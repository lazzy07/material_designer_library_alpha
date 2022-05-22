#include "AddNumber.hpp"
#include "../../core/UUIDGenerator.hpp"
#include "../../graphs/core/OutputSocket.hpp"
#include "../../graphs/core/InputSocket.hpp"

MATD::FUNC::DATA::PROCESS::AddNumber::AddNumber(MATD::GRAPH::Node* node) : DataPrimitiveProcess(node)
{
	MATD_CORE_TRACE("MATD::FUNC AddNumber function created");
}

void MATD::FUNC::DATA::PROCESS::AddNumber::Calculate()
{
	const auto num1Input = this->GetNode()->GetInputSocket("1"); 
	const auto num2Input = this->GetNode()->GetInputSocket("2"); 
	
	const auto num1 = num1Input->GetArgument();
	Number1 num1Val = *num1->GetData<float>();
	const auto num2 = num2Input->GetArgument();
	Number1 num2Val = *num2->GetData<float>();

	Number1 total = num1Val + num2Val;

	MATD_CORE_TRACE("AddNumber ID: {} values Num1: {} Num2: {} Total: {}", this->GetNode()->GetID(), num1Val, num2Val, total);

	this->GetNode()->GetOutputSocket("out")->GetArgument()->SetData<Number1>(total);
}

void MATD::FUNC::DATA::PROCESS::AddNumber::SetSocketArguments()
{
	{
		auto node = this->GetNode();
		node->AddInputSocket("1", std::make_shared<MATD::GRAPH::InputSocket>("1", node, GetArgument("default")));
		node->AddInputSocket("2", std::make_shared<MATD::GRAPH::InputSocket>("2", node, GetArgument("default2")));
		node->AddOutputSocket("out", std::make_shared<MATD::GRAPH::OutputSocket>("out", node));

		const UUID id = MATD::CORE::UUIDGenerator::GenerateUUID();
		node->GetOutputSocket("out")->SetArgument(Argument::ArgumentFactory(id.str(), DATA_TYPES::NUMBER1));
		this->Update();
	}
}
