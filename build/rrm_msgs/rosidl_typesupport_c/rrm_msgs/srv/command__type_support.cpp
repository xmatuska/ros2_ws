// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from rrm_msgs:srv/Command.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rrm_msgs/srv/detail/command__struct.h"
#include "rrm_msgs/srv/detail/command__type_support.h"
#include "rrm_msgs/srv/detail/command__functions.h"
#include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/message_type_support_dispatch.h"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_c/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace rrm_msgs
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _Command_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Command_Request_type_support_ids_t;

static const _Command_Request_type_support_ids_t _Command_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _Command_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Command_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Command_Request_type_support_symbol_names_t _Command_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, rrm_msgs, srv, Command_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rrm_msgs, srv, Command_Request)),
  }
};

typedef struct _Command_Request_type_support_data_t
{
  void * data[2];
} _Command_Request_type_support_data_t;

static _Command_Request_type_support_data_t _Command_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Command_Request_message_typesupport_map = {
  2,
  "rrm_msgs",
  &_Command_Request_message_typesupport_ids.typesupport_identifier[0],
  &_Command_Request_message_typesupport_symbol_names.symbol_name[0],
  &_Command_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Command_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Command_Request_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &rrm_msgs__srv__Command_Request__get_type_hash,
  &rrm_msgs__srv__Command_Request__get_type_description,
  &rrm_msgs__srv__Command_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace rrm_msgs

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, rrm_msgs, srv, Command_Request)() {
  return &::rrm_msgs::srv::rosidl_typesupport_c::Command_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rrm_msgs/srv/detail/command__struct.h"
// already included above
// #include "rrm_msgs/srv/detail/command__type_support.h"
// already included above
// #include "rrm_msgs/srv/detail/command__functions.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace rrm_msgs
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _Command_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Command_Response_type_support_ids_t;

static const _Command_Response_type_support_ids_t _Command_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _Command_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Command_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Command_Response_type_support_symbol_names_t _Command_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, rrm_msgs, srv, Command_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rrm_msgs, srv, Command_Response)),
  }
};

typedef struct _Command_Response_type_support_data_t
{
  void * data[2];
} _Command_Response_type_support_data_t;

static _Command_Response_type_support_data_t _Command_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Command_Response_message_typesupport_map = {
  2,
  "rrm_msgs",
  &_Command_Response_message_typesupport_ids.typesupport_identifier[0],
  &_Command_Response_message_typesupport_symbol_names.symbol_name[0],
  &_Command_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Command_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Command_Response_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &rrm_msgs__srv__Command_Response__get_type_hash,
  &rrm_msgs__srv__Command_Response__get_type_description,
  &rrm_msgs__srv__Command_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace rrm_msgs

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, rrm_msgs, srv, Command_Response)() {
  return &::rrm_msgs::srv::rosidl_typesupport_c::Command_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rrm_msgs/srv/detail/command__struct.h"
// already included above
// #include "rrm_msgs/srv/detail/command__type_support.h"
// already included above
// #include "rrm_msgs/srv/detail/command__functions.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace rrm_msgs
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _Command_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Command_Event_type_support_ids_t;

static const _Command_Event_type_support_ids_t _Command_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _Command_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Command_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Command_Event_type_support_symbol_names_t _Command_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, rrm_msgs, srv, Command_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rrm_msgs, srv, Command_Event)),
  }
};

typedef struct _Command_Event_type_support_data_t
{
  void * data[2];
} _Command_Event_type_support_data_t;

static _Command_Event_type_support_data_t _Command_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Command_Event_message_typesupport_map = {
  2,
  "rrm_msgs",
  &_Command_Event_message_typesupport_ids.typesupport_identifier[0],
  &_Command_Event_message_typesupport_symbol_names.symbol_name[0],
  &_Command_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Command_Event_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Command_Event_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &rrm_msgs__srv__Command_Event__get_type_hash,
  &rrm_msgs__srv__Command_Event__get_type_description,
  &rrm_msgs__srv__Command_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace rrm_msgs

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, rrm_msgs, srv, Command_Event)() {
  return &::rrm_msgs::srv::rosidl_typesupport_c::Command_Event_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "rrm_msgs/srv/detail/command__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/service_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
#include "service_msgs/msg/service_event_info.h"
#include "builtin_interfaces/msg/time.h"

namespace rrm_msgs
{

namespace srv
{

namespace rosidl_typesupport_c
{
typedef struct _Command_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Command_type_support_ids_t;

static const _Command_type_support_ids_t _Command_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _Command_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Command_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Command_type_support_symbol_names_t _Command_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, rrm_msgs, srv, Command)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rrm_msgs, srv, Command)),
  }
};

typedef struct _Command_type_support_data_t
{
  void * data[2];
} _Command_type_support_data_t;

static _Command_type_support_data_t _Command_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Command_service_typesupport_map = {
  2,
  "rrm_msgs",
  &_Command_service_typesupport_ids.typesupport_identifier[0],
  &_Command_service_typesupport_symbol_names.symbol_name[0],
  &_Command_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t Command_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Command_service_typesupport_map),
  rosidl_typesupport_c__get_service_typesupport_handle_function,
  &Command_Request_message_type_support_handle,
  &Command_Response_message_type_support_handle,
  &Command_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    rrm_msgs,
    srv,
    Command
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    rrm_msgs,
    srv,
    Command
  ),
  &rrm_msgs__srv__Command__get_type_hash,
  &rrm_msgs__srv__Command__get_type_description,
  &rrm_msgs__srv__Command__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace rrm_msgs

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, rrm_msgs, srv, Command)() {
  return &::rrm_msgs::srv::rosidl_typesupport_c::Command_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif
