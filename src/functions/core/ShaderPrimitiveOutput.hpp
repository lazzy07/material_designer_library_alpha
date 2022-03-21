#pragma once
#include "ShaderPrimitiveFunction.hpp"

namespace MATD{
  namespace FUNC{
    class ShaderPrimitiveOutput : public ShaderPrimitiveFunction {
		public:
			ShaderPrimitiveOutput(MATD::GRAPH::Node* node);
			
			virtual void Calculate() = 0;
			virtual void SetSocketArguments() = 0;
    };
  }
}