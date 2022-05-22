#include "BoolInput.hpp"
#include "../../core/UUIDGenerator.hpp"
#include "../../graphs/core/OutputSocket.hpp"
#include "../../graphs/core/InputSocket.hpp"

MATD::FUNC::DATA::INPUT::BoolInput::BoolInput(MATD::GRAPH::Node* node) : DataPrimitiveInput(node)
{
	MATD_CORE_TRACE("MATD::FUNC BoolInput function created");
}

void MATD::FUNC::DATA::INPUT::BoolInput::Calculate()
{
	auto input = this->GetNode()->GetInputSocket("1");
	auto arg = input->GetArgument();

	this->GetNode()->GetOutputSocket("out")->GetArgument()->SetData<bool>(*(arg->GetData<bool>()));
}

void MATD::FUNC::DATA::INPUT::BoolInput::SetSocketArguments()
{
	{
		auto node = this->GetNode();
		node->AddInputSocket("1", std::make_shared<MATD::GRAPH::InputSocket>("1", node, GetArgument("default")));
		node->AddOutputSocket("out", std::make_shared<MATD::GRAPH::OutputSocket>("out", node));

		UUID id = MATD::CORE::UUIDGenerator::GenerateUUID();
		node->GetOutputSocket("out")->SetArgument(Argument::ArgumentFactory(id.str(), DATA_TYPES::BOOLEAN));
		this->Update();
	}
}
