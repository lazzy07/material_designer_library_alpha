#pragma once
#include "../core/DataPrimitiveProcess.hpp"
#include "../../graphs/core/MaterialGraph.hpp"

namespace MATD::FUNC::DATA::PROCESS
{
	class DataGraphNode: public DataPrimitiveFunction{
	public:
		explicit DataGraphNode(MATD::GRAPH::Node* node);
		void Init(MATD::JSON JSONObj) override;

		void Calculate() override;
		void SetSocketArguments() override;

		Ref<MATD::GRAPH::MaterialGraph> GetMaterialGraph() const { return m_MaterialGraph; }
	private:
		Ref<MATD::GRAPH::MaterialGraph> m_MaterialGraph;
	};
}
