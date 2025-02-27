// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from motion_msgs:msg/LegMotors.idl
// generated code does not contain a copyright notice
#include "motion_msgs/msg/detail/leg_motors__rosidl_typesupport_fastrtps_cpp.hpp"
#include "motion_msgs/msg/detail/leg_motors__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
namespace std_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const std_msgs::msg::Header &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  std_msgs::msg::Header &);
size_t get_serialized_size(
  const std_msgs::msg::Header &,
  size_t current_alignment);
size_t
max_serialized_size_Header(
  bool & full_bounded,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace std_msgs


namespace motion_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_motion_msgs
cdr_serialize(
  const motion_msgs::msg::LegMotors & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.header,
    cdr);
  // Member: left_hip_enc_rev
  cdr << ros_message.left_hip_enc_rev;
  // Member: left_hip_pos
  cdr << ros_message.left_hip_pos;
  // Member: left_hip_vel
  cdr << ros_message.left_hip_vel;
  // Member: left_hip_iq
  cdr << ros_message.left_hip_iq;
  // Member: left_knee_enc_rev
  cdr << ros_message.left_knee_enc_rev;
  // Member: left_knee_pos
  cdr << ros_message.left_knee_pos;
  // Member: left_knee_vel
  cdr << ros_message.left_knee_vel;
  // Member: left_knee_iq
  cdr << ros_message.left_knee_iq;
  // Member: left_wheel_enc_rev
  cdr << ros_message.left_wheel_enc_rev;
  // Member: left_wheel_pos
  cdr << ros_message.left_wheel_pos;
  // Member: left_wheel_vel
  cdr << ros_message.left_wheel_vel;
  // Member: left_wheel_iq
  cdr << ros_message.left_wheel_iq;
  // Member: right_hip_enc_rev
  cdr << ros_message.right_hip_enc_rev;
  // Member: right_hip_pos
  cdr << ros_message.right_hip_pos;
  // Member: right_hip_vel
  cdr << ros_message.right_hip_vel;
  // Member: right_hip_iq
  cdr << ros_message.right_hip_iq;
  // Member: right_knee_enc_rev
  cdr << ros_message.right_knee_enc_rev;
  // Member: right_knee_pos
  cdr << ros_message.right_knee_pos;
  // Member: right_knee_vel
  cdr << ros_message.right_knee_vel;
  // Member: right_knee_iq
  cdr << ros_message.right_knee_iq;
  // Member: right_wheel_enc_rev
  cdr << ros_message.right_wheel_enc_rev;
  // Member: right_wheel_pos
  cdr << ros_message.right_wheel_pos;
  // Member: right_wheel_vel
  cdr << ros_message.right_wheel_vel;
  // Member: right_wheel_iq
  cdr << ros_message.right_wheel_iq;
  // Member: left_leg_length
  cdr << ros_message.left_leg_length;
  // Member: right_leg_length
  cdr << ros_message.right_leg_length;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_motion_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  motion_msgs::msg::LegMotors & ros_message)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.header);

  // Member: left_hip_enc_rev
  cdr >> ros_message.left_hip_enc_rev;

  // Member: left_hip_pos
  cdr >> ros_message.left_hip_pos;

  // Member: left_hip_vel
  cdr >> ros_message.left_hip_vel;

  // Member: left_hip_iq
  cdr >> ros_message.left_hip_iq;

  // Member: left_knee_enc_rev
  cdr >> ros_message.left_knee_enc_rev;

  // Member: left_knee_pos
  cdr >> ros_message.left_knee_pos;

  // Member: left_knee_vel
  cdr >> ros_message.left_knee_vel;

  // Member: left_knee_iq
  cdr >> ros_message.left_knee_iq;

  // Member: left_wheel_enc_rev
  cdr >> ros_message.left_wheel_enc_rev;

  // Member: left_wheel_pos
  cdr >> ros_message.left_wheel_pos;

  // Member: left_wheel_vel
  cdr >> ros_message.left_wheel_vel;

  // Member: left_wheel_iq
  cdr >> ros_message.left_wheel_iq;

  // Member: right_hip_enc_rev
  cdr >> ros_message.right_hip_enc_rev;

  // Member: right_hip_pos
  cdr >> ros_message.right_hip_pos;

  // Member: right_hip_vel
  cdr >> ros_message.right_hip_vel;

  // Member: right_hip_iq
  cdr >> ros_message.right_hip_iq;

  // Member: right_knee_enc_rev
  cdr >> ros_message.right_knee_enc_rev;

  // Member: right_knee_pos
  cdr >> ros_message.right_knee_pos;

  // Member: right_knee_vel
  cdr >> ros_message.right_knee_vel;

  // Member: right_knee_iq
  cdr >> ros_message.right_knee_iq;

  // Member: right_wheel_enc_rev
  cdr >> ros_message.right_wheel_enc_rev;

  // Member: right_wheel_pos
  cdr >> ros_message.right_wheel_pos;

  // Member: right_wheel_vel
  cdr >> ros_message.right_wheel_vel;

  // Member: right_wheel_iq
  cdr >> ros_message.right_wheel_iq;

  // Member: left_leg_length
  cdr >> ros_message.left_leg_length;

  // Member: right_leg_length
  cdr >> ros_message.right_leg_length;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_motion_msgs
