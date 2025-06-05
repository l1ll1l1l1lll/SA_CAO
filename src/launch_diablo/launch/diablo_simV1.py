from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, LogInfo, IncludeLaunchDescription, SetEnvironmentVariable
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
import os

def generate_launch_description():
    simtime = LaunchConfiguration('simtime', default='true')  # 统一的sim_time变量，默认true

    diablo_gazebo_pkg_path = get_package_share_directory('diablo_simulation')
    turtlebot3_cartographer_pkg_path = get_package_share_directory('turtlebot3_cartographer')

    diablo_gazebo_launch_path = os.path.join(diablo_gazebo_pkg_path, 'launch', 'gazebo.launch.py')
    cartographer_launch_path = os.path.join(turtlebot3_cartographer_pkg_path, 'launch', 'cartographerV1.launch.py')

    return LaunchDescription([
        DeclareLaunchArgument(
            'simtime',
            default_value='true',
            description='Use simulation time if true'
        ),

        LogInfo(msg="Launching Diablo simulation + SLAM + Control..."),

        SetEnvironmentVariable(
            'GAZEBO_MODEL_PATH',
            os.path.join(diablo_gazebo_pkg_path, 'urdf')
        ),

        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(diablo_gazebo_launch_path),
            launch_arguments={'use_sim_time': simtime}.items()
        ),

        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(cartographer_launch_path),
            launch_arguments={'use_sim_time': simtime}.items(),
        ),

        Node(
            package='joy',
            executable='joy_node',
            output='screen',
            parameters=[{'use_sim_time': simtime}],
        ),

        Node(
            package='pure_pursuit',
            executable='marker_relay_node',
            output='screen',
            parameters=[{'use_sim_time': simtime}],
        ),

        Node(
            package='pure_pursuit',
            executable='get_pose',
            output='screen',
            parameters=[{'use_sim_time': simtime}],
        ),

        Node(
            package='pure_pursuit',
            executable='pure_pursuit_node',
            output='screen',
            parameters=[{'use_sim_time': simtime}],
        ),
    ])
