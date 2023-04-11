// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from mazebot_msgs:msg/LidarScanProcessed.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "mazebot_msgs/msg/detail/lidar_scan_processed__rosidl_typesupport_introspection_c.h"
#include "mazebot_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "mazebot_msgs/msg/detail/lidar_scan_processed__functions.h"
#include "mazebot_msgs/msg/detail/lidar_scan_processed__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `laser_scan`
#include "sensor_msgs/msg/laser_scan.h"
// Member `laser_scan`
#include "sensor_msgs/msg/detail/laser_scan__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void mazebot_msgs__msg__LidarScanProcessed__rosidl_typesupport_introspection_c__LidarScanProcessed_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  mazebot_msgs__msg__LidarScanProcessed__init(message_memory);
}

void mazebot_msgs__msg__LidarScanProcessed__rosidl_typesupport_introspection_c__LidarScanProcessed_fini_function(void * message_memory)
{
  mazebot_msgs__msg__LidarScanProcessed__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember mazebot_msgs__msg__LidarScanProcessed__rosidl_typesupport_introspection_c__LidarScanProcessed_message_member_array[8] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(mazebot_msgs__msg__LidarScanProcessed, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "laser_scan",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(mazebot_msgs__msg__LidarScanProcessed, laser_scan),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "front_distance",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(mazebot_msgs__msg__LidarScanProcessed, front_distance),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "rear_distance",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(mazebot_msgs__msg__LidarScanProcessed, rear_distance),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "left_distance",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(mazebot_msgs__msg__LidarScanProcessed, left_distance),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "right_distance",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(mazebot_msgs__msg__LidarScanProcessed, right_distance),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "left_angle_deg",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(mazebot_msgs__msg__LidarScanProcessed, left_angle_deg),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "right_angle_deg",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(mazebot_msgs__msg__LidarScanProcessed, right_angle_deg),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers mazebot_msgs__msg__LidarScanProcessed__rosidl_typesupport_introspection_c__LidarScanProcessed_message_members = {
  "mazebot_msgs__msg",  // message namespace
  "LidarScanProcessed",  // message name
  8,  // number of fields
  sizeof(mazebot_msgs__msg__LidarScanProcessed),
  mazebot_msgs__msg__LidarScanProcessed__rosidl_typesupport_introspection_c__LidarScanProcessed_message_member_array,  // message members
  mazebot_msgs__msg__LidarScanProcessed__rosidl_typesupport_introspection_c__LidarScanProcessed_init_function,  // function to initialize message memory (memory has to be allocated)
  mazebot_msgs__msg__LidarScanProcessed__rosidl_typesupport_introspection_c__LidarScanProcessed_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t mazebot_msgs__msg__LidarScanProcessed__rosidl_typesupport_introspection_c__LidarScanProcessed_message_type_support_handle = {
  0,
  &mazebot_msgs__msg__LidarScanProcessed__rosidl_typesupport_introspection_c__LidarScanProcessed_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_mazebot_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, mazebot_msgs, msg, LidarScanProcessed)() {
  mazebot_msgs__msg__LidarScanProcessed__rosidl_typesupport_introspection_c__LidarScanProcessed_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  mazebot_msgs__msg__LidarScanProcessed__rosidl_typesupport_introspection_c__LidarScanProcessed_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sensor_msgs, msg, LaserScan)();
  if (!mazebot_msgs__msg__LidarScanProcessed__rosidl_typesupport_introspection_c__LidarScanProcessed_message_type_support_handle.typesupport_identifier) {
    mazebot_msgs__msg__LidarScanProcessed__rosidl_typesupport_introspection_c__LidarScanProcessed_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &mazebot_msgs__msg__LidarScanProcessed__rosidl_typesupport_introspection_c__LidarScanProcessed_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
