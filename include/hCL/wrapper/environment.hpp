/**
 * @file environment.hpp
 *
 * @brief Inline wrapper for C++ Environment API for hCL.
 *
 * @version 0.1
 * @date 2022-09-05
 */
#pragma once
#include <memory>

#include <hCL/c/environment.h>
#include <hCL/cpp/environment.hpp>

hCL::Environment::Environment() :
    ptr(hCL_environment_create())
{
}

hCL::Environment::~Environment()
{
  hCL_environment_destroy(&ptr);
}

std::unique_ptr<hCL::Environment> hCL::initEnvironment()
{
  return std::make_unique<hCL::Environment>(new hCL::Environment());
}
