/**
 * @file pch.hpp
 *
 * @brief Precompiled header file.
 *
 * @author theComputeKid
 * @version 0.1
 * @date 2022-09-03
 */

/**
 * @brief We can not use pragma once for precompiled headers because it emits a warning when used with GCC.
 *
 * GCC bug: https://gcc.gnu.org/bugzilla/show_bug.cgi?id=47857
 * https://stackoverflow.com/questions/56563679/gcc-precompiled-header-pragma-once-in-main-file
 */

#ifndef hCL_PCH_INCLUDE
#define hCL_PCH_INCLUDE

// Standard library
#include <cstddef>
#include <dlfcn.h>
#include <iostream>
#include <memory>
#include <vector>
#endif
