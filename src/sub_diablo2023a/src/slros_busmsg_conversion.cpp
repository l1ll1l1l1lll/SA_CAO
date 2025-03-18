#include "slros_busmsg_conversion.h"


// Conversions between SL_Bus_builtin_interfaces_Time and builtin_interfaces::msg::Time

void convertFromBus(builtin_interfaces::msg::Time& msgPtr, SL_Bus_builtin_interfaces_Time const* busPtr)
{
  const std::string rosMessageType("builtin_interfaces/Time");

  msgPtr.nanosec =  busPtr->nanosec;
  msgPtr.sec =  busPtr->sec;
}

void convertToBus(SL_Bus_builtin_interfaces_Time* busPtr, const builtin_interfaces::msg::Time& msgPtr)
{
  const std::string rosMessageType("builtin_interfaces/Time");

  busPtr->nanosec =  msgPtr.nanosec;
  busPtr->sec =  msgPtr.sec;
}


// Conversions between SL_Bus_geometry_msgs_Quaternion and geometry_msgs::msg::Quaternion

void convertFromBus(geometry_msgs::msg::Quaternion& msgPtr, SL_Bus_geometry_msgs_Quaternion const* busPtr)
{
  const std::string rosMessageType("geometry_msgs/Quaternion");

  msgPtr.w =  busPtr->w;
  msgPtr.x =  busPtr->x;
  msgPtr.y =  busPtr->y;
  msgPtr.z =  busPtr->z;
}

void convertToBus(SL_Bus_geometry_msgs_Quaternion* busPtr, const geometry_msgs::msg::Quaternion& msgPtr)
{
  const std::string rosMessageType("geometry_msgs/Quaternion");

  busPtr->w =  msgPtr.w;
  busPtr->x =  msgPtr.x;
  busPtr->y =  msgPtr.y;
  busPtr->z =  msgPtr.z;
}


// Conversions between SL_Bus_geometry_msgs_Transform and geometry_msgs::msg::Transform

void convertFromBus(geometry_msgs::msg::Transform& msgPtr, SL_Bus_geometry_msgs_Transform const* busPtr)
{
  const std::string rosMessageType("geometry_msgs/Transform");

  convertFromBus(msgPtr.rotation, &busPtr->rotation);
  convertFromBus(msgPtr.translation, &busPtr->translation);
}

void convertToBus(SL_Bus_geometry_msgs_Transform* busPtr, const geometry_msgs::msg::Transform& msgPtr)
{
  const std::string rosMessageType("geometry_msgs/Transform");

  convertToBus(&busPtr->rotation, msgPtr.rotation);
  convertToBus(&busPtr->translation, msgPtr.translation);
}


// Conversions between SL_Bus_geometry_msgs_TransformStamped and geometry_msgs::msg::TransformStamped

void convertFromBus(geometry_msgs::msg::TransformStamped& msgPtr, SL_Bus_geometry_msgs_TransformStamped const* busPtr)
{
  const std::string rosMessageType("geometry_msgs/TransformStamped");

  convertFromBusVariablePrimitiveArray(msgPtr.child_frame_id, busPtr->child_frame_id, busPtr->child_frame_id_SL_Info);
  convertFromBus(msgPtr.header, &busPtr->header);
  convertFromBus(msgPtr.transform, &busPtr->transform);
}

void convertToBus(SL_Bus_geometry_msgs_TransformStamped* busPtr, const geometry_msgs::msg::TransformStamped& msgPtr)
{
  const std::string rosMessageType("geometry_msgs/TransformStamped");

  convertToBusVariablePrimitiveArray(busPtr->child_frame_id, busPtr->child_frame_id_SL_Info, msgPtr.child_frame_id, slros::EnabledWarning(rosMessageType, "child_frame_id"));
  convertToBus(&busPtr->header, msgPtr.header);
  convertToBus(&busPtr->transform, msgPtr.transform);
}


// Conversions between SL_Bus_geometry_msgs_Twist and geometry_msgs::msg::Twist

void convertFromBus(geometry_msgs::msg::Twist& msgPtr, SL_Bus_geometry_msgs_Twist const* busPtr)
{
  const std::string rosMessageType("geometry_msgs/Twist");

  convertFromBus(msgPtr.angular, &busPtr->angular);
  convertFromBus(msgPtr.linear, &busPtr->linear);
}

void convertToBus(SL_Bus_geometry_msgs_Twist* busPtr, const geometry_msgs::msg::Twist& msgPtr)
{
  const std::string rosMessageType("geometry_msgs/Twist");

  convertToBus(&busPtr->angular, msgPtr.angular);
  convertToBus(&busPtr->linear, msgPtr.linear);
}


// Conversions between SL_Bus_geometry_msgs_Vector3 and geometry_msgs::msg::Vector3

