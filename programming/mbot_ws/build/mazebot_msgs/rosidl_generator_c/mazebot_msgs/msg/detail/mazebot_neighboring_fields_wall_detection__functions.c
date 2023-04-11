// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from mazebot_msgs:msg/MazebotNeighboringFieldsWallDetection.idl
// generated code does not contain a copyright notice
#include "mazebot_msgs/msg/detail/mazebot_neighboring_fields_wall_detection__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
mazebot_msgs__msg__MazebotNeighboringFieldsWallDetection__init(mazebot_msgs__msg__MazebotNeighboringFieldsWallDetection * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    mazebot_msgs__msg__MazebotNeighboringFieldsWallDetection__fini(msg);
    return false;
  }
  // front
  // rear
  // left
  // right
  return true;
}

void
mazebot_msgs__msg__MazebotNeighboringFieldsWallDetection__fini(mazebot_msgs__msg__MazebotNeighboringFieldsWallDetection * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // front
  // rear
  // left
  // right
}

bool
mazebot_msgs__msg__MazebotNeighboringFieldsWallDetection__are_equal(const mazebot_msgs__msg__MazebotNeighboringFieldsWallDetection * lhs, const mazebot_msgs__msg__MazebotNeighboringFieldsWallDetection * rhs)
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
  // front
  for (size_t i = 0; i < 4; ++i) {
    if (lhs->front[i] != rhs->front[i]) {
      return false;
    }
  }
  // rear
  for (size_t i = 0; i < 4; ++i) {
    if (lhs->rear[i] != rhs->rear[i]) {
      return false;
    }
  }
  // left
  for (size_t i = 0; i < 4; ++i) {
    if (lhs->left[i] != rhs->left[i]) {
      return false;
    }
  }
  // right
  for (size_t i = 0; i < 4; ++i) {
    if (lhs->right[i] != rhs->right[i]) {
      return false;
    }
  }
  return true;
}

bool
mazebot_msgs__msg__MazebotNeighboringFieldsWallDetection__copy(
  const mazebot_msgs__msg__MazebotNeighboringFieldsWallDetection * input,
  mazebot_msgs__msg__MazebotNeighboringFieldsWallDetection * output)
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
  // front
  for (size_t i = 0; i < 4; ++i) {
    output->front[i] = input->front[i];
  }
  // rear
  for (size_t i = 0; i < 4; ++i) {
    output->rear[i] = input->rear[i];
  }
  // left
  for (size_t i = 0; i < 4; ++i) {
    output->left[i] = input->left[i];
  }
  // right
  for (size_t i = 0; i < 4; ++i) {
    output->right[i] = input->right[i];
  }
  return true;
}

mazebot_msgs__msg__MazebotNeighboringFieldsWallDetection *
mazebot_msgs__msg__MazebotNeighboringFieldsWallDetection__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mazebot_msgs__msg__MazebotNeighboringFieldsWallDetection * msg = (mazebot_msgs__msg__MazebotNeighboringFieldsWallDetection *)allocator.allocate(sizeof(mazebot_msgs__msg__MazebotNeighboringFieldsWallDetection), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(mazebot_msgs__msg__MazebotNeighboringFieldsWallDetection));
  bool success = mazebot_msgs__msg__MazebotNeighboringFieldsWallDetection__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
mazebot_msgs__msg__MazebotNeighboringFieldsWallDetection__destroy(mazebot_msgs__msg__MazebotNeighboringFieldsWallDetection * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    mazebot_msgs__msg__MazebotNeighboringFieldsWallDetection__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
mazebot_msgs__msg__MazebotNeighboringFieldsWallDetection__Sequence__init(mazebot_msgs__msg__MazebotNeighboringFieldsWallDetection__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mazebot_msgs__msg__MazebotNeighboringFieldsWallDetection * data = NULL;

  if (size) {
    data = (mazebot_msgs__msg__MazebotNeighboringFieldsWallDetection *)allocator.zero_allocate(size, sizeof(mazebot_msgs__msg__MazebotNeighboringFieldsWallDetection), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = mazebot_msgs__msg__MazebotNeighboringFieldsWallDetection__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        mazebot_msgs__msg__MazebotNeighboringFieldsWallDetection__fini(&data[i - 1]);
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
mazebot_msgs__msg__MazebotNeighboringFieldsWallDetection__Sequence__fini(mazebot_msgs__msg__MazebotNeighboringFieldsWallDetection__Sequence * array)
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
      mazebot_msgs__msg__MazebotNeighboringFieldsWallDetection__fini(&array->data[i]);
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

mazebot_msgs__msg__MazebotNeighboringFieldsWallDetection__Sequence *
mazebot_msgs__msg__MazebotNeighboringFieldsWallDetection__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mazebot_msgs__msg__MazebotNeighboringFieldsWallDetection__Sequence * array = (mazebot_msgs__msg__MazebotNeighboringFieldsWallDetection__Sequence *)allocator.allocate(sizeof(mazebot_msgs__msg__MazebotNeighboringFieldsWallDetection__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = mazebot_msgs__msg__MazebotNeighboringFieldsWallDetection__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
mazebot_msgs__msg__MazebotNeighboringFieldsWallDetection__Sequence__destroy(mazebot_msgs__msg__MazebotNeighboringFieldsWallDetection__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    mazebot_msgs__msg__MazebotNeighboringFieldsWallDetection__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
mazebot_msgs__msg__MazebotNeighboringFieldsWallDetection__Sequence__are_equal(const mazebot_msgs__msg__MazebotNeighboringFieldsWallDetection__Sequence * lhs, const mazebot_msgs__msg__MazebotNeighboringFieldsWallDetection__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!mazebot_msgs__msg__MazebotNeighboringFieldsWallDetection__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
mazebot_msgs__msg__MazebotNeighboringFieldsWallDetection__Sequence__copy(
  const mazebot_msgs__msg__MazebotNeighboringFieldsWallDetection__Sequence * input,
  mazebot_msgs__msg__MazebotNeighboringFieldsWallDetection__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(mazebot_msgs__msg__MazebotNeighboringFieldsWallDetection);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    mazebot_msgs__msg__MazebotNeighboringFieldsWallDetection * data =
      (mazebot_msgs__msg__MazebotNeighboringFieldsWallDetection *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!mazebot_msgs__msg__MazebotNeighboringFieldsWallDetection__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          mazebot_msgs__msg__MazebotNeighboringFieldsWallDetection__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!mazebot_msgs__msg__MazebotNeighboringFieldsWallDetection__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
