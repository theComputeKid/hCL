/**
 * @file dataTypes.hpp
 *
 * @brief Recognised data types for hCL.
 *
 * @version 0.1
 * @date 2022-09-05
 */
#pragma once

namespace hCL
{
  /** @brief Device data type support list. */
  enum struct DataType
  {
    HALF,
    FLOAT,
    DOUBLE,

    /** @brief Used for limits check. Must be last. Never actually used. */
    UNKNOWN
  };
} // namespace hCL
