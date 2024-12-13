// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from matuska_interface:srv/TeachPosition.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "matuska_interface/srv/teach_position.h"


#ifndef MATUSKA_INTERFACE__SRV__DETAIL__TEACH_POSITION__STRUCT_H_
#define MATUSKA_INTERFACE__SRV__DETAIL__TEACH_POSITION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/TeachPosition in the package matuska_interface.
typedef struct matuska_interface__srv__TeachPosition_Request
{
  double velocity;
} matuska_interface__srv__TeachPosition_Request;

// Struct for a sequence of matuska_interface__srv__TeachPosition_Request.
typedef struct matuska_interface__srv__TeachPosition_Request__Sequence
{
  matuska_interface__srv__TeachPosition_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} matuska_interface__srv__TeachPosition_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/TeachPosition in the package matuska_interface.
typedef struct matuska_interface__srv__TeachPosition_Response
{
  bool result;
  rosidl_runtime_c__String message;
} matuska_interface__srv__TeachPosition_Response;

// Struct for a sequence of matuska_interface__srv__TeachPosition_Response.
typedef struct matuska_interface__srv__TeachPosition_Response__Sequence
{
  matuska_interface__srv__TeachPosition_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} matuska_interface__srv__TeachPosition_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  matuska_interface__srv__TeachPosition_Event__request__MAX_SIZE = 1
};
// response
enum
{
  matuska_interface__srv__TeachPosition_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/TeachPosition in the package matuska_interface.
typedef struct matuska_interface__srv__TeachPosition_Event
{
  service_msgs__msg__ServiceEventInfo info;
  matuska_interface__srv__TeachPosition_Request__Sequence request;
  matuska_interface__srv__TeachPosition_Response__Sequence response;
} matuska_interface__srv__TeachPosition_Event;

// Struct for a sequence of matuska_interface__srv__TeachPosition_Event.
typedef struct matuska_interface__srv__TeachPosition_Event__Sequence
{
  matuska_interface__srv__TeachPosition_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} matuska_interface__srv__TeachPosition_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MATUSKA_INTERFACE__SRV__DETAIL__TEACH_POSITION__STRUCT_H_
