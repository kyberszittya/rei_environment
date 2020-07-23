#ifndef REI_NODE_LIBRARY__VISIBILITY_CONTROL_H_
#define REI_NODE_LIBRARY__VISIBILITY_CONTROL_H_

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define REI_NODE_LIBRARY_EXPORT __attribute__ ((dllexport))
    #define REI_NODE_LIBRARY_IMPORT __attribute__ ((dllimport))
  #else
    #define REI_NODE_LIBRARY_EXPORT __declspec(dllexport)
    #define REI_NODE_LIBRARY_IMPORT __declspec(dllimport)
  #endif
  #ifdef REI_NODE_LIBRARY_BUILDING_LIBRARY
    #define REI_NODE_LIBRARY_PUBLIC REI_NODE_LIBRARY_EXPORT
  #else
    #define REI_NODE_LIBRARY_PUBLIC REI_NODE_LIBRARY_IMPORT
  #endif
  #define REI_NODE_LIBRARY_PUBLIC_TYPE REI_NODE_LIBRARY_PUBLIC
  #define REI_NODE_LIBRARY_LOCAL
#else
  #define REI_NODE_LIBRARY_EXPORT __attribute__ ((visibility("default")))
  #define REI_NODE_LIBRARY_IMPORT
  #if __GNUC__ >= 4
    #define REI_NODE_LIBRARY_PUBLIC __attribute__ ((visibility("default")))
    #define REI_NODE_LIBRARY_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define REI_NODE_LIBRARY_PUBLIC
    #define REI_NODE_LIBRARY_LOCAL
  #endif
  #define REI_NODE_LIBRARY_PUBLIC_TYPE
#endif

#endif  // REI_NODE_LIBRARY__VISIBILITY_CONTROL_H_
