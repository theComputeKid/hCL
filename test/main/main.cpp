/**
 * @file main.cpp
 *
 * @brief Main entry point to tests.
 *
 * @author theComputeKid
 * @version 0.1
 * @date 2022-09-03
 */
#include "pch.hpp"

namespace
{
#ifdef DEBUG
  constexpr std::string_view init{"hCL Testing Framework [debug]"};
#else
  constexpr std::string_view init{"hCL Testing Framework [release]"};
#endif
} // namespace

int main(int argc, char* argv[])
{
  std::cout << init << std::endl;
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
