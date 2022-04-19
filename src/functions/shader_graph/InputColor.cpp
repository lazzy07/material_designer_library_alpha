#include "InputColor.hpp"

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
}
