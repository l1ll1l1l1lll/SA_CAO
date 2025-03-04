// Copyright 2022 The MathWorks, Inc.
// Generated 04-Mar-2025 03:55:43
#include "slros2_initialize.h"
// Sub_diablo2023a/roboter cmd Publish2
SimulinkPublisher<motion_msgs::msg::MotionCtrl,SL_Bus_motion_msgs_MotionCtrl> Pub_Sub_diablo2023a_1882;
// Sub_diablo2023a/Subscribe
SimulinkSubscriber<sensor_msgs::msg::LaserScan,SL_Bus_sensor_msgs_LaserScan> Sub_Sub_diablo2023a_1432;
// Sub_diablo2023a/keyboard-telelop
SimulinkSubscriber<sensor_msgs::msg::Joy,SL_Bus_sensor_msgs_Joy> Sub_Sub_diablo2023a_1483;
// Sub_diablo2023a/vel_cmd from PP controller
SimulinkSubscriber<geometry_msgs::msg::Twist,SL_Bus_geometry_msgs_Twist> Sub_Sub_diablo2023a_1887;
