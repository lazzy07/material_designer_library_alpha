#include "ShaderPrimitiveFunction.hpp"

MATD::FUNC::ShaderPrimitiveFunction::ShaderPrimitiveFunction(MATD::GRAPH::Node* node) : ShaderFunction(node)
{
}

MATD::FUNC::ShaderPrimitiveFunction::~ShaderPrimitiveFunction()
{
}

void MATD::FUNC::ShaderPrimitiveFunction::Init(MATD::JSON JSONObj)
{
	MATD::JSON data = JSONObj["data"];
	for (MATD::JSON::iterator it = data.begin(); it != data.end(); ++it) {
		auto arg = MATD::FUNC::Argument::ArgumentFactory(*it);
		this->SetArgument(arg);
	}

	this->SetSocketArguments();
}
