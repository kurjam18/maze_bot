// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from mazebot_msgs:msg/LidarScanProcessed.idl
// generated code does not contain a copyright notice

#ifndef MAZEBOT_MSGS__MSG__DETAIL__LIDAR_SCAN_PROCESSED__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define MAZEBOT_MSGS__MSG__DETAIL__LIDAR_SCAN_PROCESSED__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "mazebot_msgs/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "mazebot_msgs/msg/detail/lidar_scan_processed__struct.hpp"

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

#include "fastcdr/Cdr.h"

namespace mazebot_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_mazebot_msgs
cdr_serialize(
  const mazebot_msgs::msg::LidarScanProcessed & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_mazebot_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  mazebot_msgs::msg::LidarScanProcessed & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_mazebot_msgs
get_serialized_size(
  const mazebot_msgs::msg::LidarScanProcessed & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_mazebot_msgs
max_serialized_size_LidarScanProcessed(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace mazebot_msgs

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_mazebot_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, mazebot_msgs, msg, LidarScanProcessed)();

#ifdef __cplusplus
}
#endif

#endif  // MAZEBOT_MSGS__MSG__DETAIL__LIDAR_SCAN_PROCESSED__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_