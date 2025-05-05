// Copyright 2022-2023 The MathWorks, Inc.
// Generated 05-May-2025 23:17:08
#include "slros2_initialize.h"
// SUB_DWA/to diablo
SimulinkPublisher<motion_msgs::msg::MotionCtrl,SL_Bus_motion_msgs_MotionCtrl> Pub_SUB_DWA_1882;
// SUB_DWA/Lidar scan
SimulinkSubscriber<sensor_msgs::msg::LaserScan,SL_Bus_sensor_msgs_LaserScan> Sub_SUB_DWA_1432;
// SUB_DWA/Ultrasonic scan1
SimulinkSubscriber<sensor_msgs::msg::Range,SL_Bus_sensor_msgs_Range> Sub_SUB_DWA_2634;
// SUB_DWA/Ultrasonic scan2
SimulinkSubscriber<sensor_msgs::msg::Range,SL_Bus_sensor_msgs_Range> Sub_SUB_DWA_2651;
// SUB_DWA/Ultrasonic scan3
SimulinkSubscriber<sensor_msgs::msg::Range,SL_Bus_sensor_msgs_Range> Sub_SUB_DWA_2652;
// SUB_DWA/controller
SimulinkSubscriber<sensor_msgs::msg::Joy,SL_Bus_sensor_msgs_Joy> Sub_SUB_DWA_1483;
// SUB_DWA/vel_cmd from PP controller
SimulinkSubscriber<geometry_msgs::msg::Twist,SL_Bus_geometry_msgs_Twist> Sub_SUB_DWA_1887;
