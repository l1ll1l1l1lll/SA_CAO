// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ception_msgs:msg/IMUEuler.idl
// generated code does not contain a copyright notice

#ifndef CEPTION_MSGS__MSG__DETAIL__IMU_EULER__TRAITS_HPP_
#define CEPTION_MSGS__MSG__DETAIL__IMU_EULER__TRAITS_HPP_

#include "ception_msgs/msg/detail/imu_euler__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<ception_msgs::msg::IMUEuler>()
{
  return "ception_msgs::msg::IMUEuler";
}

template<>
inline const char * name<ception_msgs::msg::IMUEuler>()
{
  return "ception_msgs/msg/IMUEuler";
}

template<>
struct has_fixed_size<ception_msgs::msg::IMUEuler>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<ception_msgs::msg::IMUEuler>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<ception_msgs::msg::IMUEuler>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CEPTION_MSGS__MSG__DETAIL__IMU_EULER__TRAITS_HPP_
