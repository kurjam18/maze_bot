// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from mazebot_msgs:msg/MazebotFieldOrientation.idl
// generated code does not contain a copyright notice

#ifndef MAZEBOT_MSGS__MSG__DETAIL__MAZEBOT_FIELD_ORIENTATION__STRUCT_H_
#define MAZEBOT_MSGS__MSG__DETAIL__MAZEBOT_FIELD_ORIENTATION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'laser_scan'
#include "sensor_msgs/msg/detail/laser_scan__struct.h"

/// Struct defined in msg/MazebotFieldOrientation in the package mazebot_msgs.
/**
  * Mazebot
  * Author: -
  * 2023, ver 0.1
 */
typedef struct mazebot_msgs__msg__MazebotFieldOrientation
{
  std_msgs__msg__Header header;
  sensor_msgs__msg__LaserScan laser_scan;
  float front_distance;
  float rear_distance;
  float left_distance;
  float right_distance;
  float front_angle_deg;
  float rear_angle_deg;
  float left_angle_deg;
  float right_angle_deg;
} mazebot_msgs__msg__MazebotFieldOrientation;

// Struct for a sequence of mazebot_msgs__msg__MazebotFieldOrientation.
typedef struct mazebot_msgs__msg__MazebotFieldOrientation__Sequence
{
  mazebot_msgs__msg__MazebotFieldOrientation * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mazebot_msgs__msg__MazebotFieldOrientation__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MAZEBOT_MSGS__MSG__DETAIL__MAZEBOT_FIELD_ORIENTATION__STRUCT_H_