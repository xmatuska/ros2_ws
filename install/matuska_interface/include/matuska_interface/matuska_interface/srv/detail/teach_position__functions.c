// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from matuska_interface:srv/TeachPosition.idl
// generated code does not contain a copyright notice
#include "matuska_interface/srv/detail/teach_position__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
matuska_interface__srv__TeachPosition_Request__init(matuska_interface__srv__TeachPosition_Request * msg)
{
  if (!msg) {
    return false;
  }
  // velocity
  return true;
}

void
matuska_interface__srv__TeachPosition_Request__fini(matuska_interface__srv__TeachPosition_Request * msg)
{
  if (!msg) {
    return;
  }
  // velocity
}

bool
matuska_interface__srv__TeachPosition_Request__are_equal(const matuska_interface__srv__TeachPosition_Request * lhs, const matuska_interface__srv__TeachPosition_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // velocity
  if (lhs->velocity != rhs->velocity) {
    return false;
  }
  return true;
}

bool
matuska_interface__srv__TeachPosition_Request__copy(
  const matuska_interface__srv__TeachPosition_Request * input,
  matuska_interface__srv__TeachPosition_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // velocity
  output->velocity = input->velocity;
  return true;
}

matuska_interface__srv__TeachPosition_Request *
matuska_interface__srv__TeachPosition_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  matuska_interface__srv__TeachPosition_Request * msg = (matuska_interface__srv__TeachPosition_Request *)allocator.allocate(sizeof(matuska_interface__srv__TeachPosition_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(matuska_interface__srv__TeachPosition_Request));
  bool success = matuska_interface__srv__TeachPosition_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
matuska_interface__srv__TeachPosition_Request__destroy(matuska_interface__srv__TeachPosition_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    matuska_interface__srv__TeachPosition_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
matuska_interface__srv__TeachPosition_Request__Sequence__init(matuska_interface__srv__TeachPosition_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  matuska_interface__srv__TeachPosition_Request * data = NULL;

  if (size) {
    data = (matuska_interface__srv__TeachPosition_Request *)allocator.zero_allocate(size, sizeof(matuska_interface__srv__TeachPosition_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = matuska_interface__srv__TeachPosition_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        matuska_interface__srv__TeachPosition_Request__fini(&data[i - 1]);
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
matuska_interface__srv__TeachPosition_Request__Sequence__fini(matuska_interface__srv__TeachPosition_Request__Sequence * array)
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
      matuska_interface__srv__TeachPosition_Request__fini(&array->data[i]);
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

matuska_interface__srv__TeachPosition_Request__Sequence *
matuska_interface__srv__TeachPosition_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  matuska_interface__srv__TeachPosition_Request__Sequence * array = (matuska_interface__srv__TeachPosition_Request__Sequence *)allocator.allocate(sizeof(matuska_interface__srv__TeachPosition_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = matuska_interface__srv__TeachPosition_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
matuska_interface__srv__TeachPosition_Request__Sequence__destroy(matuska_interface__srv__TeachPosition_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    matuska_interface__srv__TeachPosition_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
matuska_interface__srv__TeachPosition_Request__Sequence__are_equal(const matuska_interface__srv__TeachPosition_Request__Sequence * lhs, const matuska_interface__srv__TeachPosition_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!matuska_interface__srv__TeachPosition_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
matuska_interface__srv__TeachPosition_Request__Sequence__copy(
  const matuska_interface__srv__TeachPosition_Request__Sequence * input,
  matuska_interface__srv__TeachPosition_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(matuska_interface__srv__TeachPosition_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    matuska_interface__srv__TeachPosition_Request * data =
      (matuska_interface__srv__TeachPosition_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!matuska_interface__srv__TeachPosition_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          matuska_interface__srv__TeachPosition_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!matuska_interface__srv__TeachPosition_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `message`
#include "rosidl_runtime_c/string_functions.h"

bool
matuska_interface__srv__TeachPosition_Response__init(matuska_interface__srv__TeachPosition_Response * msg)
{
  if (!msg) {
    return false;
  }
  // result
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    matuska_interface__srv__TeachPosition_Response__fini(msg);
    return false;
  }
  return true;
}

void
matuska_interface__srv__TeachPosition_Response__fini(matuska_interface__srv__TeachPosition_Response * msg)
{
  if (!msg) {
    return;
  }
  // result
  // message
  rosidl_runtime_c__String__fini(&msg->message);
}

bool
matuska_interface__srv__TeachPosition_Response__are_equal(const matuska_interface__srv__TeachPosition_Response * lhs, const matuska_interface__srv__TeachPosition_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // result
  if (lhs->result != rhs->result) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->message), &(rhs->message)))
  {
    return false;
  }
  return true;
}

bool
matuska_interface__srv__TeachPosition_Response__copy(
  const matuska_interface__srv__TeachPosition_Response * input,
  matuska_interface__srv__TeachPosition_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // result
  output->result = input->result;
  // message
  if (!rosidl_runtime_c__String__copy(
      &(input->message), &(output->message)))
  {
    return false;
  }
  return true;
}

matuska_interface__srv__TeachPosition_Response *
matuska_interface__srv__TeachPosition_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  matuska_interface__srv__TeachPosition_Response * msg = (matuska_interface__srv__TeachPosition_Response *)allocator.allocate(sizeof(matuska_interface__srv__TeachPosition_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(matuska_interface__srv__TeachPosition_Response));
  bool success = matuska_interface__srv__TeachPosition_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
matuska_interface__srv__TeachPosition_Response__destroy(matuska_interface__srv__TeachPosition_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    matuska_interface__srv__TeachPosition_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
matuska_interface__srv__TeachPosition_Response__Sequence__init(matuska_interface__srv__TeachPosition_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  matuska_interface__srv__TeachPosition_Response * data = NULL;

  if (size) {
    data = (matuska_interface__srv__TeachPosition_Response *)allocator.zero_allocate(size, sizeof(matuska_interface__srv__TeachPosition_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = matuska_interface__srv__TeachPosition_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        matuska_interface__srv__TeachPosition_Response__fini(&data[i - 1]);
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
matuska_interface__srv__TeachPosition_Response__Sequence__fini(matuska_interface__srv__TeachPosition_Response__Sequence * array)
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
      matuska_interface__srv__TeachPosition_Response__fini(&array->data[i]);
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

matuska_interface__srv__TeachPosition_Response__Sequence *
matuska_interface__srv__TeachPosition_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  matuska_interface__srv__TeachPosition_Response__Sequence * array = (matuska_interface__srv__TeachPosition_Response__Sequence *)allocator.allocate(sizeof(matuska_interface__srv__TeachPosition_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = matuska_interface__srv__TeachPosition_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
matuska_interface__srv__TeachPosition_Response__Sequence__destroy(matuska_interface__srv__TeachPosition_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    matuska_interface__srv__TeachPosition_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
matuska_interface__srv__TeachPosition_Response__Sequence__are_equal(const matuska_interface__srv__TeachPosition_Response__Sequence * lhs, const matuska_interface__srv__TeachPosition_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!matuska_interface__srv__TeachPosition_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
matuska_interface__srv__TeachPosition_Response__Sequence__copy(
  const matuska_interface__srv__TeachPosition_Response__Sequence * input,
  matuska_interface__srv__TeachPosition_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(matuska_interface__srv__TeachPosition_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    matuska_interface__srv__TeachPosition_Response * data =
      (matuska_interface__srv__TeachPosition_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!matuska_interface__srv__TeachPosition_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          matuska_interface__srv__TeachPosition_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!matuska_interface__srv__TeachPosition_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `info`
#include "service_msgs/msg/detail/service_event_info__functions.h"
// Member `request`
// Member `response`
// already included above
// #include "matuska_interface/srv/detail/teach_position__functions.h"

bool
matuska_interface__srv__TeachPosition_Event__init(matuska_interface__srv__TeachPosition_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    matuska_interface__srv__TeachPosition_Event__fini(msg);
    return false;
  }
  // request
  if (!matuska_interface__srv__TeachPosition_Request__Sequence__init(&msg->request, 0)) {
    matuska_interface__srv__TeachPosition_Event__fini(msg);
    return false;
  }
  // response
  if (!matuska_interface__srv__TeachPosition_Response__Sequence__init(&msg->response, 0)) {
    matuska_interface__srv__TeachPosition_Event__fini(msg);
    return false;
  }
  return true;
}

void
matuska_interface__srv__TeachPosition_Event__fini(matuska_interface__srv__TeachPosition_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  matuska_interface__srv__TeachPosition_Request__Sequence__fini(&msg->request);
  // response
  matuska_interface__srv__TeachPosition_Response__Sequence__fini(&msg->response);
}

bool
matuska_interface__srv__TeachPosition_Event__are_equal(const matuska_interface__srv__TeachPosition_Event * lhs, const matuska_interface__srv__TeachPosition_Event * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__are_equal(
      &(lhs->info), &(rhs->info)))
  {
    return false;
  }
  // request
  if (!matuska_interface__srv__TeachPosition_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!matuska_interface__srv__TeachPosition_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
matuska_interface__srv__TeachPosition_Event__copy(
  const matuska_interface__srv__TeachPosition_Event * input,
  matuska_interface__srv__TeachPosition_Event * output)
{
  if (!input || !output) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__copy(
      &(input->info), &(output->info)))
  {
    return false;
  }
  // request
  if (!matuska_interface__srv__TeachPosition_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!matuska_interface__srv__TeachPosition_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

matuska_interface__srv__TeachPosition_Event *
matuska_interface__srv__TeachPosition_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  matuska_interface__srv__TeachPosition_Event * msg = (matuska_interface__srv__TeachPosition_Event *)allocator.allocate(sizeof(matuska_interface__srv__TeachPosition_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(matuska_interface__srv__TeachPosition_Event));
  bool success = matuska_interface__srv__TeachPosition_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
matuska_interface__srv__TeachPosition_Event__destroy(matuska_interface__srv__TeachPosition_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    matuska_interface__srv__TeachPosition_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
matuska_interface__srv__TeachPosition_Event__Sequence__init(matuska_interface__srv__TeachPosition_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  matuska_interface__srv__TeachPosition_Event * data = NULL;

  if (size) {
    data = (matuska_interface__srv__TeachPosition_Event *)allocator.zero_allocate(size, sizeof(matuska_interface__srv__TeachPosition_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = matuska_interface__srv__TeachPosition_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        matuska_interface__srv__TeachPosition_Event__fini(&data[i - 1]);
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
matuska_interface__srv__TeachPosition_Event__Sequence__fini(matuska_interface__srv__TeachPosition_Event__Sequence * array)
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
      matuska_interface__srv__TeachPosition_Event__fini(&array->data[i]);
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

matuska_interface__srv__TeachPosition_Event__Sequence *
matuska_interface__srv__TeachPosition_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  matuska_interface__srv__TeachPosition_Event__Sequence * array = (matuska_interface__srv__TeachPosition_Event__Sequence *)allocator.allocate(sizeof(matuska_interface__srv__TeachPosition_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = matuska_interface__srv__TeachPosition_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
matuska_interface__srv__TeachPosition_Event__Sequence__destroy(matuska_interface__srv__TeachPosition_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    matuska_interface__srv__TeachPosition_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
matuska_interface__srv__TeachPosition_Event__Sequence__are_equal(const matuska_interface__srv__TeachPosition_Event__Sequence * lhs, const matuska_interface__srv__TeachPosition_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!matuska_interface__srv__TeachPosition_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
matuska_interface__srv__TeachPosition_Event__Sequence__copy(
  const matuska_interface__srv__TeachPosition_Event__Sequence * input,
  matuska_interface__srv__TeachPosition_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(matuska_interface__srv__TeachPosition_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    matuska_interface__srv__TeachPosition_Event * data =
      (matuska_interface__srv__TeachPosition_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!matuska_interface__srv__TeachPosition_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          matuska_interface__srv__TeachPosition_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!matuska_interface__srv__TeachPosition_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}