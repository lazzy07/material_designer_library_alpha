#include "BoolToNum1.hpp"
#include "../../core/UUIDGenerator.hpp"
#include "../../graphs/core/OutputSocket.hpp"
#include "../../graphs/core/InputSocket.hpp"

MATD::FUNC::DATA::PROCESS::BoolToNum1::BoolToNum1(MATD::GRAPH::Node* node) : DataPrimitiveProcess(node)
{
	MATD_CORE_TRACE("MATD::FUNC BoolToNum1 function created");
}

void MATD::FUNC::DATA::PROCESS::BoolToNum1::Calculate()
{
	auto input = this->GetNode()->GetInputSocket("1");
	auto arg = input->GetArgument();

	auto data = arg->GetData<bool>();

	if (*data) {
		this->GetNode()->GetOutputSocket("out")->GetArgument()->SetData<Number1>(1);
		MATD_CORE_TRACE("MATD::FUNC BooltoNum1 bool: {} num1: {}", *data, 1);
	}
	else {
		this->GetNode()->GetOutputSocket("out")->GetArgument()->SetData<Number1>(0);
		MATD_CORE_TRACE("MATD::FUNC BooltoNum1 bool: {} num1: {}", *data, 0);
	}

}

void MATD::FUNC::DATA::PROCESS::BoolToNum1::SetSocketArguments()
{
	auto node = this->GetNode();

	{
		node->AddInputSocket("1", std::make_shared<MATD::GRAPH::InputSocket>("1", node, GetArgument("default")));
		node->AddOutputSocket("out", std::make_shared<MATD::GRAPH::OutputSocket>("out", node));

		UUID id = MATD::CORE::UUIDGenerator::GenerateUUID();
		node->GetOutputSocket("out")->SetArgument(Argument::ArgumentFactory(id.str(), DATA_TYPES::NUMBER1));
		this->Update();
	}
}

