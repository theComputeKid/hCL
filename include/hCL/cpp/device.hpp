/**
 * @file device.hpp
 *
 * @brief C++ Device API for hCL.
 *
 * @version 0.1
 * @date 2022-09-05
 */
#pragma once
#include <array>
#include <cstddef>
#include <string>
#include <utility>

#include <hCL/c/device.h>
#include <hCL/c/environment.h>

#include <hCL/cpp/dataTypes.hpp>

namespace hCL
{
  /** @brief Device type. */
  enum struct DeviceType
  {
    CPU,
    GPU
  };

  /** @brief Device properties. */
  struct Device
  {
    /** @brief Private members come first so ptr gets initialised first. */
  private:
    /** @brief Underlying implementation pointer. */
    hCLDevicePtr ptr;

    /** @brief Initialise device. */
    Device(std::size_t const index, hCLEnvironmentPtr const env);

    /** @brief Only friends can access private parts. */
    friend struct Environment;

  public:
    /** @brief Device ID reported by the mewSYCL backend runtime. */
    std::size_t const index;

    /** @brief Device name reported by the backend runtime. */
    std::string const name;

    /** @brief Type of the device. */
    DeviceType const type;

    /** @brief Total global memory of the device. */
    std::size_t const totalGlobalMemory;

    /** @brief Maximum single allocation size allowed on the device. */
    std::size_t const maxSingleAllocationSize;

    /** @brief The data types that the device supports natively. */
    std::array<std::pair<DataType, bool>, static_cast<std::size_t>(DataType::UNKNOWN)> const supportedDataTypes;

    /** @brief Check if data type is supported by device. */
    bool checkDataTypeSupport(DataType const dt) const;

    /** @brief Destroy device. */
    ~Device();

    /** @brief Get pointer to the actual backend device. Reinterpret cast to use. */
    void* getDevicePtr() const;
  };
} // namespace hCL

#include <hCL/wrapper/device.hpp>
