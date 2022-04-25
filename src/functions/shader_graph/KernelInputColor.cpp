#include "KernelInputColor.hpp"
#include "../../core/UUIDGenerator.hpp"
#include "../../graphs/core/Graph.hpp"
#include "../../graphs/core/MaterialProject.hpp"
#include "../../graphs/shader_graph/ShaderInputSocket.hpp"
#include "../../graphs/shader_graph/ShaderOutputSocket.hpp"

MATD::FUNC::SHADER::PROCESS::KernelInputColor::KernelInputColor(MATD::GRAPH::Node* node) : ShaderPrimitiveProcess(node)
{
	MATD_CORE_TRACE("MATD::FUNC KernelInputColor function created");
	this->GetNode()->SetName("KernelInput");
}

void MATD::FUNC::SHADER::PROCESS::KernelInputColor::Calculate()
{
	auto node = this->GetNode();
	auto shaderInSocket = (GRAPH::ShaderInputSocket*)node->GetInputSocket("1").get();
	auto shaderOutSocket = (GRAPH::ShaderOutputSocket*)node->GetOutputSocket("out").get();

	shaderOutSocket->SetTexArgument(shaderInSocket->GetTextureArgument());

	const auto nodes = this->GetNode()->GetGraph()->GetNodes();

	bool canUpdate = true;

	for (auto ele = nodes->begin(); ele != nodes->end(); ++ele)
	{
		if (ele->second->GetName() == "KernelInput")
		{
			if (!ele->second->GetInputSocket("1")->IsUpdated())
			{
				canUpdate = false;
				break;
			}
		}
	}

	if (canUpdate)
	{
		auto materialGraph = node->GetGraph()->GetMaterialGraph();
		if (materialGraph->GetType() == GRAPH::GRAPH_TYPE::KERNEL_GRAPH)
		{
			auto kernelGraph = (GRAPH::KernelGraph*)materialGraph->GetGraph(GRAPH::GRAPH_TYPE::KERNEL_GRAPH).get();

			kernelGraph->Compile();
		}
	}

}

void MATD::FUNC::SHADER::PROCESS::KernelInputColor::SetSocketArguments()
{
	const auto node = this->GetNode();
	const auto project = node->GetGraph()->GetMaterialGraph()->GetProject();
	node->AddInputSocket("1", std::make_shared<MATD::GRAPH::ShaderInputSocket>("1", node, project->GetDefaultColorTexture()));
	node->AddOutputSocket("out", std::make_shared<MATD::GRAPH::ShaderOutputSocket>("out", node));

	this->Update();
}
