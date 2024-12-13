// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rrm_msgs:srv/Command.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rrm_msgs/srv/command.h"


#ifndef RRM_MSGS__SRV__DETAIL__COMMAND__STRUCT_H_
#define RRM_MSGS__SRV__DETAIL__COMMAND__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'positions'
// Member 'velocities'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in srv/Command in the package rrm_msgs.
typedef struct rrm_msgs__srv__Command_Request
{
  rosidl_runtime_c__double__Sequence positions;
  rosidl_runtime_c__double__Sequence velocities;
} rrm_msgs__srv__Command_Request;

// Struct for a sequence of rrm_msgs__srv__Command_Request.
typedef struct rrm_msgs__srv__Command_Request__Sequence
{
  rrm_msgs__srv__Command_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rrm_msgs__srv__Command_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/Command in the package rrm_msgs.
typedef struct rrm_msgs__srv__Command_Response
{
  int32_t result_code;
  rosidl_runtime_c__String message;
} rrm_msgs__srv__Command_Response;

// Struct for a sequence of rrm_msgs__srv__Command_Response.
typedef struct rrm_msgs__srv__Command_Response__Sequence
{
  rrm_msgs__srv__Command_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rrm_msgs__srv__Command_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  rrm_msgs__srv__Command_Event__request__MAX_SIZE = 1
};
// response
enum
{
  rrm_msgs__srv__Command_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/Command in the package rrm_msgs.
typedef struct rrm_msgs__srv__Command_Event
{
  service_msgs__msg__ServiceEventInfo info;
  rrm_msgs__srv__Command_Request__Sequence request;
  rrm_msgs__srv__Command_Response__Sequence response;
} rrm_msgs__srv__Command_Event;

// Struct for a sequence of rrm_msgs__srv__Command_Event.
typedef struct rrm_msgs__srv__Command_Event__Sequence
{
  rrm_msgs__srv__Command_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rrm_msgs__srv__Command_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RRM_MSGS__SRV__DETAIL__COMMAND__STRUCT_H_
