#pragma once
#include "Function.hpp"

namespace MATD{
  namespace FUNC {
    class ShaderFunction : public Function {
    public:
			static Ref<FUNC::ShaderFunction> FunctionFactory(MATD::GRAPH::Node* node, const std::string& initialID, MATD::JSON JSONObj);

      ShaderFunction(MATD::GRAPH::Node* node);
      ~ShaderFunction();

			virtual void Init(MATD::JSON JSONObj) = 0;
			virtual void Calculate() = 0;
    };
  }
}