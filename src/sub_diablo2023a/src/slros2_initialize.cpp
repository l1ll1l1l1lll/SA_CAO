// Copyright 2022 The MathWorks, Inc.
// Generated 18-Mar-2025 23:29:59
#include "slros2_initialize.h"
// Sub_diablo2023a/to connect the pp controller and turtlebot3
SimulinkPublisher<geometry_msgs::msg::Twist,SL_Bus_geometry_msgs_Twist> Pub_Sub_diablo2023a_1880;
// Sub_diablo2023a/to diablo
SimulinkPublisher<motion_msgs::msg::MotionCtrl,SL_Bus_motion_msgs_MotionCtrl> Pub_Sub_diablo2023a_1882;
// Sub_diablo2023a/LIdar scan
SimulinkSubscriber<sensor_msgs::msg::LaserScan,SL_Bus_sensor_msgs_LaserScan> Sub_Sub_diablo2023a_1432;
// Sub_diablo2023a/keyboard-telelop
SimulinkSubscriber<sensor_msgs::msg::Joy,SL_Bus_sensor_msgs_Joy> Sub_Sub_diablo2023a_1483;
// Sub_diablo2023a/vel_cmd from PP controller
SimulinkSubscriber<geometry_msgs::msg::Twist,SL_Bus_geometry_msgs_Twist> Sub_Sub_diablo2023a_1887;
// Sub_diablo2023a/vel_cmd from PP controller1
SimulinkSubscriber<tf2_msgs::msg::TFMessage,SL_Bus_tf2_msgs_TFMessage> Sub_Sub_diablo2023a_1933;
