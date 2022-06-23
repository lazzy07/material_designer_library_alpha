#pragma once
#include "ShaderPrimitiveFunction.hpp"

namespace MATD{
  namespace FUNC{
    class ShaderPrimitiveProcess : public ShaderPrimitiveFunction {
		public:
			ShaderPrimitiveProcess(MATD::GRAPH::Node* node);

			void Calculate() override = 0;
			void SetSocketArguments() override = 0;
    };
  }
}