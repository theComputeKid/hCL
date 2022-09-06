/**
 * @file module.hpp
 *
 * @brief Module API for the hCL loader.
 *
 * @version 0.1
 * @date 2022-09-06
 */
#pragma once
#include "pch.hpp"

#include "hCL/c/module.h"

#include "hCLEnvironment.hpp"

/** @brief Dynamically loads the environment. */
struct hCLModule
{
  /** @brief Holds all symbols in the backend libraries loaded. */
  std::vector<hCLEnvironment> envs;

private:
  /** @brief Constructor. */
  hCLModule();

  /** @brief Disable copy constructor. */
  hCLModule(hCLModule const&) = delete;

  /** @brief Disable assignment. */
  hCLModule& operator=(hCLModule const&) = delete;

  /** @brief Disable moves initialisation. */
  hCLModule(hCLModule&&) = delete;

  /** @brief Disable move assignment. */
  hCLModule& operator=(hCLModule&&) = delete;

  /** @brief Only friends can access private parts. */
  friend hCLModulePtr hCL_module_create();
};
