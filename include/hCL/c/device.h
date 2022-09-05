/**
 * @file device.h
 *
 * @brief C Device API for hCL.
 *
 * @version 0.1
 * @date 2022-09-05
 */
#pragma once
#include <cstddef>
#include <hCL/c/environment.h>
#include <hCL/c/export.h>

typedef struct hCLDevice* hCLDevicePtr;

/** @brief Describes the type of device. */
typedef enum hCLDeviceType
{
  hCLDeviceTypeCPU, // CPU device (accelerated via OpenMP)
  hCLDeviceTypeGPU  // GPU device
} hCLDeviceType;

/** @brief Get devices recognised by the environment. */
hCL_LINKAGE hCLDevicePtr hCL_device_get(size_t const index, hCLEnvironmentPtr const env);

/** @brief Get device index. */
hCL_LINKAGE std::size_t hCL_device_get_index(hCLDevicePtr const dev);

/** @brief Get device name. */
hCL_LINKAGE char* hCL_device_get_name(hCLDevicePtr const dev);

/** @brief Get device name. */
hCL_LINKAGE void hCL_device_destroy_name(char** name);

/** @brief Get device type. */
hCL_LINKAGE hCLDeviceType hCL_device_get_type(hCLDevicePtr const dev);

/** @brief Get device total global memory. */
hCL_LINKAGE std::size_t hCL_device_get_total_global_memory(hCLDevicePtr const dev);

/** @brief Get device maximum single allocation size. */
hCL_LINKAGE std::size_t hCL_device_get_max_single_alloc_size(hCLDevicePtr const dev);

/** @brief Does the device support fp16? */
hCL_LINKAGE bool hCL_device_get_fp16_support(hCLDevicePtr const dev);

/** @brief Does the device support fp32? */
hCL_LINKAGE bool hCL_device_get_fp32_support(hCLDevicePtr const dev);

/** @brief Does the device support fp64? */
hCL_LINKAGE bool hCL_device_get_fp64_support(hCLDevicePtr const dev);

/** @brief Return the raw backend device. Reinterpret to native type to use. */
hCL_LINKAGE void* hCL_device_get_raw_ptr(hCLDevicePtr const dev);

/** @brief Deallocate memory for the devices struct. */
hCL_LINKAGE void hCL_device_destroy(hCLDevicePtr const** env);
