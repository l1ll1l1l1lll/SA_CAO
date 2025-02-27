# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_sub0227_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED sub0227_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(sub0227_FOUND FALSE)
  elseif(NOT sub0227_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(sub0227_FOUND FALSE)
  endif()
  return()
endif()
set(_sub0227_CONFIG_INCLUDED TRUE)

# output package information
if(NOT sub0227_FIND_QUIETLY)
  message(STATUS "Found sub0227: 1.0.0 (${sub0227_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'sub0227' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${sub0227_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(sub0227_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "ament_cmake_export_include_directories-extras.cmake")
foreach(_extra ${_extras})
  include("${sub0227_DIR}/${_extra}")
endforeach()
