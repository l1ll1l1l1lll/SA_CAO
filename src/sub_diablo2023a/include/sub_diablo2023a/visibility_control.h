#ifndef SUB_DIABLO2023A__VISIBILITY_CONTROL_H_
#define SUB_DIABLO2023A__VISIBILITY_CONTROL_H_
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define SUB_DIABLO2023A_EXPORT __attribute__ ((dllexport))
    #define SUB_DIABLO2023A_IMPORT __attribute__ ((dllimport))
  #else
    #define SUB_DIABLO2023A_EXPORT __declspec(dllexport)
    #define SUB_DIABLO2023A_IMPORT __declspec(dllimport)
  #endif
  #ifdef SUB_DIABLO2023A_BUILDING_LIBRARY
    #define SUB_DIABLO2023A_PUBLIC SUB_DIABLO2023A_EXPORT
  #else
    #define SUB_DIABLO2023A_PUBLIC SUB_DIABLO2023A_IMPORT
  #endif
  #define SUB_DIABLO2023A_PUBLIC_TYPE SUB_DIABLO2023A_PUBLIC
  #define SUB_DIABLO2023A_LOCAL
#else
  #define SUB_DIABLO2023A_EXPORT __attribute__ ((visibility("default")))
  #define SUB_DIABLO2023A_IMPORT
  #if __GNUC__ >= 4
    #define SUB_DIABLO2023A_PUBLIC __attribute__ ((visibility("default")))
    #define SUB_DIABLO2023A_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define SUB_DIABLO2023A_PUBLIC
    #define SUB_DIABLO2023A_LOCAL
  #endif
  #define SUB_DIABLO2023A_PUBLIC_TYPE
#endif
#endif  // SUB_DIABLO2023A__VISIBILITY_CONTROL_H_
// Generated 18-Mar-2025 14:57:34
 