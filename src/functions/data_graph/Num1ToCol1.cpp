#include "Num1ToCol1.hpp"
#include "../../core/UUIDGenerator.hpp"
#include "../../graphs/core/OutputSocket.hpp"
#include "../../graphs/core/InputSocket.hpp"

MATD::FUNC::DATA::PROCESS::Num1ToCol1::Num1ToCol1(MATD::GRAPH::Node* node) : DataPrimitiveFunction(node)
{
	MATD_CORE_TRACE("MATD::FUNC Num1ToCol1 function created");

	{
		node->AddInputSocket("1", std::make_shared<MATD::GRAPH::InputSocket>("1", node, GetArgument("2111")));
		node->SetOutputSocket("out", std::make_shared<MATD::GRAPH::OutputSocket>("out", node));
	}
}

void MATD::FUNC::DATA::PROCESS::Num1ToCol1::Calculate()
{
}
