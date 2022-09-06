/**
 * @file environment.hpp
 *
 * @brief Inline wrapper for C++ Environment API for hCL.
 *
 * @version 0.1
 * @date 2022-09-05
 */
#pragma once
#include <dlfcn.h>
#include <filesystem>
#include <iostream>
#include <memory>

#include <hCL/c/environment.h>
#include <hCL/cpp/backend.hpp>
#include <hCL/cpp/environment.hpp>

hCL::Environment::Environment() :
    backend(backend),
    ptr(hCL_environment_create())
{
}

hCL::Environment::~Environment()
{
  hCL_environment_destroy(&ptr);
}

std::unique_ptr<hCL::Environment> hCL::initEnvironment(hCL::Backend const backend)
{
  auto const exePath = std::filesystem::canonical("/proc/self/exe");
  auto const metalPlugin = exePath / "libhCL-metal.so";
  void* libHandle;
  if (backend == hCL::Backend::Metal)
  {
    libHandle = dlopen(metalPlugin.c_str(), RTLD_LAZY);
  }
  if (!libHandle)
  {
    std::cerr << "Cannot open library: " << dlerror() << '\n';
    return;
  }

  return std::make_unique<hCL::Environment>(new hCL::Environment());
}
