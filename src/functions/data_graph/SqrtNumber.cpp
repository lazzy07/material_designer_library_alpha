#include "SqrtNumber.hpp"
#include "../../core/UUIDGenerator.hpp"
#include "../../graphs/core/OutputSocket.hpp"
#include "../../graphs/core/InputSocket.hpp"
#include <math.h>

MATD::FUNC::DATA::PROCESS::SqrtNumber::SqrtNumber(MATD::GRAPH::Node* node) : DataPrimitiveFunction(node)
{
	MATD_CORE_TRACE("MATD::FUNC SqrtNumber function created");
}

void MATD::FUNC::DATA::PROCESS::SqrtNumber::Calculate()
{
	auto num1Input = this->GetNode()->GetInputSocket("1");
	auto num2Input = this->GetNode()->GetInputSocket("2");

	auto num1 = num1Input->GetArgument();
	Number1 num1Val = *num1->GetData<float>();

	Number1 total = sqrt(num1Val);

	MATD_CORE_TRACE("SqrtNumber values Num1: {} Total: {}", num1Val, total);

	this->GetNode()->GetOutputSocket("out")->GetArgument()->SetData<Number1>(total);
}

void MATD::FUNC::DATA::PROCESS::SqrtNumber::SetSocketArguments()
{
	auto node = this->GetNode();

	{
		node->AddInputSocket("1", std::make_shared<MATD::GRAPH::InputSocket>("1", node, GetArgument("1911")));
		node->AddOutputSocket("out", std::make_shared<MATD::GRAPH::OutputSocket>("out", node));
	}
}
