#include "OutputCol3.hpp"
#include "../../core/UUIDGenerator.hpp"
#include "../../graphs/core/OutputSocket.hpp"
#include "../../graphs/core/InputSocket.hpp"

MATD::FUNC::DATA::OUTPUT::OutputCol3::OutputCol3(MATD::GRAPH::Node* node) : DataPrimitiveOutput(node)
{
	MATD_CORE_TRACE("MATD::FUNC OutputCol3 function created");

}

void MATD::FUNC::DATA::OUTPUT::OutputCol3::Calculate()
{
}

void MATD::FUNC::DATA::OUTPUT::OutputCol3::SetSocketArguments()
{
	auto node = this->GetNode();

	{
		node->AddInputSocket("1", std::make_shared<MATD::GRAPH::InputSocket>("1", node, GetArgument("3111")));
		node->AddOutputSocket("out", std::make_shared<MATD::GRAPH::OutputSocket>("out", node));
	}
}
