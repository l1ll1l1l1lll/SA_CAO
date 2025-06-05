// Copyright 2022-2023 The MathWorks, Inc.
// Generated 05-Jun-2025 02:24:58
#include "slros2_initialize.h"
// SUB_DWAV18/to connect the turtlebot1
SimulinkPublisher<std_msgs::msg::Bool,SL_Bus_std_msgs_Bool> Pub_SUB_DWAV18_2774;
// SUB_DWAV18/to connect the turtlebot2
SimulinkPublisher<std_msgs::msg::Bool,SL_Bus_std_msgs_Bool> Pub_SUB_DWAV18_2845;
// SUB_DWAV18/to connect the turtlebot3
SimulinkPublisher<geometry_msgs::msg::Twist,SL_Bus_geometry_msgs_Twist> Pub_SUB_DWAV18_1880;
// SUB_DWAV18/to connect the turtlebot4
SimulinkPublisher<std_msgs::msg::Bool,SL_Bus_std_msgs_Bool> Pub_SUB_DWAV18_2864;
// SUB_DWAV18/to diablo
SimulinkPublisher<motion_msgs::msg::MotionCtrl,SL_Bus_motion_msgs_MotionCtrl> Pub_SUB_DWAV18_1882;
// SUB_DWAV18/Lidar scan
SimulinkSubscriber<sensor_msgs::msg::LaserScan,SL_Bus_sensor_msgs_LaserScan> Sub_SUB_DWAV18_1432;
// SUB_DWAV18/Ultrasonic scan1
SimulinkSubscriber<sensor_msgs::msg::Range,SL_Bus_sensor_msgs_Range> Sub_SUB_DWAV18_2634;
// SUB_DWAV18/Ultrasonic scan2
SimulinkSubscriber<sensor_msgs::msg::Range,SL_Bus_sensor_msgs_Range> Sub_SUB_DWAV18_2651;
// SUB_DWAV18/Ultrasonic scan3
SimulinkSubscriber<sensor_msgs::msg::Range,SL_Bus_sensor_msgs_Range> Sub_SUB_DWAV18_2652;
// SUB_DWAV18/controller
SimulinkSubscriber<sensor_msgs::msg::Joy,SL_Bus_sensor_msgs_Joy> Sub_SUB_DWAV18_1483;
// SUB_DWAV18/read map2
SimulinkSubscriber<std_msgs::msg::Bool,SL_Bus_std_msgs_Bool> Sub_SUB_DWAV18_2838;
// SUB_DWAV18/vel_cmd from PP controller
SimulinkSubscriber<geometry_msgs::msg::Twist,SL_Bus_geometry_msgs_Twist> Sub_SUB_DWAV18_1887;
