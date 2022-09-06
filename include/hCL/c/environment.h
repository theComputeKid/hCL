/**
 * @file environment.h
 *
 * @brief C Environment API for hCL.
 *
 * @version 0.1
 * @date 2022-09-05
 */
#pragma once
#include <stddef.h>

#include <hCL/c/export.h>

typedef struct hCLEnvironment* hCLEnvironmentPtr;

/** @brief Get the name of the environment. NULL terminated. */
hCL_LINKAGE char* hCL_environment_get_name();

/** @brief Destroy the name of the environment. Sets to NULL for safety. */
hCL_LINKAGE void hCL_environment_destroy_name(char** name);

/** @brief Initialise environment. */
hCL_LINKAGE hCLEnvironmentPtr hCL_environment_create();

/** @brief Destroy environment. Sets ptr to NULL for safety. */
hCL_LINKAGE void hCL_environment_destroy(hCLEnvironmentPtr* ptr);

/** @brief Get the number of devices recognised by the environment. */
hCL_LINKAGE size_t hCL_environment_get_num_devices(hCLEnvironmentPtr const ptr);
