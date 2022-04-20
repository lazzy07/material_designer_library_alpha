#include "InputColor.hpp"
#include "../../core/UUIDGenerator.hpp"
#include "../../graphs/core/Graph.hpp"
#include "../../graphs/core/MaterialProject.hpp"
#include "../../graphs/core/OutputSocket.hpp"
#include "../../graphs/core/InputSocket.hpp"

MATD::FUNC::SHADER::INPUT::InputColor::InputColor(MATD::GRAPH::Node* node) : ShaderPrimitiveInput(node)
{
	MATD_CORE_TRACE("MATD::FUNC InputColor function created");
}

void MATD::FUNC::SHADER::INPUT::InputColor::Calculate()
{
	auto node = this->GetNode();

}

void MATD::FUNC::SHADER::INPUT::InputColor::SetSocketArguments()
{
	const auto node = this->GetNode();
	const auto inputSocket = node->GetInputSocket("1");

	node->GetOutputSocket("out")->SetArgument(inputSocket->GetArgument());
	this->Update();
}
