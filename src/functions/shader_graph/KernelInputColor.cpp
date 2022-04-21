#include "KernelInputColor.hpp"
#include "../../core/UUIDGenerator.hpp"
#include "../../graphs/core/Graph.hpp"
#include "../../graphs/core/MaterialProject.hpp"
#include "../../graphs/shader_graph/ShaderInputSocket.hpp"
#include "../../graphs/shader_graph/ShaderOutputSocket.hpp"

MATD::FUNC::SHADER::PROCESS::KernelInputColor::KernelInputColor(MATD::GRAPH::Node* node) : ShaderPrimitiveProcess(node)
{
	MATD_CORE_TRACE("MATD::FUNC KernelInputColor function created");
	this->GetNode()->SetName("KernelInputColor");
}

void MATD::FUNC::SHADER::PROCESS::KernelInputColor::Calculate()
{
	auto node = this->GetNode();
	auto shaderInSocket = (GRAPH::ShaderInputSocket*)node->GetInputSocket("1").get();
	auto shaderOutSocket = (GRAPH::ShaderOutputSocket*)node->GetOutputSocket("out").get();

	shaderOutSocket->SetTexArgument(shaderInSocket->GetTextureArgument());


}

void MATD::FUNC::SHADER::PROCESS::KernelInputColor::SetSocketArguments()
{
	const auto node = this->GetNode();
	const auto project = node->GetGraph()->GetMaterialGraph()->GetProject();
	node->AddInputSocket("1", std::make_shared<MATD::GRAPH::ShaderInputSocket>("1", node, project->GetDefaultColorTexture()));
	node->AddOutputSocket("out", std::make_shared<MATD::GRAPH::ShaderOutputSocket>("out", node));

	this->Update();
}
