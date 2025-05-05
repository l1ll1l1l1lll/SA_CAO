import launch
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, LogInfo, IncludeLaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
from launch.launch_description_sources import PythonLaunchDescriptionSource
import os

def generate_launch_description():
    # 获取 rplidar_ros 包的路径
    rplidar_ros_pkg_path = get_package_share_directory('rplidar_ros')

    # **修正路径**，指向 launch 目录下的具体 launch 文件
    rplidar_ros_launch_path = os.path.join(
        rplidar_ros_pkg_path, 'launch', 'rplidar_c1_launch.py'  # 确保这个文件存在
    )

    return LaunchDescription([
        LogInfo(msg="Launching multiple nodes..."),

        # **正确指定 rplidar_ros 的 launch 文件**
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(rplidar_ros_launch_path)
        ),
    
        Node(
            package='diablo_ctrl',
            executable='diablo_ctrl_node',
            output='screen',
             
        ),

        # Launch joy node for joystick input
        Node(
            package='joy',
            executable='joy_node',
            output='screen'
        ),


        Node(
            package='ultrasound_package',
            executable='ultrasonic_range_publisher',
            output='screen'
        ),

    ])



