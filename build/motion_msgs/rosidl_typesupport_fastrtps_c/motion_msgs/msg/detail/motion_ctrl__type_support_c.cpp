// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from motion_msgs:msg/MotionCtrl.idl
// generated code does not contain a copyright notice
#include "motion_msgs/msg/detail/motion_ctrl__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "motion_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "motion_msgs/msg/detail/motion_ctrl__struct.h"
#include "motion_msgs/msg/detail/motion_ctrl__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "motion_msgs/msg/detail/movement_ctrl_data__functions.h"  // value
#include "motion_msgs/msg/detail/movement_ctrl_mode__functions.h"  // mode

// forward declare type support functions
size_t get_serialized_size_motion_msgs__msg__MovementCtrlData(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_motion_msgs__msg__MovementCtrlData(
  bool & full_bounded,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, motion_msgs, msg, MovementCtrlData)();
size_t get_serialized_size_motion_msgs__msg__MovementCtrlMode(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_motion_msgs__msg__MovementCtrlMode(
  bool & full_bounded,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, motion_msgs, msg, MovementCtrlMode)();


using _MotionCtrl__ros_msg_type = motion_msgs__msg__MotionCtrl;

static bool _MotionCtrl__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _MotionCtrl__ros_msg_type * ros_message = static_cast<const _MotionCtrl__ros_msg_type *>(untyped_ros_message);
  // Field name: mode_mark
  {
    cdr << (ros_message->mode_mark ? true : false);
  }

  // Field name: value
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, motion_msgs, msg, MovementCtrlData
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->value, cdr))
    {
      return false;
    }
  }

  // Field name: mode
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, motion_msgs, msg, MovementCtrlMode
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->mode, cdr))
    {
      return false;
    }
  }

  return true;
}

static bool _MotionCtrl__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _MotionCtrl__ros_msg_type * ros_message = static_cast<_MotionCtrl__ros_msg_type *>(untyped_ros_message);
  // Field name: mode_mark
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->mode_mark = tmp ? true : false;
  }

  // Field name: value
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, motion_msgs, msg, MovementCtrlData
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->value))
    {
      return false;
    }
  }

  // Field name: mode
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, motion_msgs, msg, MovementCtrlMode
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->mode))
    {
      return false;
    }
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_motion_msgs
size_t get_serialized_size_motion_msgs__msg__MotionCtrl(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _MotionCtrl__ros_msg_type * ros_message = static_cast<const _MotionCtrl__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name mode_mark
  {
    size_t item_size = sizeof(ros_message->mode_mark);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name value

  current_alignment += get_serialized_size_motion_msgs__msg__MovementCtrlData(
    &(ros_message->value), current_alignment);
  // field.name mode

  current_alignment += get_serialized_size_motion_msgs__msg__MovementCtrlMode(
    &(ros_message->mode), current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _MotionCtrl__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_motion_msgs__msg__MotionCtrl(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_motion_msgs
size_t max_serialized_size_motion_msgs__msg__MotionCtrl(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: mode_mark
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: value
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_motion_msgs__msg__MovementCtrlData(
        full_bounded, current_alignment);
    }
  }
  // member: mode
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_motion_msgs__msg__MovementCtrlMode(
        full_bounded, current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static size_t _MotionCtrl__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_motion_msgs__msg__MotionCtrl(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_MotionCtrl = {
  "motion_msgs::msg",
  "MotionCtrl",
  _MotionCtrl__cdr_serialize,
  _MotionCtrl__cdr_deserialize,
  _MotionCtrl__get_serialized_size,
  _MotionCtrl__max_serialized_size
};

static rosidl_message_type_support_t _MotionCtrl__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_MotionCtrl,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, motion_msgs, msg, MotionCtrl)() {
  return &_MotionCtrl__type_support;
}

#if defined(__cplusplus)
}
#endif
