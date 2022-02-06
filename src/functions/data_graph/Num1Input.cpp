#include "Num1Input.hpp"
#include "../../core/UUIDGenerator.hpp"
#include "../../graphs/core/OutputSocket.hpp"
#include "../../graphs/core/InputSocket.hpp"

MATD::FUNC::DATA::INPUT::Num1Input::Num1Input(MATD::GRAPH::Node* node) : DataPrimitiveFunction(node)
{
	MATD_CORE_TRACE("MATD::FUNC Num1Input function created");
}

void MATD::FUNC::DATA::INPUT::Num1Input::Calculate()
{
	auto input = this->GetNode()->GetInputSocket("1");
	auto arg = input->GetArgument();
	this->GetNode()->GetOutputSocket("out")->GetArgument()->SetData<Number1>(*(arg->GetData<Number1>()));
}

void MATD::FUNC::DATA::INPUT::Num1Input::SetSocketArguments()
{
	auto node = this->GetNode();

	{
		node->AddInputSocket("1", std::make_shared<MATD::GRAPH::InputSocket>("1", node, GetArgument("111")));
		node->AddOutputSocket("out", std::make_shared<MATD::GRAPH::OutputSocket>("out", node));
	}
}

