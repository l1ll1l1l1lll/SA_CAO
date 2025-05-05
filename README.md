ROS2 packages relevant to SA

to launch all packages
ros2 launch launch_diablo launch_diablo.py

launch file contains:
1.launch the LiDAR launch file -- /scan
2.run dialbo control node
3.run joy node, it reads the command from joystick -- /joy
4.run ultrasonic range publisher -- /ultrasonic/front /ultrasonic/left /ultrasonic/right 

# **ROS2 Packages for Diablo Robot (SA)**  

This repository contains ROS 2 packages for controlling the **Diablo Robot**, integrating sensor inputs (LiDAR, ultrasonic) and joystick control.  

---

## **Launch All Packages**  
To start all nodes simultaneously, run:  
```bash
ros2 launch launch_diablo launch_diablo.py
```

# 1. LiDAR 
/scan
```bash
ros2 launch rplidar_ros rplidar_c1_launch.py  
```
# 2. Diablo Control 
```bash
ros2 run diablo_ctrl diablo_ctrl_node  
```
# 3. Joystick  
/joy
```bash
ros2 run joy joy_node  
```
# 4. Ultrasonic Sensors  
-- /ultrasonic/front /ultrasonic/left /ultrasonic/right
```bash
ros2 run ultrasound_package ultrasonic_range_publisher  
```
