#include "OutputCol1.hpp"
#include "../../core/UUIDGenerator.hpp"
#include "../../graphs/core/OutputSocket.hpp"
#include "../../graphs/core/InputSocket.hpp"

MATD::FUNC::DATA::OUTPUT::OutputCol1::OutputCol1(MATD::GRAPH::Node* node) : DataPrimitiveFunction(node)
{
	MATD_CORE_TRACE("MATD::FUNC OutputCol1 function created");

	{
		node->AddInputSocket("1", std::make_shared<MATD::GRAPH::InputSocket>("1", node, GetArgument("3011")));
		node->SetOutputSocket("out", std::make_shared<MATD::GRAPH::OutputSocket>("out", node));
	}
}

void MATD::FUNC::DATA::OUTPUT::OutputCol1::Calculate()
{
}
