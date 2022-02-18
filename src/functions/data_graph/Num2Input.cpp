#include "Num2Input.hpp"
#include "../../core/UUIDGenerator.hpp"
#include "../../graphs/core/OutputSocket.hpp"
#include "../../graphs/core/InputSocket.hpp"

MATD::FUNC::DATA::INPUT::Num2Input::Num2Input(MATD::GRAPH::Node* node) : DataPrimitiveInput(node)
{
	MATD_CORE_TRACE("MATD::FUNC Num2Input function created");
}

void MATD::FUNC::DATA::INPUT::Num2Input::Calculate()
{
}

void MATD::FUNC::DATA::INPUT::Num2Input::SetSocketArguments()
{
	auto node = this->GetNode();

	{
		node->AddInputSocket("1", std::make_shared<MATD::GRAPH::InputSocket>("2", node, GetArgument("2612")));
		node->AddOutputSocket("out", std::make_shared<MATD::GRAPH::OutputSocket>("out", node));
	}

	UUID id = MATD::CORE::UUIDGenerator::GenerateUUID();
	node->GetOutputSocket("out")->SetArgument(Argument::ArgumentFactory(id.str(), DATA_TYPES::NUMBER2));
	this->Update();
}
