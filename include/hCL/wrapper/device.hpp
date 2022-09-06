/**
 * @file device.hpp
 *
 * @brief
 *
 * @version 0.1
 * @date 2022-09-05
 */
#pragma once
#include <cstddef>
#include <string>

#include <hCL/cpp/device.hpp>

namespace
{
  /** @brief Gets the name of the device, and cleans up pointers afterwards. */
  std::string iGetName(hCLDevicePtr const ptr)
  {
    auto charDeleter = [](auto& p) { hCL_device_destroy_name(&p); };
    auto name = std::unique_ptr<char, decltype(charDeleter)>(hCL_device_get_name(ptr), charDeleter);
    return name.get();
  }

  /** @brief Gets the supported data types. */
  std::array<std::pair<hCL::DataType, bool>, static_cast<std::size_t>(hCL::DataType::UNKNOWN)>
  iGetSupportedDataType(hCLDevicePtr const ptr)
  {
    return {std::make_pair(hCL::DataType::HALF, hCL_device_get_fp16_support(ptr)),
            std::make_pair(hCL::DataType::FLOAT, hCL_device_get_fp32_support(ptr)),
            std::make_pair(hCL::DataType::DOUBLE, hCL_device_get_fp64_support(ptr))};
  }
} // namespace

hCL::Device::Device(std::size_t const index, hCLEnvironmentPtr const env) :
    ptr(hCL_device_get(index, env)),
    index(index),
    name(iGetName(this->ptr)),
    type(static_cast<hCL::DeviceType>(hCL_device_get_type(this->ptr))),
    totalGlobalMemory(hCL_device_get_total_global_memory(this->ptr)),
    maxSingleAllocationSize(hCL_device_get_max_single_alloc_size(this->ptr)),
    supportedDataTypes(iGetSupportedDataType(this->ptr))
{
}

bool hCL::Device::checkDataTypeSupport(hCL::DataType const dt) const
{
  std::size_t const index = static_cast<std::size_t>(dt);
  return supportedDataTypes[index].second;
}

void* hCL::Device::getDevicePtr() const
{
  return hCL_device_get_raw_ptr(this->ptr);
}
