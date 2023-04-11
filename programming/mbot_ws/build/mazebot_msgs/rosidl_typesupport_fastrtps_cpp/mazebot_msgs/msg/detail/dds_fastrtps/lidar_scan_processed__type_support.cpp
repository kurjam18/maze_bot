// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from mazebot_msgs:msg/LidarScanProcessed.idl
// generated code does not contain a copyright notice
#include "mazebot_msgs/msg/detail/lidar_scan_processed__rosidl_typesupport_fastrtps_cpp.hpp"
#include "mazebot_msgs/msg/detail/lidar_scan_processed__struct.hpp"

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
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace std_msgs

namespace sensor_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const sensor_msgs::msg::LaserScan &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  sensor_msgs::msg::LaserScan &);
size_t get_serialized_size(
  const sensor_msgs::msg::LaserScan &,
  size_t current_alignment);
size_t
max_serialized_size_LaserScan(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace sensor_msgs


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
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.header,
    cdr);
  // Member: laser_scan
  sensor_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.laser_scan,
    cdr);
  // Member: front_distance
  cdr << ros_message.front_distance;
  // Member: rear_distance
  cdr << ros_message.rear_distance;
  // Member: left_distance
  cdr << ros_message.left_distance;
  // Member: right_distance
  cdr << ros_message.right_distance;
  // Member: left_angle_deg
  cdr << ros_message.left_angle_deg;
  // Member: right_angle_deg
  cdr << ros_message.right_angle_deg;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_mazebot_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  mazebot_msgs::msg::LidarScanProcessed & ros_message)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.header);

  // Member: laser_scan
  sensor_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.laser_scan);

  // Member: front_distance
  cdr >> ros_message.front_distance;

  // Member: rear_distance
  cdr >> ros_message.rear_distance;

  // Member: left_distance
  cdr >> ros_message.left_distance;

  // Member: right_distance
  cdr >> ros_message.right_distance;

  // Member: left_angle_deg
  cdr >> ros_message.left_angle_deg;

  // Member: right_angle_deg
  cdr >> ros_message.right_angle_deg;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_mazebot_msgs
get_serialized_size(
  const mazebot_msgs::msg::LidarScanProcessed & ros_message,
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
  // Member: laser_scan

  current_alignment +=
    sensor_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.laser_scan, current_alignment);
  // Member: front_distance
  {
    size_t item_size = sizeof(ros_message.front_distance);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: rear_distance
  {
    size_t item_size = sizeof(ros_message.rear_distance);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: left_distance
  {
    size_t item_size = sizeof(ros_message.left_distance);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: right_distance
  {
    size_t item_size = sizeof(ros_message.right_distance);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: left_angle_deg
  {
    size_t item_size = sizeof(ros_message.left_angle_deg);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: right_angle_deg
  {
    size_t item_size = sizeof(ros_message.right_angle_deg);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_mazebot_msgs
max_serialized_size_LidarScanProcessed(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: header
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      current_alignment +=
        std_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_Header(
        inner_full_bounded, inner_is_plain, current_alignment);
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: laser_scan
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      current_alignment +=
        sensor_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_LaserScan(
        inner_full_bounded, inner_is_plain, current_alignment);
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: front_distance
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: rear_distance
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: left_distance
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: right_distance
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: left_angle_deg
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: right_angle_deg
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static bool _LidarScanProcessed__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const mazebot_msgs::msg::LidarScanProcessed *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _LidarScanProcessed__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<mazebot_msgs::msg::LidarScanProcessed *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _LidarScanProcessed__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const mazebot_msgs::msg::LidarScanProcessed *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _LidarScanProcessed__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_LidarScanProcessed(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _LidarScanProcessed__callbacks = {
  "mazebot_msgs::msg",
  "LidarScanProcessed",
  _LidarScanProcessed__cdr_serialize,
  _LidarScanProcessed__cdr_deserialize,
  _LidarScanProcessed__get_serialized_size,
  _LidarScanProcessed__max_serialized_size
};

static rosidl_message_type_support_t _LidarScanProcessed__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_LidarScanProcessed__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace mazebot_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_mazebot_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<mazebot_msgs::msg::LidarScanProcessed>()
{
  return &mazebot_msgs::msg::typesupport_fastrtps_cpp::_LidarScanProcessed__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, mazebot_msgs, msg, LidarScanProcessed)() {
  return &mazebot_msgs::msg::typesupport_fastrtps_cpp::_LidarScanProcessed__handle;
}

#ifdef __cplusplus
}
#endif
