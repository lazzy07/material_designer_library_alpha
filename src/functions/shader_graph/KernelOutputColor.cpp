#include "KernelOutputColor.hpp"
#include "../../core/UUIDGenerator.hpp"
#include "../../graphs/core/Graph.hpp"
#include "../../graphs/core/MaterialProject.hpp"
#include "../../graphs/shader_graph/ShaderInputSocket.hpp"
#include "../../graphs/shader_graph/ShaderOutputSocket.hpp"
#include "../../graphs/kernel_graph/KernelGraph.hpp"

MATD::FUNC::SHADER::PROCESS::KernelOutputColor::KernelOutputColor(MATD::GRAPH::Node* node) : ShaderPrimitiveProcess(node)
{
	MATD_CORE_TRACE("MATD::FUNC KernelOutputColor function created");
	this->GetNode()->SetName("KernelOutput");
}

void MATD::FUNC::SHADER::PROCESS::KernelOutputColor::Calculate()
{
	auto node = this->GetNode();

	//auto shaderOutSocket = (GRAPH::ShaderOutputSocket*)node->GetOutputSocket("out").get();

	
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

void MATD::FUNC::SHADER::PROCESS::KernelOutputColor::SetSocketArguments()
{
	const auto node = this->GetNode();
	const auto project = node->GetGraph()->GetMaterialGraph()->GetProject();
	const auto socket = std::make_shared<MATD::GRAPH::ShaderOutputSocket>("out", node);
	Ref<MATD::ColorTexture> tex;
	tex.reset(MATD::Argument::ColorTexture(project->GetGlobalBitDepth(), project->GetGlobalTexWidth(), project->GetGlobalTexHeight(), ARG_TYPE::DEVICE_READ_WRITE));
	socket->SetTexArgument(tex);
	node->AddOutputSocket("out", socket);

	this->Update();
}
