#include "DataGraphNode.hpp"
#include "../../graphs/core/MaterialGraph.hpp"

MATD::FUNC::DATA::PROCESS::DataGraphNode::DataGraphNode(MATD::GRAPH::Node* node) : DataPrimitiveFunction(node)
{
	this->GetNode()->SetPrimitive(false);
}

void MATD::FUNC::DATA::PROCESS::DataGraphNode::Init(MATD::JSON JSONObj)
{
	this->m_MaterialGraph = std::make_shared<
		MATD::GRAPH::MaterialGraph>(this->GetNode()->GetGraph()->GetMaterialGraph()->GetProject(), JSONObj, true);
	
	this->SetSocketArguments();
}

void MATD::FUNC::DATA::PROCESS::DataGraphNode::Calculate()
{

}

void MATD::FUNC::DATA::PROCESS::DataGraphNode::SetSocketArguments()
{
	const auto node = this->GetNode();
	const auto dataGraph = this->m_MaterialGraph->GetGraph(GRAPH::GRAPH_TYPE::DATA_GRAPH);
	{
		const auto inputNodes = dataGraph->GetInputNodes();
			
		for(auto& inputNode: inputNodes)
		{
			auto id = std::to_string(inputNode->GetID());
			
			node->AddInputSocket(id, inputNode->GetInputSocket("1"));
		}
	}

	{
		const auto outputNodes = dataGraph->GetOutputNodes();

		for (auto& outputNode : outputNodes)
		{
			auto id = std::to_string(outputNode->GetID());
			auto argument = outputNode->GetFunction()->get()->GetArgument("default");

			node->AddOutputSocket(id, outputNode->GetOutputSocket("1"));
		}
	}
}
