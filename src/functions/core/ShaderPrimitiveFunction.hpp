#pragma once
#include "ShaderFunction.hpp"

namespace MATD{
  namespace FUNC{
    class ShaderPrimitiveFunction : public ShaderFunction {
		public:
			ShaderPrimitiveFunction(MATD::GRAPH::Node* node);
			~ShaderPrimitiveFunction();

			virtual void Init(const MATD::JSON& JSONObj) override;
			virtual void Calculate() = 0;
			virtual void Update() = 0;

			virtual void OnComplete() = 0;
		};
    };
  }
}