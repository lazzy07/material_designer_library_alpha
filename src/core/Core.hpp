/**
 * @file Core.hpp
 * @author Lasantha M Senanayake (222lasantha@gmail.com)
 * @brief Core header file for MATD
 * @version 0.1
 * @date 2024-11-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once
#include <iostream>
#include <memory>
#include "Log.hpp"

/**
 * @brief Enable assert if Debug mode is enabled
 */
#ifdef MATD_DEBUG
  #define MATD_ENABLE_ASSERTS
#endif

/**
 * @brief Assert macro for MATD
 */
#ifdef MATD_ENABLE_ASSERTS
  #define MATD_ASSERT(x, ...) {if(!(x)) { MATD_ERROR("Assertion Failed {0}", __VA_ARGS__); __debugbreak(); } }
	#define MATD_CORE_ASSERT(x, ...) {if(!(x)) { MATD_CORE_ERROR("Assertion Failed {0}", __VA_ARGS__); __debugbreak(); } }
#else
  #define MATD_ASSERT(x, ...) 
	#define MATD_CORE_ASSERT(x, ...)
#endif

/**
 * @brief Scope and Ref smart pointers for MATD
 * 
 */
namespace MATD{
  template<typename T>
  using Scope = std::unique_ptr<T>;

  template<typename T>
  using Ref = std::shared_ptr<T>;
}