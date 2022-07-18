#pragma once
#include "../core/ShaderPrimitiveProcess.hpp"
#include "../../graphs/core/MaterialGraph.hpp"

namespace MATD::FUNC::SHADER::PROCESS
{
	class ShaderGraphNode: public ShaderPrimitiveFunction{
	public:
		explicit ShaderGraphNode(MATD::GRAPH::Node* node);
		void Init(MATD::JSON JSONObj) override;

		void Calculate() override;
		void SetSocketArguments() override;

		[[nodiscard]] Ref<MATD::GRAPH::MaterialGraph> GetMaterialGraph() const { return m_MaterialGraph; }
	private:
		Ref<MATD::GRAPH::MaterialGraph> m_MaterialGraph;
	};
}
