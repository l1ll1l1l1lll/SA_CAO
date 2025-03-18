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

    # 定义 turtlebot3_world.launch.py 的路径
    turtlebot3_world_launch_path = os.path.join(
        turtlebot3_gazebo_pkg_path, 'launch', 'turtlebot3_world.launch.py'
    )

    # 通过 SetEnvironmentVariable 设置环境变量
    return LaunchDescription([
        LogInfo(condition=None, msg="Launching multiple nodes..."),
        # Set environment variables
        SetEnvironmentVariable('TURTLEBOT3_MODEL', 'burger'),
        SetEnvironmentVariable('GAZEBO_MODEL_PATH', os.path.join(turtlebot3_gazebo_pkg_path, 'share', 'turtlebot3_gazebo', 'models')),
        
        # Launch Gazebo world
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(turtlebot3_world_launch_path)
        ),
        
	
        # Launch joy node for joystick input
        Node(
            package='joy',
            executable='joy_node',
            output='screen'
        ),

        # Launch Xbox joystick node
        Node(
            package='my_joystick',
            executable='my_joystick',
            output='screen'
        ),
        
        

       
        
        
    ])