void convertFromBus(geometry_msgs::msg::Vector3& msgPtr, SL_Bus_geometry_msgs_Vector3 const* busPtr)
{
  const std::string rosMessageType("geometry_msgs/Vector3");

  msgPtr.x =  busPtr->x;
  msgPtr.y =  busPtr->y;
  msgPtr.z =  busPtr->z;
}

void convertToBus(SL_Bus_geometry_msgs_Vector3* busPtr, const geometry_msgs::msg::Vector3& msgPtr)
{
  const std::string rosMessageType("geometry_msgs/Vector3");

  busPtr->x =  msgPtr.x;
  busPtr->y =  msgPtr.y;
  busPtr->z =  msgPtr.z;
}


// Conversions between SL_Bus_motion_msgs_MotionCtrl and motion_msgs::msg::MotionCtrl

void convertFromBus(motion_msgs::msg::MotionCtrl& msgPtr, SL_Bus_motion_msgs_MotionCtrl const* busPtr)
{
  const std::string rosMessageType("motion_msgs/MotionCtrl");

  convertFromBus(msgPtr.mode, &busPtr->mode);
  msgPtr.mode_mark =  busPtr->mode_mark;
  convertFromBus(msgPtr.value, &busPtr->value);
}

void convertToBus(SL_Bus_motion_msgs_MotionCtrl* busPtr, const motion_msgs::msg::MotionCtrl& msgPtr)
{
  const std::string rosMessageType("motion_msgs/MotionCtrl");

  convertToBus(&busPtr->mode, msgPtr.mode);
  busPtr->mode_mark =  msgPtr.mode_mark;
  convertToBus(&busPtr->value, msgPtr.value);
}


// Conversions between SL_Bus_motion_msgs_MovementCtrlData and motion_msgs::msg::MovementCtrlData

void convertFromBus(motion_msgs::msg::MovementCtrlData& msgPtr, SL_Bus_motion_msgs_MovementCtrlData const* busPtr)
{
  const std::string rosMessageType("motion_msgs/MovementCtrlData");

  msgPtr.forward =  busPtr->forward;
  msgPtr.left =  busPtr->left;
  msgPtr.leg_split =  busPtr->leg_split;
  msgPtr.pitch =  busPtr->pitch;
  msgPtr.roll =  busPtr->roll;
  msgPtr.up =  busPtr->up;
}

void convertToBus(SL_Bus_motion_msgs_MovementCtrlData* busPtr, const motion_msgs::msg::MovementCtrlData& msgPtr)
{
  const std::string rosMessageType("motion_msgs/MovementCtrlData");

  busPtr->forward =  msgPtr.forward;
  busPtr->left =  msgPtr.left;
  busPtr->leg_split =  msgPtr.leg_split;
  busPtr->pitch =  msgPtr.pitch;
  busPtr->roll =  msgPtr.roll;
  busPtr->up =  msgPtr.up;
}


// Conversions between SL_Bus_motion_msgs_MovementCtrlMode and motion_msgs::msg::MovementCtrlMode

void convertFromBus(motion_msgs::msg::MovementCtrlMode& msgPtr, SL_Bus_motion_msgs_MovementCtrlMode const* busPtr)
{
  const std::string rosMessageType("motion_msgs/MovementCtrlMode");

  msgPtr.height_ctrl_mode =  busPtr->height_ctrl_mode;
  msgPtr.jump_mode =  busPtr->jump_mode;
  msgPtr.pitch_ctrl_mode =  busPtr->pitch_ctrl_mode;
  msgPtr.roll_ctrl_mode =  busPtr->roll_ctrl_mode;
  msgPtr.split_mode =  busPtr->split_mode;
  msgPtr.stand_mode =  busPtr->stand_mode;
}

void convertToBus(SL_Bus_motion_msgs_MovementCtrlMode* busPtr, const motion_msgs::msg::MovementCtrlMode& msgPtr)
{
  const std::string rosMessageType("motion_msgs/MovementCtrlMode");

  busPtr->height_ctrl_mode =  msgPtr.height_ctrl_mode;
  busPtr->jump_mode =  msgPtr.jump_mode;
  busPtr->pitch_ctrl_mode =  msgPtr.pitch_ctrl_mode;
  busPtr->roll_ctrl_mode =  msgPtr.roll_ctrl_mode;
  busPtr->split_mode =  msgPtr.split_mode;
  busPtr->stand_mode =  msgPtr.stand_mode;
}


// Conversions between SL_Bus_sensor_msgs_Joy and sensor_msgs::msg::Joy

void convertFromBus(sensor_msgs::msg::Joy& msgPtr, SL_Bus_sensor_msgs_Joy const* busPtr)
{
  const std::string rosMessageType("sensor_msgs/Joy");

  convertFromBusVariablePrimitiveArray(msgPtr.axes, busPtr->axes, busPtr->axes_SL_Info);
  convertFromBusVariablePrimitiveArray(msgPtr.buttons, busPtr->buttons, busPtr->buttons_SL_Info);
  convertFromBus(msgPtr.header, &busPtr->header);
}

