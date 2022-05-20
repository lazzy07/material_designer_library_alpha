#pragma once
#include "ShaderFunction.hpp"

namespace MATD {
	namespace FUNC {
		class ShaderPrimitiveFunction : public ShaderFunction {
		public:
			ShaderPrimitiveFunction(MATD::GRAPH::Node* node);
			~ShaderPrimitiveFunction();

			void Init(MATD::JSON JSONObj) override;
			void OnComplete();
			virtual void SetSocketArguments() = 0;
		};
	}
}