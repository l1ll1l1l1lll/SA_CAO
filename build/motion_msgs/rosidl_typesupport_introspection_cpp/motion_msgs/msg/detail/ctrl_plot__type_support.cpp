// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from motion_msgs:msg/CtrlPlot.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "motion_msgs/msg/detail/ctrl_plot__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace motion_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void CtrlPlot_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) motion_msgs::msg::CtrlPlot(_init);
}

void CtrlPlot_fini_function(void * message_memory)
{
  auto typed_message = static_cast<motion_msgs::msg::CtrlPlot *>(message_memory);
  typed_message->~CtrlPlot();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember CtrlPlot_message_member_array[2] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(motion_msgs::msg::CtrlPlot, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "value",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(motion_msgs::msg::CtrlPlot, value),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers CtrlPlot_message_members = {
  "motion_msgs::msg",  // message namespace
  "CtrlPlot",  // message name
  2,  // number of fields
  sizeof(motion_msgs::msg::CtrlPlot),
  CtrlPlot_message_member_array,  // message members
  CtrlPlot_init_function,  // function to initialize message memory (memory has to be allocated)
  CtrlPlot_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t CtrlPlot_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &CtrlPlot_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace motion_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<motion_msgs::msg::CtrlPlot>()
{
  return &::motion_msgs::msg::rosidl_typesupport_introspection_cpp::CtrlPlot_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, motion_msgs, msg, CtrlPlot)() {
  return &::motion_msgs::msg::rosidl_typesupport_introspection_cpp::CtrlPlot_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
