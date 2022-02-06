#include "AddNumber.hpp"
#include "../../core/UUIDGenerator.hpp"
#include "../../graphs/core/OutputSocket.hpp"
#include "../../graphs/core/InputSocket.hpp"

MATD::FUNC::DATA::PROCESS::AddNumber1::AddNumber1(MATD::GRAPH::Node* node) : DataPrimitiveFunction(node)
{
	MATD_CORE_TRACE("MATD::FUNC AddNumber function created");
}

void MATD::FUNC::DATA::PROCESS::AddNumber1::Calculate()
{
	auto num1Input = this->GetNode()->GetInputSocket("1"); 
	auto num2Input = this->GetNode()->GetInputSocket("2"); 
	
	auto num1 = num1Input->GetArgument();
	Number1 num1Val = *num1->GetData<float>();
	auto num2 = num2Input->GetArgument();
	Number1 num2Val = *num2->GetData<float>();

	Number1 total = num1Val + num2Val;

	MATD_CORE_TRACE("AddNumber values Num1: {} Num2: {} Total: {}", num1Val, num2Val, total);

	this->GetNode()->GetOutputSocket("out")->GetArgument()->SetData<Number1>(total);
}

void MATD::FUNC::DATA::PROCESS::AddNumber1::SetSocketArguments()
{
	{
		auto node = this->GetNode();
		node->AddInputSocket("1", std::make_shared<MATD::GRAPH::InputSocket>("1", node, GetArgument("1411")));
		node->AddInputSocket("2", std::make_shared<MATD::GRAPH::InputSocket>("2", node, GetArgument("1412")));
		node->AddOutputSocket("out", std::make_shared<MATD::GRAPH::OutputSocket>("out", node));
	}
}