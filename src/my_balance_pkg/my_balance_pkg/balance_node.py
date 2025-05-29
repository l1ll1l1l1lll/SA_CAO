import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from sensor_msgs.msg import Imu
import math

class SelfBalanceController(Node):
    def __init__(self):
        super().__init__('self_balance_controller')

        self.kp = self.declare_parameter('kp', 0.0).get_parameter_value().double_value
        self.kd = self.declare_parameter('kd', 0).get_parameter_value().double_value
        self.ki = self.declare_parameter('ki', 0.0).get_parameter_value().double_value

        self.latest_pitch = 0.0
        self.latest_pitch_rate = 0.0
        self.integral = 0.0
        self.last_time = self.get_clock().now()

        self.cmd_sub = self.create_subscription(
            Twist,
            '/cmd_vel_raw',
            self.cmd_callback,
            10
        )

        self.imu_sub = self.create_subscription(
            Imu,
            '/imu',
            self.imu_callback,
            10
        )

        self.cmd_pub = self.create_publisher(
            Twist,
            '/cmd_vel',
            10
        )

    def imu_callback(self, msg):
        q = msg.orientation
        _, pitch, _ = self.euler_from_quaternion(q.x, q.y, q.z, q.w)
        self.latest_pitch = pitch
        self.latest_pitch_rate = msg.angular_velocity.y

    def cmd_callback(self, msg):
        current_time = self.get_clock().now()
        dt = (current_time - self.last_time).nanoseconds / 1e9
        self.last_time = current_time

        self.integral += self.latest_pitch * dt
        # 可选：限制积分项避免超调
        self.integral = max(min(self.integral, 0.5), -0.5)

        correction = -self.kp * self.latest_pitch - self.kd * self.latest_pitch_rate - self.ki * self.integral

        max_lin = 1  # 最大线速度（限制控制器输出）
        max_ang = 1.67  # 最大角速度（防止转弯过猛）

        new_cmd = Twist()
        new_cmd.linear.x = max(min(msg.linear.x + correction, max_lin), -max_lin)
        new_cmd.angular.z = max(min(msg.angular.z, max_ang), -max_ang)

        self.cmd_pub.publish(new_cmd)

    @staticmethod
    def euler_from_quaternion(x, y, z, w):
        t0 = +2.0 * (w * x + y * z)
        t1 = +1.0 - 2.0 * (x * x + y * y)
        roll = math.atan2(t0, t1)

        t2 = +2.0 * (w * y - z * x)
        t2 = max(min(t2, 1.0), -1.0)
        pitch = math.asin(t2)

        t3 = +2.0 * (w * z + x * y)
        t4 = +1.0 - 2.0 * (y * y + z * z)
        yaw = math.atan2(t3, t4)

        return roll, pitch, yaw

def main(args=None):
    rclpy.init(args=args)
    node = SelfBalanceController()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
