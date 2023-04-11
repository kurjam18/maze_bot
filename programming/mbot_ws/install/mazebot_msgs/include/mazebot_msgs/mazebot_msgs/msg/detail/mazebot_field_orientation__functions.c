// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from mazebot_msgs:msg/MazebotFieldOrientation.idl
// generated code does not contain a copyright notice
#include "mazebot_msgs/msg/detail/mazebot_field_orientation__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `laser_scan`
#include "sensor_msgs/msg/detail/laser_scan__functions.h"

bool
mazebot_msgs__msg__MazebotFieldOrientation__init(mazebot_msgs__msg__MazebotFieldOrientation * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    mazebot_msgs__msg__MazebotFieldOrientation__fini(msg);
    return false;
  }
  // laser_scan
  if (!sensor_msgs__msg__LaserScan__init(&msg->laser_scan)) {
    mazebot_msgs__msg__MazebotFieldOrientation__fini(msg);
    return false;
  }
  // front_distance
  // rear_distance
  // left_distance
  // right_distance
  // front_angle_deg
  // rear_angle_deg
  // left_angle_deg
  // right_angle_deg
  return true;
}

void
mazebot_msgs__msg__MazebotFieldOrientation__fini(mazebot_msgs__msg__MazebotFieldOrientation * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // laser_scan
  sensor_msgs__msg__LaserScan__fini(&msg->laser_scan);
  // front_distance
  // rear_distance
  // left_distance
  // right_distance
  // front_angle_deg
  // rear_angle_deg
  // left_angle_deg
  // right_angle_deg
}

bool
mazebot_msgs__msg__MazebotFieldOrientation__are_equal(const mazebot_msgs__msg__MazebotFieldOrientation * lhs, const mazebot_msgs__msg__MazebotFieldOrientation * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // laser_scan
  if (!sensor_msgs__msg__LaserScan__are_equal(
      &(lhs->laser_scan), &(rhs->laser_scan)))
  {
    return false;
  }
  // front_distance
  if (lhs->front_distance != rhs->front_distance) {
    return false;
  }
  // rear_distance
  if (lhs->rear_distance != rhs->rear_distance) {
    return false;
  }
  // left_distance
  if (lhs->left_distance != rhs->left_distance) {
    return false;
  }
  // right_distance
  if (lhs->right_distance != rhs->right_distance) {
    return false;
  }
  // front_angle_deg
  if (lhs->front_angle_deg != rhs->front_angle_deg) {
    return false;
  }
  // rear_angle_deg
  if (lhs->rear_angle_deg != rhs->rear_angle_deg) {
    return false;
  }
  // left_angle_deg
  if (lhs->left_angle_deg != rhs->left_angle_deg) {
    return false;
  }
  // right_angle_deg
  if (lhs->right_angle_deg != rhs->right_angle_deg) {
    return false;
  }
  return true;
}

bool
mazebot_msgs__msg__MazebotFieldOrientation__copy(
  const mazebot_msgs__msg__MazebotFieldOrientation * input,
  mazebot_msgs__msg__MazebotFieldOrientation * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // laser_scan
  if (!sensor_msgs__msg__LaserScan__copy(
      &(input->laser_scan), &(output->laser_scan)))
  {
    return false;
  }
  // front_distance
  output->front_distance = input->front_distance;
  // rear_distance
  output->rear_distance = input->rear_distance;
  // left_distance
  output->left_distance = input->left_distance;
  // right_distance
  output->right_distance = input->right_distance;
  // front_angle_deg
  output->front_angle_deg = input->front_angle_deg;
  // rear_angle_deg
  output->rear_angle_deg = input->rear_angle_deg;
  // left_angle_deg
  output->left_angle_deg = input->left_angle_deg;
  // right_angle_deg
  output->right_angle_deg = input->right_angle_deg;
  return true;
}

mazebot_msgs__msg__MazebotFieldOrientation *
mazebot_msgs__msg__MazebotFieldOrientation__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mazebot_msgs__msg__MazebotFieldOrientation * msg = (mazebot_msgs__msg__MazebotFieldOrientation *)allocator.allocate(sizeof(mazebot_msgs__msg__MazebotFieldOrientation), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(mazebot_msgs__msg__MazebotFieldOrientation));
  bool success = mazebot_msgs__msg__MazebotFieldOrientation__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
mazebot_msgs__msg__MazebotFieldOrientation__destroy(mazebot_msgs__msg__MazebotFieldOrientation * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    mazebot_msgs__msg__MazebotFieldOrientation__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
mazebot_msgs__msg__MazebotFieldOrientation__Sequence__init(mazebot_msgs__msg__MazebotFieldOrientation__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mazebot_msgs__msg__MazebotFieldOrientation * data = NULL;

  if (size) {
    data = (mazebot_msgs__msg__MazebotFieldOrientation *)allocator.zero_allocate(size, sizeof(mazebot_msgs__msg__MazebotFieldOrientation), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = mazebot_msgs__msg__MazebotFieldOrientation__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        mazebot_msgs__msg__MazebotFieldOrientation__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
mazebot_msgs__msg__MazebotFieldOrientation__Sequence__fini(mazebot_msgs__msg__MazebotFieldOrientation__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      mazebot_msgs__msg__MazebotFieldOrientation__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

mazebot_msgs__msg__MazebotFieldOrientation__Sequence *
mazebot_msgs__msg__MazebotFieldOrientation__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mazebot_msgs__msg__MazebotFieldOrientation__Sequence * array = (mazebot_msgs__msg__MazebotFieldOrientation__Sequence *)allocator.allocate(sizeof(mazebot_msgs__msg__MazebotFieldOrientation__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = mazebot_msgs__msg__MazebotFieldOrientation__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
mazebot_msgs__msg__MazebotFieldOrientation__Sequence__destroy(mazebot_msgs__msg__MazebotFieldOrientation__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    mazebot_msgs__msg__MazebotFieldOrientation__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
mazebot_msgs__msg__MazebotFieldOrientation__Sequence__are_equal(const mazebot_msgs__msg__MazebotFieldOrientation__Sequence * lhs, const mazebot_msgs__msg__MazebotFieldOrientation__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!mazebot_msgs__msg__MazebotFieldOrientation__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
mazebot_msgs__msg__MazebotFieldOrientation__Sequence__copy(
  const mazebot_msgs__msg__MazebotFieldOrientation__Sequence * input,
  mazebot_msgs__msg__MazebotFieldOrientation__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(mazebot_msgs__msg__MazebotFieldOrientation);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    mazebot_msgs__msg__MazebotFieldOrientation * data =
      (mazebot_msgs__msg__MazebotFieldOrientation *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!mazebot_msgs__msg__MazebotFieldOrientation__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          mazebot_msgs__msg__MazebotFieldOrientation__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!mazebot_msgs__msg__MazebotFieldOrientation__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
