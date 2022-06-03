#include "ShaderGraphNode.hpp"

MATD::FUNC::SHADER::PROCESS::ShaderGraphNode::ShaderGraphNode(MATD::GRAPH::Node* node) : ShaderPrimitiveFunction(node)
{
}

void MATD::FUNC::SHADER::PROCESS::ShaderGraphNode::Init(MATD::JSON JSONObj)
{
	const auto graph = std::make_shared<
		MATD::GRAPH::MaterialGraph>(this->GetNode()->GetGraph()->GetMaterialGraph()->GetProject(), JSONObj);

	this->m_MaterialGraph = graph;
}

void MATD::FUNC::SHADER::PROCESS::ShaderGraphNode::Calculate()
{
}

void MATD::FUNC::SHADER::PROCESS::ShaderGraphNode::SetSocketArguments()
{
}
