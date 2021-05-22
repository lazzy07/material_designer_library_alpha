#pragma once
#include <memory>

#ifdef VUL_DEBUG
  #define VUL_ENABLE_ASSERTS
#endif

#ifdef VUL_ENABLE_ASSERTS
  #define VUL_ASSERT(x, ...) {if(!(x)) { VUL_ERROR("Assertion Failed {0}", __VA_ARGS__); __debugbreak(); } }
	#define VUL_CORE_ASSERT(x, ...) {if(!(x)) { VUL_ERROR("Assertion Failed {0}", __VA_ARGS__); __debugbreak(); } }
#else
  #define VUL_ASSERT(x, ...) 
	#define VUL_CORE_ASSERT(x, ...)
#endif

namespace MATD{
  template<typename T>
  using Scope = std::unique_ptr<T>;

  template<typename T>
  using Ref = std::shared_ptr<T>;
}