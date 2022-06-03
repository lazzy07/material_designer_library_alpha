#pragma once
#include "../core/ShaderPrimitiveFunction.hpp"
#include "../../graphs/core/MaterialGraph.hpp"

namespace MATD {
	namespace FUNC {
		namespace SHADER {
			namespace PROCESS {
        class ShaderGraphNode: public ShaderPrimitiveFunction{
        public:
	        explicit ShaderGraphNode(MATD::GRAPH::Node* node);

					void Init(MATD::JSON JSONObj) override;

					void Calculate() override;
					void SetSocketArguments() override;
        private:
					Ref<MATD::GRAPH::MaterialGraph> m_MaterialGraph;
        };
      }
    }
  }
}