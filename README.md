# **ROS2 Packages for Diablo Robot (SA of CAO)**  

This repository contains ROS 2 packages for controlling the **Diablo Robot**, integrating sensor inputs (LiDAR, ultrasonic) and joystick control.  
All packages must be depolyed on **Diablo Robot**.

---

# **Primary System Launch**  
Execute the following command to initialize all core system components:
```bash
ros2 launch launch_diablo launch_diablo.py
```
This launch sequence activates:
Sensor feedback (LiDAR/ultrasonic)
Joystick feedback 
# **Subsumption Architecture Deployment**  
After core systems are operational, execute the Subsumption Architecture Model:
```bash
ros2 run sub_dwa SUB_DWA
```
The subsumption architecture implements:
Dynamic Window Approach (DWA) for obstacle avoidance
note: the model is using PS5 controller mapping

---
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
