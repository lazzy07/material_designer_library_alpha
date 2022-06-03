#include "DataGraphNode.hpp"
#include "../../graphs/core/MaterialGraph.hpp"

MATD::FUNC::DATA::PROCESS::DataGraphNode::DataGraphNode(MATD::GRAPH::Node* node) : DataPrimitiveFunction(node)
{
}

void MATD::FUNC::DATA::PROCESS::DataGraphNode::Init(MATD::JSON JSONObj)
{
	this->m_MaterialGraph = std::make_shared<
		MATD::GRAPH::MaterialGraph>(this->GetNode()->GetGraph()->GetMaterialGraph()->GetProject(), JSONObj, true);
}

void MATD::FUNC::DATA::PROCESS::DataGraphNode::Calculate()
{
}

void MATD::FUNC::DATA::PROCESS::DataGraphNode::SetSocketArguments()
{
}
