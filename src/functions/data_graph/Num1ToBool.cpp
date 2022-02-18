#include "Num1ToBool.hpp"
#include "../../core/UUIDGenerator.hpp"
#include "../../graphs/core/OutputSocket.hpp"
#include "../../graphs/core/InputSocket.hpp"

MATD::FUNC::DATA::PROCESS::Num1ToBool::Num1ToBool(MATD::GRAPH::Node* node) : DataPrimitiveProcess(node)
{
	MATD_CORE_TRACE("MATD::FUNC Num1ToBool function created");
}

void MATD::FUNC::DATA::PROCESS::Num1ToBool::Calculate()
{
	auto input = this->GetNode()->GetInputSocket("1");
	auto arg = input->GetArgument();

	auto data = arg->GetData<Number1>();

	if (*data != 0) {
		this->GetNode()->GetOutputSocket("out")->GetArgument()->SetData<bool>(true);
		MATD_CORE_TRACE("MATD::FUNC Num1ToBool num1: {} bool: {}", *data, true);
	}
	else {
		this->GetNode()->GetOutputSocket("out")->GetArgument()->SetData<bool>(false);
		MATD_CORE_TRACE("MATD::FUNC Num1ToBool num1: {} bool: {}", *data, false);
	}
}

void MATD::FUNC::DATA::PROCESS::Num1ToBool::SetSocketArguments()
{
	auto node = this->GetNode();

	{
		node->AddInputSocket("1", std::make_shared<MATD::GRAPH::InputSocket>("1", node, GetArgument("2511")));
		node->AddOutputSocket("out", std::make_shared<MATD::GRAPH::OutputSocket>("out", node));
	}

	UUID id = MATD::CORE::UUIDGenerator::GenerateUUID();
	node->GetOutputSocket("out")->SetArgument(Argument::ArgumentFactory(id.str(), DATA_TYPES::BOOLEAN));
	this->Update();
}

