#include "OutputNum1.hpp"
#include "../../core/UUIDGenerator.hpp"
#include "../../graphs/core/OutputSocket.hpp"
#include "../../graphs/core/InputSocket.hpp"

MATD::FUNC::DATA::OUTPUT::OutputNum1::OutputNum1(MATD::GRAPH::Node* node) : DataPrimitiveOutput(node)
{
	MATD_CORE_TRACE("MATD::FUNC OutputNum1 function created");
}

void MATD::FUNC::DATA::OUTPUT::OutputNum1::Calculate()
{
}

void MATD::FUNC::DATA::OUTPUT::OutputNum1::SetSocketArguments()
{
	auto node = this->GetNode();

	{
		node->AddInputSocket("1", std::make_shared<MATD::GRAPH::InputSocket>("1", node, GetArgument("2811")));
		node->AddOutputSocket("out", std::make_shared<MATD::GRAPH::OutputSocket>("out", node));
	}

	UUID id = MATD::CORE::UUIDGenerator::GenerateUUID();
	node->GetOutputSocket("out")->SetArgument(Argument::ArgumentFactory(id.str(), DATA_TYPES::NUMBER1));
	this->Update();
}
