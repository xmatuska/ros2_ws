# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_block2_matuska_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED block2_matuska_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(block2_matuska_FOUND FALSE)
  elseif(NOT block2_matuska_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(block2_matuska_FOUND FALSE)
  endif()
  return()
endif()
set(_block2_matuska_CONFIG_INCLUDED TRUE)

# output package information
if(NOT block2_matuska_FIND_QUIETLY)
  message(STATUS "Found block2_matuska: 0.0.0 (${block2_matuska_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'block2_matuska' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT block2_matuska_DEPRECATED_QUIET)
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(block2_matuska_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${block2_matuska_DIR}/${_extra}")
endforeach()
