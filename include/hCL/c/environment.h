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

/** @brief Initialise environment. */
hCL_LINKAGE hCLEnvironmentPtr hCL_environment_create();

/** @brief Destroy environment. Sets ptr to NULL for safety. */
hCL_LINKAGE void hCL_environment_destroy(hCLEnvironmentPtr* ptr);

/** @brief Get the number of devices recognised by the environment. */
hCL_LINKAGE size_t hCL_environment_get_num_devices(hCLEnvironmentPtr const ptr);
