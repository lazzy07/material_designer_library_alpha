#include "BoolToNum1.hpp"
#include "../../core/UUIDGenerator.hpp"
#include "../../graphs/core/OutputSocket.hpp"
#include "../../graphs/core/InputSocket.hpp"

MATD::FUNC::DATA::PROCESS::BoolToNum1::BoolToNum1(MATD::GRAPH::Node* node) : DataPrimitiveFunction(node)
{
	MATD_CORE_TRACE("MATD::FUNC BoolToNum1 function created");

	
}

void MATD::FUNC::DATA::PROCESS::BoolToNum1::Calculate()
{
	auto input = this->GetNode()->GetInput("1");
	auto arg = input->GetArgument();

	auto data = arg->GetData<bool>();

	if (data) {
		this->GetOutput("out").get()->SetData<Number1>(1);
	}
	else {
		this->GetOutput("out").get()->SetData<Number1>(0);
	}
}

void MATD::FUNC::DATA::PROCESS::BoolToNum1::SetSocketArguments()
{
	auto node = this->GetNode();

	{
		node->AddInputSocket("1", std::make_shared<MATD::GRAPH::InputSocket>("1", node, GetArgument("2411")));
		node->SetOutputSocket("out", std::make_shared<MATD::GRAPH::OutputSocket>("out", node));
	}
}

