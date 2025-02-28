#ifndef SUB_DIABLO__VISIBILITY_CONTROL_H_
#define SUB_DIABLO__VISIBILITY_CONTROL_H_
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define SUB_DIABLO_EXPORT __attribute__ ((dllexport))
    #define SUB_DIABLO_IMPORT __attribute__ ((dllimport))
  #else
    #define SUB_DIABLO_EXPORT __declspec(dllexport)
    #define SUB_DIABLO_IMPORT __declspec(dllimport)
  #endif
  #ifdef SUB_DIABLO_BUILDING_LIBRARY
    #define SUB_DIABLO_PUBLIC SUB_DIABLO_EXPORT
  #else
    #define SUB_DIABLO_PUBLIC SUB_DIABLO_IMPORT
  #endif
  #define SUB_DIABLO_PUBLIC_TYPE SUB_DIABLO_PUBLIC
  #define SUB_DIABLO_LOCAL
#else
  #define SUB_DIABLO_EXPORT __attribute__ ((visibility("default")))
  #define SUB_DIABLO_IMPORT
  #if __GNUC__ >= 4
    #define SUB_DIABLO_PUBLIC __attribute__ ((visibility("default")))
    #define SUB_DIABLO_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define SUB_DIABLO_PUBLIC
    #define SUB_DIABLO_LOCAL
  #endif
  #define SUB_DIABLO_PUBLIC_TYPE
#endif
#endif  // SUB_DIABLO__VISIBILITY_CONTROL_H_
// Generated 27-Feb-2025 22:54:30
 