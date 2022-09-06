/**
 * @file module.cpp
 *
 * @brief Tests the module API.
 *
 * @version 0.1
 * @date 2022-09-06
 */
#include "pch.hpp"

#include <hCL/c/module.h>

#define TestSuiteName hCLModule

/** @brief Check if module sets up correctly. */
TEST(TestSuiteName, create)
{
  auto m = hCL_module_create();
  ASSERT_TRUE(m != nullptr);
  hCL_module_destroy(&m);
}

/** @brief Check if module destroys correctly. */
TEST(TestSuiteName, destroy)
{
  auto m = hCL_module_create();
  ASSERT_TRUE(m != nullptr);
  hCL_module_destroy(&m);
  ASSERT_TRUE(m == nullptr);
}

/** @brief Check if the machine has valid recognised environments. Pointless to continue otherwise. */
TEST(TestSuiteName, getNumEnvironments)
{
  auto m = hCL_module_create();
  ASSERT_TRUE(m != nullptr);

  auto const numEnvs = hCL_module_get_num_environments(m);
  ASSERT_EQ(numEnvs, std::size_t{0});

  hCL_module_destroy(&m);
  ASSERT_TRUE(m == nullptr);
}
