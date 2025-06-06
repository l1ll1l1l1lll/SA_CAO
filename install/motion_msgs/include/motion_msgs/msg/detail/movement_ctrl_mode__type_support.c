// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from motion_msgs:msg/MovementCtrlMode.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "motion_msgs/msg/detail/movement_ctrl_mode__rosidl_typesupport_introspection_c.h"
#include "motion_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "motion_msgs/msg/detail/movement_ctrl_mode__functions.h"
#include "motion_msgs/msg/detail/movement_ctrl_mode__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void MovementCtrlMode__rosidl_typesupport_introspection_c__MovementCtrlMode_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  motion_msgs__msg__MovementCtrlMode__init(message_memory);
}

void MovementCtrlMode__rosidl_typesupport_introspection_c__MovementCtrlMode_fini_function(void * message_memory)
{
  motion_msgs__msg__MovementCtrlMode__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember MovementCtrlMode__rosidl_typesupport_introspection_c__MovementCtrlMode_message_member_array[6] = {
  {
    "pitch_ctrl_mode",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(motion_msgs__msg__MovementCtrlMode, pitch_ctrl_mode),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "roll_ctrl_mode",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(motion_msgs__msg__MovementCtrlMode, roll_ctrl_mode),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "height_ctrl_mode",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(motion_msgs__msg__MovementCtrlMode, height_ctrl_mode),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "stand_mode",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(motion_msgs__msg__MovementCtrlMode, stand_mode),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "jump_mode",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(motion_msgs__msg__MovementCtrlMode, jump_mode),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "split_mode",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(motion_msgs__msg__MovementCtrlMode, split_mode),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers MovementCtrlMode__rosidl_typesupport_introspection_c__MovementCtrlMode_message_members = {
  "motion_msgs__msg",  // message namespace
  "MovementCtrlMode",  // message name
  6,  // number of fields
  sizeof(motion_msgs__msg__MovementCtrlMode),
  MovementCtrlMode__rosidl_typesupport_introspection_c__MovementCtrlMode_message_member_array,  // message members
  MovementCtrlMode__rosidl_typesupport_introspection_c__MovementCtrlMode_init_function,  // function to initialize message memory (memory has to be allocated)
  MovementCtrlMode__rosidl_typesupport_introspection_c__MovementCtrlMode_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t MovementCtrlMode__rosidl_typesupport_introspection_c__MovementCtrlMode_message_type_support_handle = {
  0,
  &MovementCtrlMode__rosidl_typesupport_introspection_c__MovementCtrlMode_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_motion_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, motion_msgs, msg, MovementCtrlMode)() {
  if (!MovementCtrlMode__rosidl_typesupport_introspection_c__MovementCtrlMode_message_type_support_handle.typesupport_identifier) {
    MovementCtrlMode__rosidl_typesupport_introspection_c__MovementCtrlMode_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &MovementCtrlMode__rosidl_typesupport_introspection_c__MovementCtrlMode_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
