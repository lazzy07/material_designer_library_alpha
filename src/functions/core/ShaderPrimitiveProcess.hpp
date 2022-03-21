#pragma once
#include "ShaderPrimitiveFunction.hpp"

namespace MATD{
  namespace FUNC{
    class ShaderPrimitiveProcess : public ShaderPrimitiveFunction {
		public:
			ShaderPrimitiveProcess(MATD::GRAPH::Node* node);
			
			virtual void Calculate() = 0;
			virtual void SetSocketArguments() = 0;
    };
  }
}