/**
 * @file module.cpp
 *
 * @brief C module API for hCL.
 *
 * @version 0.1
 * @date 2022-09-06
 */
#include "pch.hpp"

#include "hCLModule.hpp"

/** @brief Initialise module. */
hCLModulePtr hCL_module_create()
{
  return new hCLModule();
}

/** @brief Destroy module. Sets ptr to NULL for safety. */
void hCL_module_destroy(hCLModulePtr* m)
{
  delete *m;
  *m = nullptr;
}

/** @brief Get the number of environments recognised by the module. */
size_t hCL_module_get_num_environments(hCLModulePtr const m)
{
  return m->envs.size();
}

/** @brief Get the name of en environment. */
char* hCL_module_get_environment_name(size_t const index, hCLModulePtr const m)
{
  return m->envs[index].getName();
}

/** @brief Destroy the name of en environment. */
void hCL_module_destroy_environment_name(char** name, size_t const index, hCLModulePtr const m)
{
  return m->envs[index].destroyName(name);
}

/** @brief Get a particular environment recognised by the module. */
hCLEnvironmentPtr hCL_module_get_environment(size_t const index, hCLModulePtr const m)
{
  return m->envs[index].create();
}

namespace
{
  std::function<void(void*)> iHandleCloser = [](void* l)
  {
    if (l)
    {
#ifndef _WIN32
      dlclose(l);
#endif
    }
  };

  void* iHandleOpener(std::string const& p)
  {
#ifndef _WIN32
    return dlopen(p.c_str(), RTLD_NOW);
#endif
  };

} // namespace

/** @brief Constructor. */
hCLModule::hCLModule()
{
  // Holder for all library handles.
  std::vector<std::string> pluginPaths;

  // For Apple, we only load the cpu and metal plugin.
#ifdef __APPLE__
  pluginPaths.push_back("libhCL-metal.so");
  pluginPaths.push_back("libhCL-cpu.so");
#endif

  // Try to load each plugin.
  for (auto const& p : pluginPaths)
  {
    auto handle = std::unique_ptr<void, std::function<void(void*)>>(iHandleOpener(p), iHandleCloser);
    if (handle.get())
    {
      envs.push_back(std::move(handle));
    }
    else
    {
      std::cerr << "Unable to load: " << p << std::endl;
    }
  }
}
