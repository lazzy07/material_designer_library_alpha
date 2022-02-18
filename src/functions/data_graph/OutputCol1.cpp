#include "OutputCol1.hpp"
#include "../../core/UUIDGenerator.hpp"
#include "../../graphs/core/OutputSocket.hpp"
#include "../../graphs/core/InputSocket.hpp"

MATD::FUNC::DATA::OUTPUT::OutputCol1::OutputCol1(MATD::GRAPH::Node* node) : DataPrimitiveOutput(node)
{
	MATD_CORE_TRACE("MATD::FUNC OutputCol1 function created");
}

void MATD::FUNC::DATA::OUTPUT::OutputCol1::Calculate()
{
}

void MATD::FUNC::DATA::OUTPUT::OutputCol1::SetSocketArguments()
{
	auto node = this->GetNode();

	{
		node->AddInputSocket("id", std::make_shared<MATD::GRAPH::InputSocket>("id", node, GetArgument("id")));
		node->AddOutputSocket("out", std::make_shared<MATD::GRAPH::OutputSocket>("out", node));
	}
}
