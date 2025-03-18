#ifndef _SLROS_BUSMSG_CONVERSION_H_
#define _SLROS_BUSMSG_CONVERSION_H_

#include "rclcpp/rclcpp.hpp"
#include <builtin_interfaces/msg/time.hpp>
#include <geometry_msgs/msg/quaternion.hpp>
#include <geometry_msgs/msg/transform.hpp>
#include <geometry_msgs/msg/transform_stamped.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <geometry_msgs/msg/vector3.hpp>
#include <motion_msgs/msg/motion_ctrl.hpp>
#include <motion_msgs/msg/movement_ctrl_data.hpp>
#include <motion_msgs/msg/movement_ctrl_mode.hpp>
#include <sensor_msgs/msg/joy.hpp>
#include <sensor_msgs/msg/laser_scan.hpp>
#include <std_msgs/msg/header.hpp>
#include <tf2_msgs/msg/tf_message.hpp>
#include "Sub_diablo2023a_types.h"
#include "slros_msgconvert_utils.h"


void convertFromBus(builtin_interfaces::msg::Time& msgPtr, SL_Bus_builtin_interfaces_Time const* busPtr);
void convertToBus(SL_Bus_builtin_interfaces_Time* busPtr, const builtin_interfaces::msg::Time& msgPtr);

void convertFromBus(geometry_msgs::msg::Quaternion& msgPtr, SL_Bus_geometry_msgs_Quaternion const* busPtr);
void convertToBus(SL_Bus_geometry_msgs_Quaternion* busPtr, const geometry_msgs::msg::Quaternion& msgPtr);

void convertFromBus(geometry_msgs::msg::Transform& msgPtr, SL_Bus_geometry_msgs_Transform const* busPtr);
void convertToBus(SL_Bus_geometry_msgs_Transform* busPtr, const geometry_msgs::msg::Transform& msgPtr);

void convertFromBus(geometry_msgs::msg::TransformStamped& msgPtr, SL_Bus_geometry_msgs_TransformStamped const* busPtr);
void convertToBus(SL_Bus_geometry_msgs_TransformStamped* busPtr, const geometry_msgs::msg::TransformStamped& msgPtr);

void convertFromBus(geometry_msgs::msg::Twist& msgPtr, SL_Bus_geometry_msgs_Twist const* busPtr);
void convertToBus(SL_Bus_geometry_msgs_Twist* busPtr, const geometry_msgs::msg::Twist& msgPtr);

void convertFromBus(geometry_msgs::msg::Vector3& msgPtr, SL_Bus_geometry_msgs_Vector3 const* busPtr);
void convertToBus(SL_Bus_geometry_msgs_Vector3* busPtr, const geometry_msgs::msg::Vector3& msgPtr);

void convertFromBus(motion_msgs::msg::MotionCtrl& msgPtr, SL_Bus_motion_msgs_MotionCtrl const* busPtr);
void convertToBus(SL_Bus_motion_msgs_MotionCtrl* busPtr, const motion_msgs::msg::MotionCtrl& msgPtr);

void convertFromBus(motion_msgs::msg::MovementCtrlData& msgPtr, SL_Bus_motion_msgs_MovementCtrlData const* busPtr);
void convertToBus(SL_Bus_motion_msgs_MovementCtrlData* busPtr, const motion_msgs::msg::MovementCtrlData& msgPtr);

void convertFromBus(motion_msgs::msg::MovementCtrlMode& msgPtr, SL_Bus_motion_msgs_MovementCtrlMode const* busPtr);
void convertToBus(SL_Bus_motion_msgs_MovementCtrlMode* busPtr, const motion_msgs::msg::MovementCtrlMode& msgPtr);

void convertFromBus(sensor_msgs::msg::Joy& msgPtr, SL_Bus_sensor_msgs_Joy const* busPtr);
void convertToBus(SL_Bus_sensor_msgs_Joy* busPtr, const sensor_msgs::msg::Joy& msgPtr);

void convertFromBus(sensor_msgs::msg::LaserScan& msgPtr, SL_Bus_sensor_msgs_LaserScan const* busPtr);
void convertToBus(SL_Bus_sensor_msgs_LaserScan* busPtr, const sensor_msgs::msg::LaserScan& msgPtr);

void convertFromBus(std_msgs::msg::Header& msgPtr, SL_Bus_std_msgs_Header const* busPtr);
void convertToBus(SL_Bus_std_msgs_Header* busPtr, const std_msgs::msg::Header& msgPtr);

void convertFromBus(tf2_msgs::msg::TFMessage& msgPtr, SL_Bus_tf2_msgs_TFMessage const* busPtr);
void convertToBus(SL_Bus_tf2_msgs_TFMessage* busPtr, const tf2_msgs::msg::TFMessage& msgPtr);


#endif
