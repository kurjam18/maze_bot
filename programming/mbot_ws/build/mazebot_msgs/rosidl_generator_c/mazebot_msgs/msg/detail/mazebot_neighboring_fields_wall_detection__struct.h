// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from mazebot_msgs:msg/MazebotNeighboringFieldsWallDetection.idl
// generated code does not contain a copyright notice

#ifndef MAZEBOT_MSGS__MSG__DETAIL__MAZEBOT_NEIGHBORING_FIELDS_WALL_DETECTION__STRUCT_H_
#define MAZEBOT_MSGS__MSG__DETAIL__MAZEBOT_NEIGHBORING_FIELDS_WALL_DETECTION__STRUCT_H_

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

/// Struct defined in msg/MazebotNeighboringFieldsWallDetection in the package mazebot_msgs.
/**
  * Mazebot
  * Author: -
  * 2023, ver 0.1
 */
typedef struct mazebot_msgs__msg__MazebotNeighboringFieldsWallDetection
{
  std_msgs__msg__Header header;
  /// [front, rear, left, right]
  int8_t front[4];
  int8_t rear[4];
  int8_t left[4];
  int8_t right[4];
} mazebot_msgs__msg__MazebotNeighboringFieldsWallDetection;

// Struct for a sequence of mazebot_msgs__msg__MazebotNeighboringFieldsWallDetection.
typedef struct mazebot_msgs__msg__MazebotNeighboringFieldsWallDetection__Sequence
{
  mazebot_msgs__msg__MazebotNeighboringFieldsWallDetection * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mazebot_msgs__msg__MazebotNeighboringFieldsWallDetection__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MAZEBOT_MSGS__MSG__DETAIL__MAZEBOT_NEIGHBORING_FIELDS_WALL_DETECTION__STRUCT_H_
