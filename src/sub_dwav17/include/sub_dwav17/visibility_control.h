#ifndef SUB_DWAV17__VISIBILITY_CONTROL_H_
#define SUB_DWAV17__VISIBILITY_CONTROL_H_
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define SUB_DWAV17_EXPORT __attribute__ ((dllexport))
    #define SUB_DWAV17_IMPORT __attribute__ ((dllimport))
  #else
    #define SUB_DWAV17_EXPORT __declspec(dllexport)
    #define SUB_DWAV17_IMPORT __declspec(dllimport)
  #endif
  #ifdef SUB_DWAV17_BUILDING_LIBRARY
    #define SUB_DWAV17_PUBLIC SUB_DWAV17_EXPORT
  #else
    #define SUB_DWAV17_PUBLIC SUB_DWAV17_IMPORT
  #endif
  #define SUB_DWAV17_PUBLIC_TYPE SUB_DWAV17_PUBLIC
  #define SUB_DWAV17_LOCAL
#else
  #define SUB_DWAV17_EXPORT __attribute__ ((visibility("default")))
  #define SUB_DWAV17_IMPORT
  #if __GNUC__ >= 4
    #define SUB_DWAV17_PUBLIC __attribute__ ((visibility("default")))
    #define SUB_DWAV17_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define SUB_DWAV17_PUBLIC
    #define SUB_DWAV17_LOCAL
  #endif
  #define SUB_DWAV17_PUBLIC_TYPE
#endif
#endif  // SUB_DWAV17__VISIBILITY_CONTROL_H_
// Generated 29-May-2025 03:31:41
 