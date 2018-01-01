
#ifndef LIB_EXT_SHARED_EXPORT_H
#define LIB_EXT_SHARED_EXPORT_H

#ifdef LIB_EXT_BUILD_AS_STATIC
#  define LIB_EXT_SHARED_EXPORT
#  define LIB_EXT_SHARED_NO_EXPORT
#else
#  ifndef LIB_EXT_SHARED_EXPORT
#    ifdef lib_ext_shared_EXPORTS
        /* We are building this library */
#      define LIB_EXT_SHARED_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define LIB_EXT_SHARED_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef LIB_EXT_SHARED_NO_EXPORT
#    define LIB_EXT_SHARED_NO_EXPORT 
#  endif
#endif

#ifndef LIB_EXT_SHARED_DEPRECATED
#  define LIB_EXT_SHARED_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef LIB_EXT_SHARED_DEPRECATED_EXPORT
#  define LIB_EXT_SHARED_DEPRECATED_EXPORT LIB_EXT_SHARED_EXPORT LIB_EXT_SHARED_DEPRECATED
#endif

#ifndef LIB_EXT_SHARED_DEPRECATED_NO_EXPORT
#  define LIB_EXT_SHARED_DEPRECATED_NO_EXPORT LIB_EXT_SHARED_NO_EXPORT LIB_EXT_SHARED_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef LIB_EXT_SHARED_NO_DEPRECATED
#    define LIB_EXT_SHARED_NO_DEPRECATED
#  endif
#endif

#endif
