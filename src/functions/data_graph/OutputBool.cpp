#include "OutputBool.hpp"
#include "../../core/UUIDGenerator.hpp"
#include "../../graphs/core/OutputSocket.hpp"
#include "../../graphs/core/InputSocket.hpp"

MATD::FUNC::DATA::OUTPUT::OutputBool::OutputBool(MATD::GRAPH::Node* node) : DataPrimitiveFunction(node)
{
	MATD_CORE_TRACE("MATD::FUNC OutputBool function created");

	{
		node->AddInputSocket("1", std::make_shared<MATD::GRAPH::InputSocket>("1", node, GetArgument("3211")));
		node->SetOutputSocket("out", std::make_shared<MATD::GRAPH::OutputSocket>("out", node));
	}
}

void MATD::FUNC::DATA::OUTPUT::OutputBool::Calculate()
{
}
