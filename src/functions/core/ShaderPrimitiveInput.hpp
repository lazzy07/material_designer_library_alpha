#pragma once
#include "ShaderPrimitiveFunction.hpp"

namespace MATD{
  namespace FUNC{
    class ShaderPrimitiveInput : public ShaderPrimitiveFunction {
		public:
			ShaderPrimitiveInput(MATD::GRAPH::Node* node);
			
			virtual void Calculate() = 0;
			virtual void SetSocketArguments() = 0;
    };
  }
}