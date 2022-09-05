/**
 * @file environment.hpp
 *
 * @brief C++ Environment API for hCL.
 *
 * @version 0.1
 * @date 2022-09-05
 */
#pragma once
#include <memory>
#include <vector>

#include <hCL/c/environment.h>
#include <hCL/cpp/device.hpp>

namespace hCL
{
  struct Environment
  {
    /** @brief Private members come first so ptr gets initialised first. */
  private:
    /** @brief Underlying implementation pointer. */
    hCLEnvironmentPtr ptr;

    /** @brief Initialise environment. */
    Environment();

    /** @brief Only friends can access private parts. */
    friend std::unique_ptr<Environment> initEnvironment();

  public:
    /** @brief Destroy environment. */
    ~Environment();

    /** @brief Contains device information. */
    std::vector<Device> devices;
  };

  /** @brief Initialise C++ environment. Cleans up on destruction. */
  std::unique_ptr<Environment> initEnvironment();
} // namespace hCL

#include <hCL/wrapper/environment.hpp>
