// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from motion_msgs:msg/CtrlPlot.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "motion_msgs/msg/detail/ctrl_plot__rosidl_typesupport_introspection_c.h"
#include "motion_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "motion_msgs/msg/detail/ctrl_plot__functions.h"
#include "motion_msgs/msg/detail/ctrl_plot__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void CtrlPlot__rosidl_typesupport_introspection_c__CtrlPlot_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  motion_msgs__msg__CtrlPlot__init(message_memory);
}

void CtrlPlot__rosidl_typesupport_introspection_c__CtrlPlot_fini_function(void * message_memory)
{
  motion_msgs__msg__CtrlPlot__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember CtrlPlot__rosidl_typesupport_introspection_c__CtrlPlot_message_member_array[2] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(motion_msgs__msg__CtrlPlot, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "value",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(motion_msgs__msg__CtrlPlot, value),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers CtrlPlot__rosidl_typesupport_introspection_c__CtrlPlot_message_members = {
  "motion_msgs__msg",  // message namespace
  "CtrlPlot",  // message name
  2,  // number of fields
  sizeof(motion_msgs__msg__CtrlPlot),
  CtrlPlot__rosidl_typesupport_introspection_c__CtrlPlot_message_member_array,  // message members
  CtrlPlot__rosidl_typesupport_introspection_c__CtrlPlot_init_function,  // function to initialize message memory (memory has to be allocated)
  CtrlPlot__rosidl_typesupport_introspection_c__CtrlPlot_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t CtrlPlot__rosidl_typesupport_introspection_c__CtrlPlot_message_type_support_handle = {
  0,
  &CtrlPlot__rosidl_typesupport_introspection_c__CtrlPlot_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_motion_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, motion_msgs, msg, CtrlPlot)() {
  CtrlPlot__rosidl_typesupport_introspection_c__CtrlPlot_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  if (!CtrlPlot__rosidl_typesupport_introspection_c__CtrlPlot_message_type_support_handle.typesupport_identifier) {
    CtrlPlot__rosidl_typesupport_introspection_c__CtrlPlot_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &CtrlPlot__rosidl_typesupport_introspection_c__CtrlPlot_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
