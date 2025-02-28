import rclpy
from rclpy.node import Node
from motion_msgs.msg import MotionCtrl  # 导入自定义消息
from geometry_msgs.msg import Twist  # 导入Twist消息类型

def generMsgs(ctrlMsgs, forward=None, left=None, roll=None, up=None,
              pitch=None, mode_mark=False, height_ctrl_mode=None,
              pitch_ctrl_mode=None, roll_ctrl_mode=None, stand_mode=None,
              jump_mode=False, dance_mode=None):
    ctrlMsgs.mode_mark = mode_mark
    ctrlMsgs.mode.jump_mode = jump_mode

    if dance_mode is not None:
        ctrlMsgs.mode.split_mode = dance_mode
    if forward is not None:
        ctrlMsgs.value.forward = forward
    if left is not None:
        ctrlMsgs.value.left = left
    if pitch is not None:
        ctrlMsgs.value.pitch = pitch
    if roll is not None:
        ctrlMsgs.value.roll = roll
    if up is not None:
        ctrlMsgs.value.up = up
    if height_ctrl_mode is not None:
        ctrlMsgs.mode.height_ctrl_mode = height_ctrl_mode
    if pitch_ctrl_mode is not None:
        ctrlMsgs.mode.pitch_ctrl_mode = pitch_ctrl_mode
    if roll_ctrl_mode is not None:
        ctrlMsgs.mode.roll_ctrl_mode = roll_ctrl_mode
    if stand_mode is not None:
        ctrlMsgs.mode.stand_mode = stand_mode


class cmd_vel2motionctrl(Node):
    def __init__(self):
        super().__init__('my_node')
        
        # 创建一个订阅者，订阅Twist消息
        self.subscription = self.create_subscription(
            Twist,  # 消息类型
            '/vw_vel',  # 订阅的Topic名称
            self.listener_callback,  # 回调函数
            10  # 队列长度
        )
        
        # 创建一个发布者，发布自定义消息
        self.publisher = self.create_publisher(
            MotionCtrl,  # 自定义消息类型
            'diablo/MotionCmd',  # 发布的Topic名称
            2  # 队列长度
        )

    def listener_callback(self, msg):
        # 处理接收到的消息
        self.get_logger().info(f'Received: {msg}')
        
        # 创建一个新的消息
        ctrlMsgs = MotionCtrl()
        generMsgs( forward=msg.linear.x, left=msg.angular.z)  # 一次性传递所有参数
        
        # 发布新的消息
        self.publisher.publish(ctrlMsgs)
        self.get_logger().info(f'Published: {ctrlMsgs}')


def main(args=None):
    rclpy.init(args=args)
    node = cmd_vel2motionctrl()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()



