#ifndef SUB_DWA__VISIBILITY_CONTROL_H_
#define SUB_DWA__VISIBILITY_CONTROL_H_
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define SUB_DWA_EXPORT __attribute__ ((dllexport))
    #define SUB_DWA_IMPORT __attribute__ ((dllimport))
  #else
    #define SUB_DWA_EXPORT __declspec(dllexport)
    #define SUB_DWA_IMPORT __declspec(dllimport)
  #endif
  #ifdef SUB_DWA_BUILDING_LIBRARY
    #define SUB_DWA_PUBLIC SUB_DWA_EXPORT
  #else
    #define SUB_DWA_PUBLIC SUB_DWA_IMPORT
  #endif
  #define SUB_DWA_PUBLIC_TYPE SUB_DWA_PUBLIC
  #define SUB_DWA_LOCAL
#else
  #define SUB_DWA_EXPORT __attribute__ ((visibility("default")))
  #define SUB_DWA_IMPORT
  #if __GNUC__ >= 4
    #define SUB_DWA_PUBLIC __attribute__ ((visibility("default")))
    #define SUB_DWA_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define SUB_DWA_PUBLIC
    #define SUB_DWA_LOCAL
  #endif
  #define SUB_DWA_PUBLIC_TYPE
#endif
#endif  // SUB_DWA__VISIBILITY_CONTROL_H_
// Generated 05-May-2025 23:17:12
 