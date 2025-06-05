// Copyright 2022-2023 The MathWorks, Inc.
// Generated 05-Jun-2025 02:24:58
#ifndef _SLROS2_INITIALIZE_H_
#define _SLROS2_INITIALIZE_H_
#include "SUB_DWAV18_types.h"
// Generic pub-sub header
#include "slros2_generic_pubsub.h"
// Generic service header
#include "slros2_generic_service.h"
extern rclcpp::Node::SharedPtr SLROSNodePtr;
#ifndef SET_QOS_VALUES
#define SET_QOS_VALUES(qosStruct, hist, dep, dur, rel)  \
    {                                                   \
        qosStruct.history = hist;                       \
        qosStruct.depth = dep;                          \
        qosStruct.durability = dur;                     \
        qosStruct.reliability = rel;                    \
    }
#endif
inline rclcpp::QoS getQOSSettingsFromRMW(const rmw_qos_profile_t& qosProfile) {
    rclcpp::QoS qos(rclcpp::QoSInitialization::from_rmw(qosProfile));
    if (RMW_QOS_POLICY_DURABILITY_TRANSIENT_LOCAL == qosProfile.durability) {
        qos.transient_local();
    } else {
        qos.durability_volatile();
    }
    if (RMW_QOS_POLICY_RELIABILITY_RELIABLE == qosProfile.reliability) {
        qos.reliable();
    } else {
        qos.best_effort();
    }
    return qos;
}
// SUB_DWAV18/to connect the turtlebot1
extern SimulinkPublisher<std_msgs::msg::Bool,SL_Bus_std_msgs_Bool> Pub_SUB_DWAV18_2774;
// SUB_DWAV18/to connect the turtlebot2
extern SimulinkPublisher<std_msgs::msg::Bool,SL_Bus_std_msgs_Bool> Pub_SUB_DWAV18_2845;
// SUB_DWAV18/to connect the turtlebot3
extern SimulinkPublisher<geometry_msgs::msg::Twist,SL_Bus_geometry_msgs_Twist> Pub_SUB_DWAV18_1880;
// SUB_DWAV18/to connect the turtlebot4
extern SimulinkPublisher<std_msgs::msg::Bool,SL_Bus_std_msgs_Bool> Pub_SUB_DWAV18_2864;
// SUB_DWAV18/to diablo
extern SimulinkPublisher<motion_msgs::msg::MotionCtrl,SL_Bus_motion_msgs_MotionCtrl> Pub_SUB_DWAV18_1882;
// SUB_DWAV18/Lidar scan
extern SimulinkSubscriber<sensor_msgs::msg::LaserScan,SL_Bus_sensor_msgs_LaserScan> Sub_SUB_DWAV18_1432;
// SUB_DWAV18/Ultrasonic scan1
extern SimulinkSubscriber<sensor_msgs::msg::Range,SL_Bus_sensor_msgs_Range> Sub_SUB_DWAV18_2634;
// SUB_DWAV18/Ultrasonic scan2
extern SimulinkSubscriber<sensor_msgs::msg::Range,SL_Bus_sensor_msgs_Range> Sub_SUB_DWAV18_2651;
// SUB_DWAV18/Ultrasonic scan3
extern SimulinkSubscriber<sensor_msgs::msg::Range,SL_Bus_sensor_msgs_Range> Sub_SUB_DWAV18_2652;
// SUB_DWAV18/controller
extern SimulinkSubscriber<sensor_msgs::msg::Joy,SL_Bus_sensor_msgs_Joy> Sub_SUB_DWAV18_1483;
// SUB_DWAV18/read map2
extern SimulinkSubscriber<std_msgs::msg::Bool,SL_Bus_std_msgs_Bool> Sub_SUB_DWAV18_2838;
// SUB_DWAV18/vel_cmd from PP controller
extern SimulinkSubscriber<geometry_msgs::msg::Twist,SL_Bus_geometry_msgs_Twist> Sub_SUB_DWAV18_1887;
#endif
