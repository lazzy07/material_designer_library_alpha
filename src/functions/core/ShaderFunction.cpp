#include "ShaderFunction.hpp"
#include "../shader_graph/ShaderGraphFunctions.hpp"

MATD::Ref<MATD::FUNC::ShaderFunction> MATD::FUNC::ShaderFunction::FunctionFactory(MATD::GRAPH::Node* node, const std::string& initialID, MATD::JSON JSONObj)
{
	if (initialID == "1") {
		auto func = std::make_shared<MATD::FUNC::SHADER::INPUT::InputColor>(node);
		return func;
	}
	else if (initialID == "2") {
		auto func = std::make_shared<MATD::FUNC::SHADER::INPUT::InputGrayscale>(node);
		return func;
	}
	else if (initialID == "3") {
		auto func = std::make_shared<MATD::FUNC::SHADER::PROCESS::KernelInputColor>(node);
		return func;
	}
	else if (initialID == "4") {
		auto func = std::make_shared<MATD::FUNC::SHADER::PROCESS::KernelInputGrayscale>(node);
		return func;
	}
	else if (initialID == "5") {
		auto func = std::make_shared<MATD::FUNC::SHADER::PROCESS::KernelOutputColor>(node);
		return func;
	}
	else if (initialID == "6") {
		auto func = std::make_shared<MATD::FUNC::SHADER::PROCESS::KernelOutputGrayscale>(node);
		return func;
	}
	else if (initialID == "7") {
		auto func = std::make_shared<MATD::FUNC::SHADER::OUTPUT::OutputColor>(node);
		return func;
	}
	else if (initialID == "8") {
		auto func = std::make_shared<MATD::FUNC::SHADER::OUTPUT::OutputGrayscale>(node);
		return func;
	}

	return std::make_shared<MATD::FUNC::SHADER::PROCESS::ShaderGraphNode>(node);
}

MATD::FUNC::ShaderFunction::ShaderFunction(MATD::GRAPH::Node* node) : Function(node)
{
}


MATD::FUNC::ShaderFunction::~ShaderFunction()
{
}
