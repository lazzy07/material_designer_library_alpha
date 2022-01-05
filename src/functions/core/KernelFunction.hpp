#pragma once
#include "Function.hpp"

namespace MATD{
  namespace FUNC{
    class KernelFunction : public Function{
    public:
      KernelFunction(MATD::GRAPH::Node* node);
      ~KernelFunction();

			virtual void Init() = 0;
			virtual void Calculate() = 0;
			virtual void Update() = 0;

			virtual void OnComplete() = 0;
    };
  }
}