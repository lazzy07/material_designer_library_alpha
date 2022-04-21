#include "KernelOutputGrayscale.hpp"
#include "../../core/UUIDGenerator.hpp"
#include "../../graphs/core/Graph.hpp"
#include "../../graphs/core/MaterialProject.hpp"
#include "../../graphs/shader_graph/ShaderInputSocket.hpp"
#include "../../graphs/shader_graph/ShaderOutputSocket.hpp"
#include "../../graphs/kernel_graph/KernelGraph.hpp"

MATD::FUNC::SHADER::PROCESS::KernelOutputGrayscale::KernelOutputGrayscale(MATD::GRAPH::Node* node) : ShaderPrimitiveProcess(node)
{
	MATD_CORE_TRACE("MATD::FUNC KernelOutputGrayscale function created");
	this->GetNode()->SetName("KernelOutput");
}

void MATD::FUNC::SHADER::PROCESS::KernelOutputGrayscale::Calculate()
{
	auto node = this->GetNode();
	auto shaderInSocket = (GRAPH::ShaderInputSocket*)node->GetInputSocket("1").get();
	auto shaderOutSocket = (GRAPH::ShaderOutputSocket*)node->GetOutputSocket("out").get();

	shaderOutSocket->SetTexArgument(shaderInSocket->GetTextureArgument());
}

void MATD::FUNC::SHADER::PROCESS::KernelOutputGrayscale::SetSocketArguments()
{
	const auto node = this->GetNode();
	const auto project = node->GetGraph()->GetMaterialGraph()->GetProject();
	const auto tex = std::make_shared<MATD::GrayscaleTexture>(*MATD::Argument::GrayscaleTexture(project->GetGlobalBitDepth(), project->GetGlobalTexWidth(), project->GetGlobalTexHeight(), ARG_TYPE::DEVICE_READ_WRITE));
	node->AddInputSocket("1", std::make_shared<MATD::GRAPH::ShaderInputSocket>("1", node, tex));
	node->AddOutputSocket("out", std::make_shared<MATD::GRAPH::ShaderOutputSocket>("out", node));
}
