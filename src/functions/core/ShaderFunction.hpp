#pragma once
#include "Function.hpp"

namespace MATD{
  namespace FUNC {
    class ShaderFunction : public Function {
    public:
      ShaderFunction(MATD::GRAPH::Node* node);
      ~ShaderFunction();

			virtual void Init() = 0;
			virtual void Calculate() = 0;
			virtual void Update() = 0;

			virtual void OnComplete() = 0;
    };
  }
}