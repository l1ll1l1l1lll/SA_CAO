import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Point, Pose, Twist
from std_msgs.msg import Bool
import math
import os


class PurePursuitNode(Node):
    def __init__(self):
        super().__init__('pure_pursuit_node')

        # 订阅器
        self.sub_point = self.create_subscription(Point, '/traj_point', self.traj_point_callback, 10)
        self.sub_pose = self.create_subscription(Pose, '/pose', self.pose_callback, 10)
        self.sub_record = self.create_subscription(Bool, '/is_recording', self.record_callback, 10)
        self.sub_repeat = self.create_subscription(Bool, '/is_repeating', self.repeat_callback, 10)

        # 发布器
        self.pub_vel = self.create_publisher(Twist, '/pp_vel', 10)
        self.pub_rep_done = self.create_publisher(Bool, '/repeating_done', 10)

        # 变量
        self.traj = []
        self.pose = None
        self.is_recording = False
        self.is_repeating = False
        self.should_stop = False
        self.traj_file = os.path.expanduser('~/Desktop/trajectory.txt')

        # 控制参数
        self.pure_pursuit_enabled = False
        self.lookahead_dist = 0.1
        self.base_speed = 0.1
        self.gain_w = 2.0
        self.stop_radius = 0.05
        self.stop_ratio = 0.7
        self.start_thresh = 0.15
        self.min_traj_points = 5  # 最小有效轨迹点数

        # 定时器
        self.timer = self.create_timer(0.05, self.control_loop)

        # 初始化
        self.pub_rep_done.publish(Bool(data=False))
        self.get_logger().info("Pure Pursuit节点已初始化")

    def traj_point_callback(self, msg):
        if not self.is_recording:
            return

        x, y = msg.x, msg.y

        # 忽略无效点 (0,0)
        if math.isclose(x, 0.0, abs_tol=1e-4) and math.isclose(y, 0.0, abs_tol=1e-4):
            return

        # 过滤过于接近的点，避免重复存储
        if len(self.traj) > 0:
            last_x, last_y = self.traj[-1]
            dist = math.hypot(x - last_x, y - last_y)
            if dist < 0.01:  # 小于1cm的点不存
                return

        self.traj.append((x, y))

    def pose_callback(self, msg):
        self.pose = msg

    def record_callback(self, msg):
        if msg.data and not self.is_recording:
            # 开始录制
            self.traj = []
            self.is_recording = True
            self.get_logger().info("开始录制轨迹...")

        elif not msg.data and self.is_recording:
            # 停止录制
            self.is_recording = False

            # 保存轨迹
            if self.save_trajectory():
                self.get_logger().info(f"轨迹保存成功，共{len(self.traj)}个点")
            else:
                self.get_logger().error("轨迹保存失败")

    def repeat_callback(self, msg):
        if msg.data and not self.is_repeating:
            # 开始重复
            if self.load_trajectory():
                self.is_repeating = True
                self.pure_pursuit_enabled = False
                self.should_stop = False
                self.get_logger().info(f"开始重复轨迹，共{len(self.traj)}个点")
            else:
                self.get_logger().error("无法加载轨迹文件")

        elif not msg.data and self.is_repeating:
            # 停止重复
            self.should_stop = True
            self.get_logger().info("收到停止重复指令")

    def save_trajectory(self):
        if not self.traj:
            self.get_logger().warn("没有轨迹点可保存")
            return False

        try:
            temp_file = self.traj_file + ".tmp"
            with open(temp_file, 'w') as f:
                for x, y in self.traj:
                    # 只保留4位小数，减小文件大小并保证精度
                    f.write(f"{x:.4f},{y:.4f}\n")

            os.sync()
            os.replace(temp_file, self.traj_file)

            if os.path.exists(self.traj_file) and os.path.getsize(self.traj_file) > 0:
                return True

            self.get_logger().error("文件验证失败")
            return False

        except Exception as e:
            self.get_logger().error(f"保存轨迹出错: {str(e)}")
            if os.path.exists(temp_file):
                os.remove(temp_file)
            return False

    def load_trajectory(self):
        self.traj = []
        if not os.path.exists(self.traj_file):
            self.get_logger().error(f"轨迹文件不存在: {self.traj_file}")
            return False

        try:
            with open(self.traj_file, 'r') as f:
                for line in f:
                    try:
                        x, y = map(float, line.strip().split(','))
                        self.traj.append((x, y))
                    except ValueError:
                        continue

            if len(self.traj) < self.min_traj_points:
                self.get_logger().error(f"轨迹点不足，至少需要{self.min_traj_points}个点")
                return False

            return True

        except Exception as e:
            self.get_logger().error(f"加载轨迹出错: {str(e)}")
            return False

    def get_yaw(self):
        if self.pose is None:
            return 0.0
        o = self.pose.orientation
        # 四元数转换yaw，假设z轴旋转
        siny_cosp = 2.0 * (o.w * o.z + o.x * o.y)
        cosy_cosp = 1.0 - 2.0 * (o.y * o.y + o.z * o.z)
        return math.atan2(siny_cosp, cosy_cosp)

    def control_loop(self):
        if self.should_stop:
            self.stop_repeating()
            return

        if not self.is_repeating or self.pose is None:
            return

        if len(self.traj) < self.min_traj_points:
            self.get_logger().error("轨迹点不足，停止重复")
            self.stop_repeating()
            return

        x = self.pose.position.x
        y = self.pose.position.y
        yaw = self.get_yaw()

        # 导航到起点
        if not self.pure_pursuit_enabled:
            start_x, start_y = self.traj[0]
            dist_to_start = math.hypot(x - start_x, y - start_y)

            if dist_to_start <= self.start_thresh:
                self.pure_pursuit_enabled = True
                self.get_logger().info("到达起点，开始追踪轨迹")
            else:
                dx = start_x - x
                dy = start_y - y
                goal_angle = math.atan2(dy, dx)
                yaw_err = math.atan2(math.sin(goal_angle - yaw), math.cos(goal_angle - yaw))

                v = self.base_speed + 0.3 * math.tanh(1.5 * dist_to_start)
                w = self.gain_w * yaw_err
                w = max(min(w, 1.0 / 0.6), -1.0 / 0.6)

                self.publish_velocity(v, w)
                return

        # 纯追踪控制阶段
        closest_idx = min(range(len(self.traj)),
                          key=lambda i: math.hypot(x - self.traj[i][0], y - self.traj[i][1]))

        goal_x, goal_y = self.traj[-1]
        for i in range(closest_idx, len(self.traj)):
            dx = self.traj[i][0] - x
            dy = self.traj[i][1] - y
            if math.hypot(dx, dy) >= self.lookahead_dist:
                goal_x, goal_y = self.traj[i]
                break

        dx = goal_x - x
        dy = goal_y - y
        goal_angle = math.atan2(dy, dx)
        yaw_error = math.atan2(math.sin(goal_angle - yaw), math.cos(goal_angle - yaw))
        dist = math.hypot(dx, dy)

        v = self.base_speed + 0.2 * math.tanh(1.5 * dist)
        w = self.gain_w * yaw_error

        if closest_idx > int(self.stop_ratio * len(self.traj)) and \
                math.hypot(self.traj[-1][0] - x, self.traj[-1][1] - y) < self.stop_radius:
            self.get_logger().info("到达轨迹终点")
            self.publish_velocity(0.0, 0.0)
            self.stop_repeating()
        else:
            self.publish_velocity(v, w)

    def stop_repeating(self):
        if not self.is_repeating:
            return

        self.get_logger().info("停止重复模式")
        self.publish_velocity(0.0, 0.0)
        self.pub_rep_done.publish(Bool(data=True))
        self.is_repeating = False
        self.pure_pursuit_enabled = False
        self.should_stop = False

        # 延迟重置 repeating_done 标志
        self.create_timer(0.5, lambda: self.pub_rep_done.publish(Bool(data=False)))

    def publish_velocity(self, linear, angular):
        twist = Twist()
        twist.linear.x = float(linear)
        twist.angular.z = float(angular)
        self.pub_vel.publish(twist)


def main(args=None):
    rclpy.init(args=args)
    node = PurePursuitNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
