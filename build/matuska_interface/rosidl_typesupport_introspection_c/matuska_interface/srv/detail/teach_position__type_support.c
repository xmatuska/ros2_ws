// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from matuska_interface:srv/TeachPosition.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "matuska_interface/srv/detail/teach_position__rosidl_typesupport_introspection_c.h"
#include "matuska_interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "matuska_interface/srv/detail/teach_position__functions.h"
#include "matuska_interface/srv/detail/teach_position__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void matuska_interface__srv__TeachPosition_Request__rosidl_typesupport_introspection_c__TeachPosition_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  matuska_interface__srv__TeachPosition_Request__init(message_memory);
}

void matuska_interface__srv__TeachPosition_Request__rosidl_typesupport_introspection_c__TeachPosition_Request_fini_function(void * message_memory)
{
  matuska_interface__srv__TeachPosition_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember matuska_interface__srv__TeachPosition_Request__rosidl_typesupport_introspection_c__TeachPosition_Request_message_member_array[1] = {
  {
    "velocity",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(matuska_interface__srv__TeachPosition_Request, velocity),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers matuska_interface__srv__TeachPosition_Request__rosidl_typesupport_introspection_c__TeachPosition_Request_message_members = {
  "matuska_interface__srv",  // message namespace
  "TeachPosition_Request",  // message name
  1,  // number of fields
  sizeof(matuska_interface__srv__TeachPosition_Request),
  false,  // has_any_key_member_
  matuska_interface__srv__TeachPosition_Request__rosidl_typesupport_introspection_c__TeachPosition_Request_message_member_array,  // message members
  matuska_interface__srv__TeachPosition_Request__rosidl_typesupport_introspection_c__TeachPosition_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  matuska_interface__srv__TeachPosition_Request__rosidl_typesupport_introspection_c__TeachPosition_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t matuska_interface__srv__TeachPosition_Request__rosidl_typesupport_introspection_c__TeachPosition_Request_message_type_support_handle = {
  0,
  &matuska_interface__srv__TeachPosition_Request__rosidl_typesupport_introspection_c__TeachPosition_Request_message_members,
  get_message_typesupport_handle_function,
  &matuska_interface__srv__TeachPosition_Request__get_type_hash,
  &matuska_interface__srv__TeachPosition_Request__get_type_description,
  &matuska_interface__srv__TeachPosition_Request__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_matuska_interface
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, matuska_interface, srv, TeachPosition_Request)() {
  if (!matuska_interface__srv__TeachPosition_Request__rosidl_typesupport_introspection_c__TeachPosition_Request_message_type_support_handle.typesupport_identifier) {
    matuska_interface__srv__TeachPosition_Request__rosidl_typesupport_introspection_c__TeachPosition_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &matuska_interface__srv__TeachPosition_Request__rosidl_typesupport_introspection_c__TeachPosition_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "matuska_interface/srv/detail/teach_position__rosidl_typesupport_introspection_c.h"
// already included above
// #include "matuska_interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "matuska_interface/srv/detail/teach_position__functions.h"
// already included above
// #include "matuska_interface/srv/detail/teach_position__struct.h"


// Include directives for member types
// Member `message`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void matuska_interface__srv__TeachPosition_Response__rosidl_typesupport_introspection_c__TeachPosition_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  matuska_interface__srv__TeachPosition_Response__init(message_memory);
}

void matuska_interface__srv__TeachPosition_Response__rosidl_typesupport_introspection_c__TeachPosition_Response_fini_function(void * message_memory)
{
  matuska_interface__srv__TeachPosition_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember matuska_interface__srv__TeachPosition_Response__rosidl_typesupport_introspection_c__TeachPosition_Response_message_member_array[2] = {
  {
    "result",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(matuska_interface__srv__TeachPosition_Response, result),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "message",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(matuska_interface__srv__TeachPosition_Response, message),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers matuska_interface__srv__TeachPosition_Response__rosidl_typesupport_introspection_c__TeachPosition_Response_message_members = {
  "matuska_interface__srv",  // message namespace
  "TeachPosition_Response",  // message name
  2,  // number of fields
  sizeof(matuska_interface__srv__TeachPosition_Response),
  false,  // has_any_key_member_
  matuska_interface__srv__TeachPosition_Response__rosidl_typesupport_introspection_c__TeachPosition_Response_message_member_array,  // message members
  matuska_interface__srv__TeachPosition_Response__rosidl_typesupport_introspection_c__TeachPosition_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  matuska_interface__srv__TeachPosition_Response__rosidl_typesupport_introspection_c__TeachPosition_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t matuska_interface__srv__TeachPosition_Response__rosidl_typesupport_introspection_c__TeachPosition_Response_message_type_support_handle = {
  0,
  &matuska_interface__srv__TeachPosition_Response__rosidl_typesupport_introspection_c__TeachPosition_Response_message_members,
  get_message_typesupport_handle_function,
  &matuska_interface__srv__TeachPosition_Response__get_type_hash,
  &matuska_interface__srv__TeachPosition_Response__get_type_description,
  &matuska_interface__srv__TeachPosition_Response__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_matuska_interface
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, matuska_interface, srv, TeachPosition_Response)() {
  if (!matuska_interface__srv__TeachPosition_Response__rosidl_typesupport_introspection_c__TeachPosition_Response_message_type_support_handle.typesupport_identifier) {
    matuska_interface__srv__TeachPosition_Response__rosidl_typesupport_introspection_c__TeachPosition_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &matuska_interface__srv__TeachPosition_Response__rosidl_typesupport_introspection_c__TeachPosition_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "matuska_interface/srv/detail/teach_position__rosidl_typesupport_introspection_c.h"
// already included above
// #include "matuska_interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "matuska_interface/srv/detail/teach_position__functions.h"
// already included above
// #include "matuska_interface/srv/detail/teach_position__struct.h"


// Include directives for member types
// Member `info`
#include "service_msgs/msg/service_event_info.h"
// Member `info`
#include "service_msgs/msg/detail/service_event_info__rosidl_typesupport_introspection_c.h"
// Member `request`
// Member `response`
#include "matuska_interface/srv/teach_position.h"
// Member `request`
// Member `response`
// already included above
// #include "matuska_interface/srv/detail/teach_position__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void matuska_interface__srv__TeachPosition_Event__rosidl_typesupport_introspection_c__TeachPosition_Event_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  matuska_interface__srv__TeachPosition_Event__init(message_memory);
}

void matuska_interface__srv__TeachPosition_Event__rosidl_typesupport_introspection_c__TeachPosition_Event_fini_function(void * message_memory)
{
  matuska_interface__srv__TeachPosition_Event__fini(message_memory);
}

size_t matuska_interface__srv__TeachPosition_Event__rosidl_typesupport_introspection_c__size_function__TeachPosition_Event__request(
  const void * untyped_member)
{
  const matuska_interface__srv__TeachPosition_Request__Sequence * member =
    (const matuska_interface__srv__TeachPosition_Request__Sequence *)(untyped_member);
  return member->size;
}

const void * matuska_interface__srv__TeachPosition_Event__rosidl_typesupport_introspection_c__get_const_function__TeachPosition_Event__request(
  const void * untyped_member, size_t index)
{
  const matuska_interface__srv__TeachPosition_Request__Sequence * member =
    (const matuska_interface__srv__TeachPosition_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void * matuska_interface__srv__TeachPosition_Event__rosidl_typesupport_introspection_c__get_function__TeachPosition_Event__request(
  void * untyped_member, size_t index)
{
  matuska_interface__srv__TeachPosition_Request__Sequence * member =
    (matuska_interface__srv__TeachPosition_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void matuska_interface__srv__TeachPosition_Event__rosidl_typesupport_introspection_c__fetch_function__TeachPosition_Event__request(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const matuska_interface__srv__TeachPosition_Request * item =
    ((const matuska_interface__srv__TeachPosition_Request *)
    matuska_interface__srv__TeachPosition_Event__rosidl_typesupport_introspection_c__get_const_function__TeachPosition_Event__request(untyped_member, index));
  matuska_interface__srv__TeachPosition_Request * value =
    (matuska_interface__srv__TeachPosition_Request *)(untyped_value);
  *value = *item;
}

void matuska_interface__srv__TeachPosition_Event__rosidl_typesupport_introspection_c__assign_function__TeachPosition_Event__request(
  void * untyped_member, size_t index, const void * untyped_value)
{
  matuska_interface__srv__TeachPosition_Request * item =
    ((matuska_interface__srv__TeachPosition_Request *)
    matuska_interface__srv__TeachPosition_Event__rosidl_typesupport_introspection_c__get_function__TeachPosition_Event__request(untyped_member, index));
  const matuska_interface__srv__TeachPosition_Request * value =
    (const matuska_interface__srv__TeachPosition_Request *)(untyped_value);
  *item = *value;
}

bool matuska_interface__srv__TeachPosition_Event__rosidl_typesupport_introspection_c__resize_function__TeachPosition_Event__request(
  void * untyped_member, size_t size)
{
  matuska_interface__srv__TeachPosition_Request__Sequence * member =
    (matuska_interface__srv__TeachPosition_Request__Sequence *)(untyped_member);
  matuska_interface__srv__TeachPosition_Request__Sequence__fini(member);
  return matuska_interface__srv__TeachPosition_Request__Sequence__init(member, size);
}

size_t matuska_interface__srv__TeachPosition_Event__rosidl_typesupport_introspection_c__size_function__TeachPosition_Event__response(
  const void * untyped_member)
{
  const matuska_interface__srv__TeachPosition_Response__Sequence * member =
    (const matuska_interface__srv__TeachPosition_Response__Sequence *)(untyped_member);
  return member->size;
}

const void * matuska_interface__srv__TeachPosition_Event__rosidl_typesupport_introspection_c__get_const_function__TeachPosition_Event__response(
  const void * untyped_member, size_t index)
{
  const matuska_interface__srv__TeachPosition_Response__Sequence * member =
    (const matuska_interface__srv__TeachPosition_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void * matuska_interface__srv__TeachPosition_Event__rosidl_typesupport_introspection_c__get_function__TeachPosition_Event__response(
  void * untyped_member, size_t index)
{
  matuska_interface__srv__TeachPosition_Response__Sequence * member =
    (matuska_interface__srv__TeachPosition_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void matuska_interface__srv__TeachPosition_Event__rosidl_typesupport_introspection_c__fetch_function__TeachPosition_Event__response(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const matuska_interface__srv__TeachPosition_Response * item =
    ((const matuska_interface__srv__TeachPosition_Response *)
    matuska_interface__srv__TeachPosition_Event__rosidl_typesupport_introspection_c__get_const_function__TeachPosition_Event__response(untyped_member, index));
  matuska_interface__srv__TeachPosition_Response * value =
    (matuska_interface__srv__TeachPosition_Response *)(untyped_value);
  *value = *item;
}

void matuska_interface__srv__TeachPosition_Event__rosidl_typesupport_introspection_c__assign_function__TeachPosition_Event__response(
  void * untyped_member, size_t index, const void * untyped_value)
{
  matuska_interface__srv__TeachPosition_Response * item =
    ((matuska_interface__srv__TeachPosition_Response *)
    matuska_interface__srv__TeachPosition_Event__rosidl_typesupport_introspection_c__get_function__TeachPosition_Event__response(untyped_member, index));
  const matuska_interface__srv__TeachPosition_Response * value =
    (const matuska_interface__srv__TeachPosition_Response *)(untyped_value);
  *item = *value;
}

bool matuska_interface__srv__TeachPosition_Event__rosidl_typesupport_introspection_c__resize_function__TeachPosition_Event__response(
  void * untyped_member, size_t size)
{
  matuska_interface__srv__TeachPosition_Response__Sequence * member =
    (matuska_interface__srv__TeachPosition_Response__Sequence *)(untyped_member);
  matuska_interface__srv__TeachPosition_Response__Sequence__fini(member);
  return matuska_interface__srv__TeachPosition_Response__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember matuska_interface__srv__TeachPosition_Event__rosidl_typesupport_introspection_c__TeachPosition_Event_message_member_array[3] = {
  {
    "info",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(matuska_interface__srv__TeachPosition_Event, info),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "request",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(matuska_interface__srv__TeachPosition_Event, request),  // bytes offset in struct
    NULL,  // default value
    matuska_interface__srv__TeachPosition_Event__rosidl_typesupport_introspection_c__size_function__TeachPosition_Event__request,  // size() function pointer
    matuska_interface__srv__TeachPosition_Event__rosidl_typesupport_introspection_c__get_const_function__TeachPosition_Event__request,  // get_const(index) function pointer
    matuska_interface__srv__TeachPosition_Event__rosidl_typesupport_introspection_c__get_function__TeachPosition_Event__request,  // get(index) function pointer
    matuska_interface__srv__TeachPosition_Event__rosidl_typesupport_introspection_c__fetch_function__TeachPosition_Event__request,  // fetch(index, &value) function pointer
    matuska_interface__srv__TeachPosition_Event__rosidl_typesupport_introspection_c__assign_function__TeachPosition_Event__request,  // assign(index, value) function pointer
    matuska_interface__srv__TeachPosition_Event__rosidl_typesupport_introspection_c__resize_function__TeachPosition_Event__request  // resize(index) function pointer
  },
  {
    "response",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(matuska_interface__srv__TeachPosition_Event, response),  // bytes offset in struct
    NULL,  // default value
    matuska_interface__srv__TeachPosition_Event__rosidl_typesupport_introspection_c__size_function__TeachPosition_Event__response,  // size() function pointer
    matuska_interface__srv__TeachPosition_Event__rosidl_typesupport_introspection_c__get_const_function__TeachPosition_Event__response,  // get_const(index) function pointer
    matuska_interface__srv__TeachPosition_Event__rosidl_typesupport_introspection_c__get_function__TeachPosition_Event__response,  // get(index) function pointer
    matuska_interface__srv__TeachPosition_Event__rosidl_typesupport_introspection_c__fetch_function__TeachPosition_Event__response,  // fetch(index, &value) function pointer
    matuska_interface__srv__TeachPosition_Event__rosidl_typesupport_introspection_c__assign_function__TeachPosition_Event__response,  // assign(index, value) function pointer
    matuska_interface__srv__TeachPosition_Event__rosidl_typesupport_introspection_c__resize_function__TeachPosition_Event__response  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers matuska_interface__srv__TeachPosition_Event__rosidl_typesupport_introspection_c__TeachPosition_Event_message_members = {
  "matuska_interface__srv",  // message namespace
  "TeachPosition_Event",  // message name
  3,  // number of fields
  sizeof(matuska_interface__srv__TeachPosition_Event),
  false,  // has_any_key_member_
  matuska_interface__srv__TeachPosition_Event__rosidl_typesupport_introspection_c__TeachPosition_Event_message_member_array,  // message members
  matuska_interface__srv__TeachPosition_Event__rosidl_typesupport_introspection_c__TeachPosition_Event_init_function,  // function to initialize message memory (memory has to be allocated)
  matuska_interface__srv__TeachPosition_Event__rosidl_typesupport_introspection_c__TeachPosition_Event_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t matuska_interface__srv__TeachPosition_Event__rosidl_typesupport_introspection_c__TeachPosition_Event_message_type_support_handle = {
  0,
  &matuska_interface__srv__TeachPosition_Event__rosidl_typesupport_introspection_c__TeachPosition_Event_message_members,
  get_message_typesupport_handle_function,
  &matuska_interface__srv__TeachPosition_Event__get_type_hash,
  &matuska_interface__srv__TeachPosition_Event__get_type_description,
  &matuska_interface__srv__TeachPosition_Event__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_matuska_interface
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, matuska_interface, srv, TeachPosition_Event)() {
  matuska_interface__srv__TeachPosition_Event__rosidl_typesupport_introspection_c__TeachPosition_Event_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, service_msgs, msg, ServiceEventInfo)();
  matuska_interface__srv__TeachPosition_Event__rosidl_typesupport_introspection_c__TeachPosition_Event_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, matuska_interface, srv, TeachPosition_Request)();
  matuska_interface__srv__TeachPosition_Event__rosidl_typesupport_introspection_c__TeachPosition_Event_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, matuska_interface, srv, TeachPosition_Response)();
  if (!matuska_interface__srv__TeachPosition_Event__rosidl_typesupport_introspection_c__TeachPosition_Event_message_type_support_handle.typesupport_identifier) {
    matuska_interface__srv__TeachPosition_Event__rosidl_typesupport_introspection_c__TeachPosition_Event_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &matuska_interface__srv__TeachPosition_Event__rosidl_typesupport_introspection_c__TeachPosition_Event_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "matuska_interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "matuska_interface/srv/detail/teach_position__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers matuska_interface__srv__detail__teach_position__rosidl_typesupport_introspection_c__TeachPosition_service_members = {
  "matuska_interface__srv",  // service namespace
  "TeachPosition",  // service name
  // the following fields are initialized below on first access
  NULL,  // request message
  // matuska_interface__srv__detail__teach_position__rosidl_typesupport_introspection_c__TeachPosition_Request_message_type_support_handle,
  NULL,  // response message
  // matuska_interface__srv__detail__teach_position__rosidl_typesupport_introspection_c__TeachPosition_Response_message_type_support_handle
  NULL  // event_message
  // matuska_interface__srv__detail__teach_position__rosidl_typesupport_introspection_c__TeachPosition_Response_message_type_support_handle
};


static rosidl_service_type_support_t matuska_interface__srv__detail__teach_position__rosidl_typesupport_introspection_c__TeachPosition_service_type_support_handle = {
  0,
  &matuska_interface__srv__detail__teach_position__rosidl_typesupport_introspection_c__TeachPosition_service_members,
  get_service_typesupport_handle_function,
  &matuska_interface__srv__TeachPosition_Request__rosidl_typesupport_introspection_c__TeachPosition_Request_message_type_support_handle,
  &matuska_interface__srv__TeachPosition_Response__rosidl_typesupport_introspection_c__TeachPosition_Response_message_type_support_handle,
  &matuska_interface__srv__TeachPosition_Event__rosidl_typesupport_introspection_c__TeachPosition_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    matuska_interface,
    srv,
    TeachPosition
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    matuska_interface,
    srv,
    TeachPosition
  ),
  &matuska_interface__srv__TeachPosition__get_type_hash,
  &matuska_interface__srv__TeachPosition__get_type_description,
  &matuska_interface__srv__TeachPosition__get_type_description_sources,
};

// Forward declaration of message type support functions for service members
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, matuska_interface, srv, TeachPosition_Request)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, matuska_interface, srv, TeachPosition_Response)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, matuska_interface, srv, TeachPosition_Event)(void);

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_matuska_interface
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, matuska_interface, srv, TeachPosition)(void) {
  if (!matuska_interface__srv__detail__teach_position__rosidl_typesupport_introspection_c__TeachPosition_service_type_support_handle.typesupport_identifier) {
    matuska_interface__srv__detail__teach_position__rosidl_typesupport_introspection_c__TeachPosition_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)matuska_interface__srv__detail__teach_position__rosidl_typesupport_introspection_c__TeachPosition_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, matuska_interface, srv, TeachPosition_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, matuska_interface, srv, TeachPosition_Response)()->data;
  }
  if (!service_members->event_members_) {
    service_members->event_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, matuska_interface, srv, TeachPosition_Event)()->data;
  }

  return &matuska_interface__srv__detail__teach_position__rosidl_typesupport_introspection_c__TeachPosition_service_type_support_handle;
}
