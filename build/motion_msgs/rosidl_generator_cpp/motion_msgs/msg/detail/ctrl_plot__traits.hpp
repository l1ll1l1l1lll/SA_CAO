// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from motion_msgs:msg/CtrlPlot.idl
// generated code does not contain a copyright notice

#ifndef MOTION_MSGS__MSG__DETAIL__CTRL_PLOT__TRAITS_HPP_
#define MOTION_MSGS__MSG__DETAIL__CTRL_PLOT__TRAITS_HPP_

#include "motion_msgs/msg/detail/ctrl_plot__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<motion_msgs::msg::CtrlPlot>()
{
  return "motion_msgs::msg::CtrlPlot";
}

template<>
inline const char * name<motion_msgs::msg::CtrlPlot>()
{
  return "motion_msgs/msg/CtrlPlot";
}

template<>
struct has_fixed_size<motion_msgs::msg::CtrlPlot>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<motion_msgs::msg::CtrlPlot>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<motion_msgs::msg::CtrlPlot>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MOTION_MSGS__MSG__DETAIL__CTRL_PLOT__TRAITS_HPP_
