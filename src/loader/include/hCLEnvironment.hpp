/**
 * @file environment.hpp
 *
 * @brief Dynamic Loading of the backend librarie
 *
 * @version 0.1
 * @date 2022-09-06
 */
#include <functional>
#include <vector>

#include "hCL/c/environment.h"
#include "hCL/c/module.h"

/** @brief Dynamically loads the environment. */
struct hCLEnvironment
{
  /** @brief Handle to backend library. */
  std::unique_ptr<void, std::function<void(void*)>> libraryHandle;

  /** @brief Get the name of the environment. NULL terminated. */
  std::function<char*()> getName;

  /** @brief Destroy the name of the environment. Sets to NULL for safety. */
  std::function<void(char**)> destroyName;

  /** @brief Initialise environment. */
  std::function<hCLEnvironmentPtr()> create;

  /** @brief Destroy environment. Sets ptr to NULL for safety. */
  std::function<void(hCLEnvironmentPtr*)> destroy;

  /** @brief Get the number of devices recognised by the environment. */
  std::function<size_t(hCLEnvironmentPtr)> getNumDevices;

private:
  /** @brief Constructor. */
  hCLEnvironment(std::unique_ptr<void, std::function<void(void*)>> libHandle);

  /** @brief Only friends can access private parts. */
  friend struct hCLModule;
};