get_serialized_size(
  const motion_msgs::msg::LegMotors & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: header

  current_alignment +=
    std_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.header, current_alignment);
  // Member: left_hip_enc_rev
  {
    size_t item_size = sizeof(ros_message.left_hip_enc_rev);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: left_hip_pos
  {
    size_t item_size = sizeof(ros_message.left_hip_pos);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: left_hip_vel
  {
    size_t item_size = sizeof(ros_message.left_hip_vel);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: left_hip_iq
  {
    size_t item_size = sizeof(ros_message.left_hip_iq);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: left_knee_enc_rev
  {
    size_t item_size = sizeof(ros_message.left_knee_enc_rev);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: left_knee_pos
  {
    size_t item_size = sizeof(ros_message.left_knee_pos);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: left_knee_vel
  {
    size_t item_size = sizeof(ros_message.left_knee_vel);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: left_knee_iq
  {
    size_t item_size = sizeof(ros_message.left_knee_iq);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: left_wheel_enc_rev
  {
    size_t item_size = sizeof(ros_message.left_wheel_enc_rev);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: left_wheel_pos
  {
    size_t item_size = sizeof(ros_message.left_wheel_pos);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: left_wheel_vel
  {
    size_t item_size = sizeof(ros_message.left_wheel_vel);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: left_wheel_iq
  {
    size_t item_size = sizeof(ros_message.left_wheel_iq);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: right_hip_enc_rev
  {
    size_t item_size = sizeof(ros_message.right_hip_enc_rev);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: right_hip_pos
  {
    size_t item_size = sizeof(ros_message.right_hip_pos);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: right_hip_vel
  {
    size_t item_size = sizeof(ros_message.right_hip_vel);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: right_hip_iq
  {
    size_t item_size = sizeof(ros_message.right_hip_iq);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: right_knee_enc_rev
  {
    size_t item_size = sizeof(ros_message.right_knee_enc_rev);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: right_knee_pos
  {
    size_t item_size = sizeof(ros_message.right_knee_pos);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: right_knee_vel
  {
    size_t item_size = sizeof(ros_message.right_knee_vel);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: right_knee_iq
  {
    size_t item_size = sizeof(ros_message.right_knee_iq);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: right_wheel_enc_rev
  {
    size_t item_size = sizeof(ros_message.right_wheel_enc_rev);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: right_wheel_pos
  {
    size_t item_size = sizeof(ros_message.right_wheel_pos);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: right_wheel_vel
  {
    size_t item_size = sizeof(ros_message.right_wheel_vel);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: right_wheel_iq
  {
    size_t item_size = sizeof(ros_message.right_wheel_iq);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: left_leg_length
  {
    size_t item_size = sizeof(ros_message.left_leg_length);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: right_leg_length
  {
    size_t item_size = sizeof(ros_message.right_leg_length);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_motion_msgs
max_serialized_size_LegMotors(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: header
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        std_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_Header(
        full_bounded, current_alignment);
    }
  }

  // Member: left_hip_enc_rev
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: left_hip_pos
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: left_hip_vel
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: left_hip_iq
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: left_knee_enc_rev
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: left_knee_pos
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: left_knee_vel
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: left_knee_iq
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: left_wheel_enc_rev
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: left_wheel_pos
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: left_wheel_vel
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: left_wheel_iq
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: right_hip_enc_rev
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: right_hip_pos
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: right_hip_vel
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: right_hip_iq
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: right_knee_enc_rev
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: right_knee_pos
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: right_knee_vel
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: right_knee_iq
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: right_wheel_enc_rev
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: right_wheel_pos
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: right_wheel_vel
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: right_wheel_iq
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: left_leg_length
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: right_leg_length
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static bool _LegMotors__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const motion_msgs::msg::LegMotors *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _LegMotors__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<motion_msgs::msg::LegMotors *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _LegMotors__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const motion_msgs::msg::LegMotors *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _LegMotors__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_LegMotors(full_bounded, 0);
}

static message_type_support_callbacks_t _LegMotors__callbacks = {
  "motion_msgs::msg",
  "LegMotors",
  _LegMotors__cdr_serialize,
  _LegMotors__cdr_deserialize,
  _LegMotors__get_serialized_size,
  _LegMotors__max_serialized_size
};

static rosidl_message_type_support_t _LegMotors__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_LegMotors__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace motion_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_motion_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<motion_msgs::msg::LegMotors>()
{
  return &motion_msgs::msg::typesupport_fastrtps_cpp::_LegMotors__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, motion_msgs, msg, LegMotors)() {
  return &motion_msgs::msg::typesupport_fastrtps_cpp::_LegMotors__handle;
}

#ifdef __cplusplus
}
#endif
