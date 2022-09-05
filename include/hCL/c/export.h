/**
 * @file export.h
 *
 * @brief C linkage import and export macros for convenience.
 *
 * @version 0.1
 * @date 2022-09-05
 */
#pragma once

#ifdef __cplusplus
#  define hCL_EXTERN_C extern "C"
#endif

#ifdef _WIN32
#  ifdef hCL_EXPORT_API
#    define hCL_LINKAGE hCL_EXTERN_C __declspec(dllexport)
#  else
#    define hCL_LINKAGE hCL_EXTERN_C __declspec(dllimport)
#  endif
#else
#  define hCL_LINKAGE hCL_EXTERN_C __attribute__((visibility("default")))
#endif
