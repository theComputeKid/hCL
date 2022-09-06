/**
 * @file module.h
 *
 * @brief C module API for hCL. Only to be implemented by the hCL loader.
 *
 * @version 0.1
 * @date 2022-09-05
 */
#pragma once
#include <stddef.h>

#include <hCL/c/environment.h>
#include <hCL/c/export.h>

typedef struct hCLModule* hCLModulePtr;

/** @brief Initialise module. */
hCL_LINKAGE hCLModulePtr hCL_module_create();

/** @brief Destroy module. Sets ptr to NULL for safety. */
hCL_LINKAGE void hCL_module_destroy(hCLModulePtr* m);

/** @brief Get the number of environments recognised by the module. */
hCL_LINKAGE size_t hCL_module_get_num_environments(hCLModulePtr const m);

/** @brief Get the name of en environment. */
hCL_LINKAGE char* hCL_module_get_environment_name(size_t const index, hCLModulePtr const m);

/** @brief Destroy the name of en environment. */
hCL_LINKAGE void hCL_module_destroy_environment_name(char** name, size_t const index, hCLModulePtr const m);

/** @brief Get the number of environments recognised by the module. */
hCL_LINKAGE hCLEnvironmentPtr hCL_module_get_environment(size_t const index, hCLModulePtr const m);
