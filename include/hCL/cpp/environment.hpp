/**
 * @file environment.hpp
 *
 * @brief C++ Environment API for hCL.
 *
 * @version 0.1
 * @date 2022-09-05
 */
#pragma once
#include <cstddef>
#include <memory>
#include <vector>

#include <hCL/c/environment.h>

namespace hCL
{
  struct Environment
  {
    /** @brief Destroy environment. */
    ~Environment();

  private:
    /** @brief Underlying implementation pointer. */
    hCLEnvironmentPtr ptr;

    /** @brief Initialise environment. */
    Environment();

    /** @brief Only friends can access private parts. */
    friend std::unique_ptr<Environment> initEnvironment();
  };

  /** @brief Initialise C++ environment. Cleans up on destruction. */
  std::unique_ptr<Environment> initEnvironment();
} // namespace hCL

#include <hCL/wrapper/environment.hpp>
