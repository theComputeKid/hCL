/**
 * @file environment.cpp
 *
 * @brief
 *
 * @version 0.1
 * @date 2022-09-05
 */
#include "pch.hpp"

#include <hCL/c/environment.h>

#include "hCLEnvironment.hpp"

hCLEnvironment::hCLEnvironment(std::unique_ptr<void, std::function<void(void*)>> libHandle) :
    libraryHandle(std::move(libHandle))
{
}
