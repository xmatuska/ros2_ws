// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from matuska_interface:srv/TeachPosition.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "matuska_interface/srv/detail/teach_position__functions.h"
#include "matuska_interface/srv/detail/teach_position__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace matuska_interface
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _TeachPosition_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _TeachPosition_Request_type_support_ids_t;

static const _TeachPosition_Request_type_support_ids_t _TeachPosition_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _TeachPosition_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _TeachPosition_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _TeachPosition_Request_type_support_symbol_names_t _TeachPosition_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, matuska_interface, srv, TeachPosition_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, matuska_interface, srv, TeachPosition_Request)),
  }
};

typedef struct _TeachPosition_Request_type_support_data_t
{
  void * data[2];
} _TeachPosition_Request_type_support_data_t;

static _TeachPosition_Request_type_support_data_t _TeachPosition_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _TeachPosition_Request_message_typesupport_map = {
  2,
  "matuska_interface",
  &_TeachPosition_Request_message_typesupport_ids.typesupport_identifier[0],
  &_TeachPosition_Request_message_typesupport_symbol_names.symbol_name[0],
  &_TeachPosition_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t TeachPosition_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_TeachPosition_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &matuska_interface__srv__TeachPosition_Request__get_type_hash,
  &matuska_interface__srv__TeachPosition_Request__get_type_description,
  &matuska_interface__srv__TeachPosition_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace matuska_interface

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<matuska_interface::srv::TeachPosition_Request>()
{
  return &::matuska_interface::srv::rosidl_typesupport_cpp::TeachPosition_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, matuska_interface, srv, TeachPosition_Request)() {
  return get_message_type_support_handle<matuska_interface::srv::TeachPosition_Request>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "matuska_interface/srv/detail/teach_position__functions.h"
// already included above
// #include "matuska_interface/srv/detail/teach_position__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace matuska_interface
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _TeachPosition_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _TeachPosition_Response_type_support_ids_t;

static const _TeachPosition_Response_type_support_ids_t _TeachPosition_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _TeachPosition_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _TeachPosition_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _TeachPosition_Response_type_support_symbol_names_t _TeachPosition_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, matuska_interface, srv, TeachPosition_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, matuska_interface, srv, TeachPosition_Response)),
  }
};

typedef struct _TeachPosition_Response_type_support_data_t
{
  void * data[2];
} _TeachPosition_Response_type_support_data_t;

static _TeachPosition_Response_type_support_data_t _TeachPosition_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _TeachPosition_Response_message_typesupport_map = {
  2,
  "matuska_interface",
  &_TeachPosition_Response_message_typesupport_ids.typesupport_identifier[0],
  &_TeachPosition_Response_message_typesupport_symbol_names.symbol_name[0],
  &_TeachPosition_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t TeachPosition_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_TeachPosition_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &matuska_interface__srv__TeachPosition_Response__get_type_hash,
  &matuska_interface__srv__TeachPosition_Response__get_type_description,
  &matuska_interface__srv__TeachPosition_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace matuska_interface

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<matuska_interface::srv::TeachPosition_Response>()
{
  return &::matuska_interface::srv::rosidl_typesupport_cpp::TeachPosition_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, matuska_interface, srv, TeachPosition_Response)() {
  return get_message_type_support_handle<matuska_interface::srv::TeachPosition_Response>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "matuska_interface/srv/detail/teach_position__functions.h"
// already included above
// #include "matuska_interface/srv/detail/teach_position__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace matuska_interface
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _TeachPosition_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _TeachPosition_Event_type_support_ids_t;

static const _TeachPosition_Event_type_support_ids_t _TeachPosition_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _TeachPosition_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _TeachPosition_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _TeachPosition_Event_type_support_symbol_names_t _TeachPosition_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, matuska_interface, srv, TeachPosition_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, matuska_interface, srv, TeachPosition_Event)),
  }
};

typedef struct _TeachPosition_Event_type_support_data_t
{
  void * data[2];
} _TeachPosition_Event_type_support_data_t;

static _TeachPosition_Event_type_support_data_t _TeachPosition_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _TeachPosition_Event_message_typesupport_map = {
  2,
  "matuska_interface",
  &_TeachPosition_Event_message_typesupport_ids.typesupport_identifier[0],
  &_TeachPosition_Event_message_typesupport_symbol_names.symbol_name[0],
  &_TeachPosition_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t TeachPosition_Event_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_TeachPosition_Event_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &matuska_interface__srv__TeachPosition_Event__get_type_hash,
  &matuska_interface__srv__TeachPosition_Event__get_type_description,
  &matuska_interface__srv__TeachPosition_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace matuska_interface

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<matuska_interface::srv::TeachPosition_Event>()
{
  return &::matuska_interface::srv::rosidl_typesupport_cpp::TeachPosition_Event_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, matuska_interface, srv, TeachPosition_Event)() {
  return get_message_type_support_handle<matuska_interface::srv::TeachPosition_Event>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "matuska_interface/srv/detail/teach_position__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace matuska_interface
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _TeachPosition_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _TeachPosition_type_support_ids_t;

static const _TeachPosition_type_support_ids_t _TeachPosition_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _TeachPosition_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _TeachPosition_type_support_symbol_names_t;
#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _TeachPosition_type_support_symbol_names_t _TeachPosition_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, matuska_interface, srv, TeachPosition)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, matuska_interface, srv, TeachPosition)),
  }
};

typedef struct _TeachPosition_type_support_data_t
{
  void * data[2];
} _TeachPosition_type_support_data_t;

static _TeachPosition_type_support_data_t _TeachPosition_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _TeachPosition_service_typesupport_map = {
  2,
  "matuska_interface",
  &_TeachPosition_service_typesupport_ids.typesupport_identifier[0],
  &_TeachPosition_service_typesupport_symbol_names.symbol_name[0],
  &_TeachPosition_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t TeachPosition_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_TeachPosition_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
  ::rosidl_typesupport_cpp::get_message_type_support_handle<matuska_interface::srv::TeachPosition_Request>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<matuska_interface::srv::TeachPosition_Response>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<matuska_interface::srv::TeachPosition_Event>(),
  &::rosidl_typesupport_cpp::service_create_event_message<matuska_interface::srv::TeachPosition>,
  &::rosidl_typesupport_cpp::service_destroy_event_message<matuska_interface::srv::TeachPosition>,
  &matuska_interface__srv__TeachPosition__get_type_hash,
  &matuska_interface__srv__TeachPosition__get_type_description,
  &matuska_interface__srv__TeachPosition__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace matuska_interface

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<matuska_interface::srv::TeachPosition>()
{
  return &::matuska_interface::srv::rosidl_typesupport_cpp::TeachPosition_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_cpp, matuska_interface, srv, TeachPosition)() {
  return ::rosidl_typesupport_cpp::get_service_type_support_handle<matuska_interface::srv::TeachPosition>();
}

#ifdef __cplusplus
}
#endif
