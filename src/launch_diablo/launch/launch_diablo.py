import launch
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, LogInfo, IncludeLaunchDescription, SetEnvironmentVariable
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
from launch.launch_description_sources import PythonLaunchDescriptionSource
import os

def generate_launch_description():
    # 获取 turtlebot3_gazebo 包的路径
    turtlebot3_gazebo_pkg_path = get_package_share_directory('turtlebot3_gazebo')

    # 获取 turtlebot3_cartographer 包的路径
    turtlebot3_cartographer_pkg_path = get_package_share_directory('turtlebot3_cartographer')

    # 定义 turtlebot3_world.launch.py 的路径
    turtlebot3_world_launch_path = os.path.join(
        turtlebot3_gazebo_pkg_path, 'launch', 'turtlebot3_world.launch.py'
    )

    # 定义 cartographer.launch.py 的路径
    cartographer_launch_path = os.path.join(
        turtlebot3_cartographer_pkg_path, 'launch', 'cartographer.launch.py'
    )

    return LaunchDescription([
        LogInfo(msg="Launching multiple nodes..."),
        
        # 设置环境变量
        SetEnvironmentVariable('TURTLEBOT3_MODEL', 'burger'),
        SetEnvironmentVariable('GAZEBO_MODEL_PATH', os.path.join(turtlebot3_gazebo_pkg_path, 'share', 'turtlebot3_gazebo', 'models')),

        # 启动 Gazebo world
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(turtlebot3_world_launch_path)
        ),

        # 启动 Cartographer SLAM
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(cartographer_launch_path)
        ),

        # 启动手柄输入节点
        Node(
            package='joy',
            executable='joy_node',
            output='screen'
        ),
        
        Node(
            package='pure_pursuit',
            executable='marker_relay_node',
            output='screen'
        ),
        
        Node(
            package='pure_pursuit',
            executable='get_pose',
            output='screen'
        ),
        
        Node(
            package='pure_pursuit',
            executable='pure_pursuit_node',
            output='screen'
        ),
    ])
