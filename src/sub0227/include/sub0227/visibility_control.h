#ifndef SUB0227__VISIBILITY_CONTROL_H_
#define SUB0227__VISIBILITY_CONTROL_H_
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define SUB0227_EXPORT __attribute__ ((dllexport))
    #define SUB0227_IMPORT __attribute__ ((dllimport))
  #else
    #define SUB0227_EXPORT __declspec(dllexport)
    #define SUB0227_IMPORT __declspec(dllimport)
  #endif
  #ifdef SUB0227_BUILDING_LIBRARY
    #define SUB0227_PUBLIC SUB0227_EXPORT
  #else
    #define SUB0227_PUBLIC SUB0227_IMPORT
  #endif
  #define SUB0227_PUBLIC_TYPE SUB0227_PUBLIC
  #define SUB0227_LOCAL
#else
  #define SUB0227_EXPORT __attribute__ ((visibility("default")))
  #define SUB0227_IMPORT
  #if __GNUC__ >= 4
    #define SUB0227_PUBLIC __attribute__ ((visibility("default")))
    #define SUB0227_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define SUB0227_PUBLIC
    #define SUB0227_LOCAL
  #endif
  #define SUB0227_PUBLIC_TYPE
#endif
#endif  // SUB0227__VISIBILITY_CONTROL_H_
// Generated 27-Feb-2025 09:58:52
 