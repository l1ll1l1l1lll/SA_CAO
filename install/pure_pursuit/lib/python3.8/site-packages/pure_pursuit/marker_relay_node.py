import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile, QoSReliabilityPolicy, QoSDurabilityPolicy
from visualization_msgs.msg import MarkerArray
from geometry_msgs.msg import Point
import math


class MarkerRelayNode(Node):
    def __init__(self):
        super().__init__('marker_relay_node')

        # QoS配置（与发布者保持一致）
        self.qos_profile = QoSProfile(
            reliability=QoSReliabilityPolicy.RELIABLE,
            durability=QoSDurabilityPolicy.VOLATILE,
            depth=10
        )

        self.subscription = self.create_subscription(
            MarkerArray,
            '/trajectory_node_list',
            self.marker_callback,
            qos_profile=self.qos_profile
        )
        self.publisher = self.create_publisher(Point, '/traj_point', 10)

        # 记录上一个发布点，避免重复发布
        self.last_published_point = None

        self.get_logger().info('MarkerRelayNode started')

    def is_point_near_zero(self, point, tol=0.01):
        """判断点是否接近 (0,0,0)，tol 为容差"""
        return math.isclose(point.x, 0.0, abs_tol=tol) and \
               math.isclose(point.y, 0.0, abs_tol=tol) and \
               math.isclose(point.z, 0.0, abs_tol=tol)

    def is_point_equal(self, p1: Point, p2: Point, tol=1e-6):
        """判断两个点是否相同，容差tol"""
        if p1 is None or p2 is None:
            return False
        return math.isclose(p1.x, p2.x, abs_tol=tol) and \
               math.isclose(p1.y, p2.y, abs_tol=tol) and \
               math.isclose(p1.z, p2.z, abs_tol=tol)

    def marker_callback(self, msg: MarkerArray):
        for marker in msg.markers:
            # marker.type==4 是 LINE_STRIP 类型
            if marker.type == 4 and len(marker.points) > 0:
                last_point = marker.points[-1]

                # 过滤掉接近零点（防止无效点）
                if self.is_point_near_zero(last_point):
                    self.get_logger().debug(f"过滤掉接近零点: ({last_point.x}, {last_point.y}, {last_point.z})")
                    continue

                # 过滤掉重复点，避免无意义重复发布
                if self.is_point_equal(last_point, self.last_published_point):
                    continue

                # 发布点
                point_msg = Point()
                point_msg.x = last_point.x
                point_msg.y = last_point.y
                point_msg.z = last_point.z
                self.publisher.publish(point_msg)

                self.last_published_point = point_msg
                self.get_logger().debug(f"发布点: ({point_msg.x}, {point_msg.y}, {point_msg.z})")


def main(args=None):
    rclpy.init(args=args)
    node = MarkerRelayNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
