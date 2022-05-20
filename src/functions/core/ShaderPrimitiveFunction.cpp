#include "ShaderPrimitiveFunction.hpp"
#include "../../core/MaterialDesigner.hpp"
#include "../../graphs/shader_graph/ShaderOutputSocket.hpp"

MATD::FUNC::ShaderPrimitiveFunction::ShaderPrimitiveFunction(MATD::GRAPH::Node* node) : ShaderFunction(node)
{
}

MATD::FUNC::ShaderPrimitiveFunction::~ShaderPrimitiveFunction()
{
}

void MATD::FUNC::ShaderPrimitiveFunction::Init(MATD::JSON JSONObj)
{
	MATD::JSON data = JSONObj["data"];
	for (const auto& it : data)
	{
		const auto arg = MATD::FUNC::Argument::ArgumentFactory(it);
		this->SetArgument(arg);
	}

	this->SetSocketArguments();
}

void MATD::FUNC::ShaderPrimitiveFunction::OnComplete()
{
	const auto node = this->GetNode();
	const auto outSocket = dynamic_cast<MATD::GRAPH::ShaderOutputSocket*>(node->GetOutputSocket("out").get());
	MATD::CORE::MaterialDesigner::CallShaderNodeChangeCallback(node->GetID(), outSocket->GetTexArgument().get());
	MATD::FUNC::Function::OnComplete();
}
