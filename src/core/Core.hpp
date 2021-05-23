#pragma once
#include <memory>

#ifdef MATD_DEBUG
  #define MATD_ENABLE_ASSERTS
#endif

#ifdef MATD_ENABLE_ASSERTS
  #define MATD_ASSERT(x, ...) {if(!(x)) { MATD_ERROR("Assertion Failed {0}", __VA_ARGS__); __debugbreak(); } }
	#define MATD_CORE_ASSERT(x, ...) {if(!(x)) { MATD_ERROR("Assertion Failed {0}", __VA_ARGS__); __debugbreak(); } }
#else
  #define MATD_ASSERT(x, ...) 
	#define MATD_CORE_ASSERT(x, ...)
#endif

namespace MATD{
  template<typename T>
  using Scope = std::unique_ptr<T>;

  template<typename T>
  using Ref = std::shared_ptr<T>;
}