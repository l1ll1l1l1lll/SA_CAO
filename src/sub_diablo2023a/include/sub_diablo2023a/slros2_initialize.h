// Copyright 2022 The MathWorks, Inc.
// Generated 18-Mar-2025 23:29:59
#ifndef _SLROS2_INITIALIZE_H_
#define _SLROS2_INITIALIZE_H_
#include "Sub_diablo2023a_types.h"
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
// Sub_diablo2023a/to connect the pp controller and turtlebot3
extern SimulinkPublisher<geometry_msgs::msg::Twist,SL_Bus_geometry_msgs_Twist> Pub_Sub_diablo2023a_1880;
// Sub_diablo2023a/to diablo
extern SimulinkPublisher<motion_msgs::msg::MotionCtrl,SL_Bus_motion_msgs_MotionCtrl> Pub_Sub_diablo2023a_1882;
// Sub_diablo2023a/LIdar scan
extern SimulinkSubscriber<sensor_msgs::msg::LaserScan,SL_Bus_sensor_msgs_LaserScan> Sub_Sub_diablo2023a_1432;
// Sub_diablo2023a/keyboard-telelop
extern SimulinkSubscriber<sensor_msgs::msg::Joy,SL_Bus_sensor_msgs_Joy> Sub_Sub_diablo2023a_1483;
// Sub_diablo2023a/vel_cmd from PP controller
extern SimulinkSubscriber<geometry_msgs::msg::Twist,SL_Bus_geometry_msgs_Twist> Sub_Sub_diablo2023a_1887;
// Sub_diablo2023a/vel_cmd from PP controller1
extern SimulinkSubscriber<tf2_msgs::msg::TFMessage,SL_Bus_tf2_msgs_TFMessage> Sub_Sub_diablo2023a_1933;
#endif
