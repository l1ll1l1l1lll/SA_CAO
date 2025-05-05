ROS2 packages relevant to SA

to launch all packages
ros2 launch launch_diablo launch_diablo.py

launch file contains:
1.launch the LiDAR launch file -- /scan
2.run dialbo control node
3.run joy node, it reads the command from joystick -- /joy
4.run ultrasonic range publisher -- /ultrasonic/front /ultrasonic/left /ultrasonic/right 
