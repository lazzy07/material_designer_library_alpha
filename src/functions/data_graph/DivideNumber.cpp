#include "DivideNumber.hpp"
#include "../../core/UUIDGenerator.hpp"
#include "../../graphs/core/OutputSocket.hpp"
#include "../../graphs/core/InputSocket.hpp"

MATD::FUNC::DATA::PROCESS::DivideNumber::DivideNumber(MATD::GRAPH::Node* node) : DataPrimitiveProcess(node)
{
	MATD_CORE_TRACE("MATD::FUNC DivideNumber function created");

	{
		node->AddInputSocket("1", std::make_shared<MATD::GRAPH::InputSocket>("1", node, GetArgument("default")));
		node->AddInputSocket("2", std::make_shared<MATD::GRAPH::InputSocket>("2", node, GetArgument("default2")));
		node->AddOutputSocket("out", std::make_shared<MATD::GRAPH::OutputSocket>("out", node));
	}
}

void MATD::FUNC::DATA::PROCESS::DivideNumber::Calculate()
{
	auto num1Input = this->GetNode()->GetInputSocket("1");
	auto num2Input = this->GetNode()->GetInputSocket("2");

	auto num1 = num1Input->GetArgument();
	Number1 num1Val = *num1->GetData<float>();
	
	auto num2 = num2Input->GetArgument();
	Number1 num2Val = *num2->GetData<float>();
	
	Number1 total = 0;
	
	if (num2Val != 0) {
		total = num1Val / num2Val;
	}

	MATD_CORE_TRACE("DivideNumber values Num1: {} Num2: {} Total: {}", num1Val, num2Val, total);
	this->GetNode()->GetOutputSocket("out")->GetArgument()->SetData<Number1>(total);
}

void MATD::FUNC::DATA::PROCESS::DivideNumber::SetSocketArguments()
{
	auto node = this->GetNode();

	{
		node->AddInputSocket("1", std::make_shared<MATD::GRAPH::InputSocket>("1", node, GetArgument("1711")));
		node->AddInputSocket("2", std::make_shared<MATD::GRAPH::InputSocket>("2", node, GetArgument("1712")));
		node->AddOutputSocket("out", std::make_shared<MATD::GRAPH::OutputSocket>("out", node));
	}

	UUID id = MATD::CORE::UUIDGenerator::GenerateUUID();
	node->GetOutputSocket("out")->SetArgument(Argument::ArgumentFactory(id.str(), DATA_TYPES::NUMBER1));
	this->Update();
}

