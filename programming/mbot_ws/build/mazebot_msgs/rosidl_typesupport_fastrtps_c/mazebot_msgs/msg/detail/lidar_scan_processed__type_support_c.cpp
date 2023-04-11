// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from mazebot_msgs:msg/LidarScanProcessed.idl
// generated code does not contain a copyright notice
#include "mazebot_msgs/msg/detail/lidar_scan_processed__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "mazebot_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "mazebot_msgs/msg/detail/lidar_scan_processed__struct.h"
#include "mazebot_msgs/msg/detail/lidar_scan_processed__functions.h"
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

#include "sensor_msgs/msg/detail/laser_scan__functions.h"  // laser_scan
#include "std_msgs/msg/detail/header__functions.h"  // header

// forward declare type support functions
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_mazebot_msgs
size_t get_serialized_size_sensor_msgs__msg__LaserScan(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_mazebot_msgs
size_t max_serialized_size_sensor_msgs__msg__LaserScan(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_mazebot_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, sensor_msgs, msg, LaserScan)();
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_mazebot_msgs
size_t get_serialized_size_std_msgs__msg__Header(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_mazebot_msgs
size_t max_serialized_size_std_msgs__msg__Header(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_mazebot_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, std_msgs, msg, Header)();


using _LidarScanProcessed__ros_msg_type = mazebot_msgs__msg__LidarScanProcessed;

static bool _LidarScanProcessed__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _LidarScanProcessed__ros_msg_type * ros_message = static_cast<const _LidarScanProcessed__ros_msg_type *>(untyped_ros_message);
  // Field name: header
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, Header
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->header, cdr))
    {
      return false;
    }
  }

  // Field name: laser_scan
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, sensor_msgs, msg, LaserScan
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->laser_scan, cdr))
    {
      return false;
    }
  }

  // Field name: front_distance
  {
    cdr << ros_message->front_distance;
  }

  // Field name: rear_distance
  {
    cdr << ros_message->rear_distance;
  }

  // Field name: left_distance
  {
    cdr << ros_message->left_distance;
  }

  // Field name: right_distance
  {
    cdr << ros_message->right_distance;
  }

  // Field name: left_angle_deg
  {
    cdr << ros_message->left_angle_deg;
  }

  // Field name: right_angle_deg
  {
    cdr << ros_message->right_angle_deg;
  }

  return true;
}

static bool _LidarScanProcessed__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _LidarScanProcessed__ros_msg_type * ros_message = static_cast<_LidarScanProcessed__ros_msg_type *>(untyped_ros_message);
  // Field name: header
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, Header
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->header))
    {
      return false;
    }
  }

  // Field name: laser_scan
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, sensor_msgs, msg, LaserScan
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->laser_scan))
    {
      return false;
    }
  }

  // Field name: front_distance
  {
    cdr >> ros_message->front_distance;
  }

  // Field name: rear_distance
  {
    cdr >> ros_message->rear_distance;
  }

  // Field name: left_distance
  {
    cdr >> ros_message->left_distance;
  }

  // Field name: right_distance
  {
    cdr >> ros_message->right_distance;
  }

  // Field name: left_angle_deg
  {
    cdr >> ros_message->left_angle_deg;
  }

  // Field name: right_angle_deg
  {
    cdr >> ros_message->right_angle_deg;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_mazebot_msgs
size_t get_serialized_size_mazebot_msgs__msg__LidarScanProcessed(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _LidarScanProcessed__ros_msg_type * ros_message = static_cast<const _LidarScanProcessed__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name header

  current_alignment += get_serialized_size_std_msgs__msg__Header(
    &(ros_message->header), current_alignment);
  // field.name laser_scan

  current_alignment += get_serialized_size_sensor_msgs__msg__LaserScan(
    &(ros_message->laser_scan), current_alignment);
  // field.name front_distance
  {
    size_t item_size = sizeof(ros_message->front_distance);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name rear_distance
  {
    size_t item_size = sizeof(ros_message->rear_distance);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name left_distance
  {
    size_t item_size = sizeof(ros_message->left_distance);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name right_distance
  {
    size_t item_size = sizeof(ros_message->right_distance);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name left_angle_deg
  {
    size_t item_size = sizeof(ros_message->left_angle_deg);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name right_angle_deg
  {
    size_t item_size = sizeof(ros_message->right_angle_deg);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _LidarScanProcessed__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_mazebot_msgs__msg__LidarScanProcessed(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_mazebot_msgs
size_t max_serialized_size_mazebot_msgs__msg__LidarScanProcessed(
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

  // member: header
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      current_alignment +=
        max_serialized_size_std_msgs__msg__Header(
        inner_full_bounded, inner_is_plain, current_alignment);
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: laser_scan
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      current_alignment +=
        max_serialized_size_sensor_msgs__msg__LaserScan(
        inner_full_bounded, inner_is_plain, current_alignment);
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: front_distance
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: rear_distance
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: left_distance
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: right_distance
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: left_angle_deg
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: right_angle_deg
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _LidarScanProcessed__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_mazebot_msgs__msg__LidarScanProcessed(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_LidarScanProcessed = {
  "mazebot_msgs::msg",
  "LidarScanProcessed",
  _LidarScanProcessed__cdr_serialize,
  _LidarScanProcessed__cdr_deserialize,
  _LidarScanProcessed__get_serialized_size,
  _LidarScanProcessed__max_serialized_size
};

static rosidl_message_type_support_t _LidarScanProcessed__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_LidarScanProcessed,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, mazebot_msgs, msg, LidarScanProcessed)() {
  return &_LidarScanProcessed__type_support;
}

#if defined(__cplusplus)
}
#endif
