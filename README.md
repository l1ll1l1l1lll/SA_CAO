# **ROS2 Packages for Diablo Robot (SA)**  

This repository contains ROS 2 packages for controlling the **Diablo Robot**, integrating sensor inputs (LiDAR, ultrasonic) and joystick control.  

---

# **Launch All support Packages**  
To start all nodes simultaneously, run:  
```bash
ros2 launch launch_diablo launch_diablo.py
```

## **If you need to debug individual nodes:**
### 1. LiDAR 
launch the LiDAR --/scan
```bash
ros2 launch rplidar_ros rplidar_c1_launch.py  
```
### 2. Diablo Control 
```bash
ros2 run diablo_ctrl diablo_ctrl_node  
```
### 3. Joystick  
this node reads the command from joystick -- /joy
```bash
ros2 run joy joy_node  
```
### 4. Ultrasonic Sensors  
this node reads the feedbacks from 3 ultrasonic sensors -- /ultrasonic/front; /ultrasonic/left; /ultrasonic/right
```bash
ros2 run ultrasound_package ultrasonic_range_publisher  
```
