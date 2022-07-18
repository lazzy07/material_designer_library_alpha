#include "Viewer.hpp"
#include "../../graphs/core/Graph.hpp"
#include "../../graphs/core/MaterialProject.hpp"
#include "../../graphs/shader_graph/ShaderInputSocket.hpp"

MATD::FUNC::SHADER::PROCESS::Viewer::Viewer(MATD::GRAPH::Node* node) : ShaderPrimitiveProcess(node)
{
}

void MATD::FUNC::SHADER::PROCESS::Viewer::Calculate()
{
}

void MATD::FUNC::SHADER::PROCESS::Viewer::SetSocketArguments()
{
	const auto node = this->GetNode();
	const auto project = node->GetGraph()->GetMaterialGraph()->GetProject();
	node->AddInputSocket("1", std::make_shared<MATD::GRAPH::ShaderInputSocket>("1", node, project->GetDefaultColorTexture()));
}
