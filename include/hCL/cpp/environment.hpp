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
#include <hCL/cpp/backend.hpp>
#include <hCL/cpp/device.hpp>
#include <hCL/loader/environment.hpp>

namespace hCL
{
  struct Environment
  {
    /** @brief Private members come first so native library gets initialised first. */
  private:
    loader::Environment ld;

    /** @brief Initialise environment. */
    Environment();

    /** @brief Only friends can access private parts. */
    friend std::unique_ptr<Environment> initEnvironment(hCL::Backend const backend);

  public:
    /** @brief Destroy environment. */
    ~Environment();

    /** @brief Contains device information. */
    std::vector<Device> devices;

    hCL::Backend const backend;
  };

  /** @brief Initialise C++ environment. Cleans up on destruction. */
  std::unique_ptr<Environment> initEnvironment(hCL::Backend const backend);
} // namespace hCL

#include <hCL/wrapper/environment.hpp>
