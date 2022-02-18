#include "Col1ToNum1.hpp"
#include "../../core/UUIDGenerator.hpp"
#include "../../graphs/core/OutputSocket.hpp"
#include "../../graphs/core/InputSocket.hpp"

MATD::FUNC::DATA::PROCESS::Col1ToNum1::Col1ToNum1(MATD::GRAPH::Node* node) : DataPrimitiveProcess(node)
{
	MATD_CORE_TRACE("MATD::FUNC Col1ToNum1 function created");
}

void MATD::FUNC::DATA::PROCESS::Col1ToNum1::Calculate()
{
	auto input = this->GetNode()->GetInputSocket("1");
	auto arg = input->GetArgument();

	auto data = arg->GetData<Number1>();

	this->GetNode()->GetOutputSocket("out")->GetArgument()->SetData<Number1>(*data);
}

void MATD::FUNC::DATA::PROCESS::Col1ToNum1::SetSocketArguments()
{
	auto node = this->GetNode();

	{
		node->AddInputSocket("1", std::make_shared<MATD::GRAPH::InputSocket>("1", node, GetArgument("2011")));
		node->AddOutputSocket("out", std::make_shared<MATD::GRAPH::OutputSocket>("out", node));
	}

	UUID id = MATD::CORE::UUIDGenerator::GenerateUUID();
	node->GetOutputSocket("out")->SetArgument(Argument::ArgumentFactory(id.str(), DATA_TYPES::NUMBER1));
	this->Update();
}
