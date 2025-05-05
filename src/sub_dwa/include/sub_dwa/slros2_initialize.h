// Copyright 2022-2023 The MathWorks, Inc.
// Generated 05-May-2025 23:17:08
#ifndef _SLROS2_INITIALIZE_H_
#define _SLROS2_INITIALIZE_H_
#include "SUB_DWA_types.h"
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
// SUB_DWA/to diablo
extern SimulinkPublisher<motion_msgs::msg::MotionCtrl,SL_Bus_motion_msgs_MotionCtrl> Pub_SUB_DWA_1882;
// SUB_DWA/Lidar scan
extern SimulinkSubscriber<sensor_msgs::msg::LaserScan,SL_Bus_sensor_msgs_LaserScan> Sub_SUB_DWA_1432;
// SUB_DWA/Ultrasonic scan1
extern SimulinkSubscriber<sensor_msgs::msg::Range,SL_Bus_sensor_msgs_Range> Sub_SUB_DWA_2634;
// SUB_DWA/Ultrasonic scan2
extern SimulinkSubscriber<sensor_msgs::msg::Range,SL_Bus_sensor_msgs_Range> Sub_SUB_DWA_2651;
// SUB_DWA/Ultrasonic scan3
extern SimulinkSubscriber<sensor_msgs::msg::Range,SL_Bus_sensor_msgs_Range> Sub_SUB_DWA_2652;
// SUB_DWA/controller
extern SimulinkSubscriber<sensor_msgs::msg::Joy,SL_Bus_sensor_msgs_Joy> Sub_SUB_DWA_1483;
// SUB_DWA/vel_cmd from PP controller
extern SimulinkSubscriber<geometry_msgs::msg::Twist,SL_Bus_geometry_msgs_Twist> Sub_SUB_DWA_1887;
#endif