void convertToBus(SL_Bus_sensor_msgs_Joy* busPtr, const sensor_msgs::msg::Joy& msgPtr)
{
  const std::string rosMessageType("sensor_msgs/Joy");

  convertToBusVariablePrimitiveArray(busPtr->axes, busPtr->axes_SL_Info, msgPtr.axes, slros::EnabledWarning(rosMessageType, "axes"));
  convertToBusVariablePrimitiveArray(busPtr->buttons, busPtr->buttons_SL_Info, msgPtr.buttons, slros::EnabledWarning(rosMessageType, "buttons"));
  convertToBus(&busPtr->header, msgPtr.header);
}


// Conversions between SL_Bus_sensor_msgs_LaserScan and sensor_msgs::msg::LaserScan

void convertFromBus(sensor_msgs::msg::LaserScan& msgPtr, SL_Bus_sensor_msgs_LaserScan const* busPtr)
{
  const std::string rosMessageType("sensor_msgs/LaserScan");

  msgPtr.angle_increment =  busPtr->angle_increment;
  msgPtr.angle_max =  busPtr->angle_max;
  msgPtr.angle_min =  busPtr->angle_min;
  convertFromBus(msgPtr.header, &busPtr->header);
  convertFromBusVariablePrimitiveArray(msgPtr.intensities, busPtr->intensities, busPtr->intensities_SL_Info);
  msgPtr.range_max =  busPtr->range_max;
  msgPtr.range_min =  busPtr->range_min;
  convertFromBusVariablePrimitiveArray(msgPtr.ranges, busPtr->ranges, busPtr->ranges_SL_Info);
  msgPtr.scan_time =  busPtr->scan_time;
  msgPtr.time_increment =  busPtr->time_increment;
}

void convertToBus(SL_Bus_sensor_msgs_LaserScan* busPtr, const sensor_msgs::msg::LaserScan& msgPtr)
{
  const std::string rosMessageType("sensor_msgs/LaserScan");

  busPtr->angle_increment =  msgPtr.angle_increment;
  busPtr->angle_max =  msgPtr.angle_max;
  busPtr->angle_min =  msgPtr.angle_min;
  convertToBus(&busPtr->header, msgPtr.header);
  convertToBusVariablePrimitiveArray(busPtr->intensities, busPtr->intensities_SL_Info, msgPtr.intensities, slros::EnabledWarning(rosMessageType, "intensities"));
  busPtr->range_max =  msgPtr.range_max;
  busPtr->range_min =  msgPtr.range_min;
  convertToBusVariablePrimitiveArray(busPtr->ranges, busPtr->ranges_SL_Info, msgPtr.ranges, slros::EnabledWarning(rosMessageType, "ranges"));
  busPtr->scan_time =  msgPtr.scan_time;
  busPtr->time_increment =  msgPtr.time_increment;
}


// Conversions between SL_Bus_std_msgs_Header and std_msgs::msg::Header

void convertFromBus(std_msgs::msg::Header& msgPtr, SL_Bus_std_msgs_Header const* busPtr)
{
  const std::string rosMessageType("std_msgs/Header");

  convertFromBusVariablePrimitiveArray(msgPtr.frame_id, busPtr->frame_id, busPtr->frame_id_SL_Info);
  convertFromBus(msgPtr.stamp, &busPtr->stamp);
}

void convertToBus(SL_Bus_std_msgs_Header* busPtr, const std_msgs::msg::Header& msgPtr)
{
  const std::string rosMessageType("std_msgs/Header");

  convertToBusVariablePrimitiveArray(busPtr->frame_id, busPtr->frame_id_SL_Info, msgPtr.frame_id, slros::EnabledWarning(rosMessageType, "frame_id"));
  convertToBus(&busPtr->stamp, msgPtr.stamp);
}


// Conversions between SL_Bus_tf2_msgs_TFMessage and tf2_msgs::msg::TFMessage

void convertFromBus(tf2_msgs::msg::TFMessage& msgPtr, SL_Bus_tf2_msgs_TFMessage const* busPtr)
{
  const std::string rosMessageType("tf2_msgs/TFMessage");

  convertFromBusVariableNestedArray(msgPtr.transforms, busPtr->transforms, busPtr->transforms_SL_Info);
}

void convertToBus(SL_Bus_tf2_msgs_TFMessage* busPtr, const tf2_msgs::msg::TFMessage& msgPtr)
{
  const std::string rosMessageType("tf2_msgs/TFMessage");

  convertToBusVariableNestedArray(busPtr->transforms, busPtr->transforms_SL_Info, msgPtr.transforms, slros::EnabledWarning(rosMessageType, "transforms"));
}

