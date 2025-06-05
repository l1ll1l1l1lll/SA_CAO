#ifndef SUB_DWAV18__VISIBILITY_CONTROL_H_
#define SUB_DWAV18__VISIBILITY_CONTROL_H_
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define SUB_DWAV18_EXPORT __attribute__ ((dllexport))
    #define SUB_DWAV18_IMPORT __attribute__ ((dllimport))
  #else
    #define SUB_DWAV18_EXPORT __declspec(dllexport)
    #define SUB_DWAV18_IMPORT __declspec(dllimport)
  #endif
  #ifdef SUB_DWAV18_BUILDING_LIBRARY
    #define SUB_DWAV18_PUBLIC SUB_DWAV18_EXPORT
  #else
    #define SUB_DWAV18_PUBLIC SUB_DWAV18_IMPORT
  #endif
  #define SUB_DWAV18_PUBLIC_TYPE SUB_DWAV18_PUBLIC
  #define SUB_DWAV18_LOCAL
#else
  #define SUB_DWAV18_EXPORT __attribute__ ((visibility("default")))
  #define SUB_DWAV18_IMPORT
  #if __GNUC__ >= 4
    #define SUB_DWAV18_PUBLIC __attribute__ ((visibility("default")))
    #define SUB_DWAV18_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define SUB_DWAV18_PUBLIC
    #define SUB_DWAV18_LOCAL
  #endif
  #define SUB_DWAV18_PUBLIC_TYPE
#endif
#endif  // SUB_DWAV18__VISIBILITY_CONTROL_H_
// Generated 05-Jun-2025 02:25:01
 