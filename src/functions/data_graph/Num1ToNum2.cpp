#include "Num1ToNum2.hpp"
#include "../../core/UUIDGenerator.hpp"
#include "../../graphs/core/OutputSocket.hpp"
#include "../../graphs/core/InputSocket.hpp"

MATD::FUNC::DATA::PROCESS::Num1ToNum2::Num1ToNum2(MATD::GRAPH::Node* node) : DataPrimitiveProcess(node)
{
	MATD_CORE_TRACE("MATD::FUNC Num1ToNum2 function created");

}

void MATD::FUNC::DATA::PROCESS::Num1ToNum2::Calculate()
{
	auto input1 = this->GetNode()->GetInputSocket("1");
	auto input2 = this->GetNode()->GetInputSocket("2");

	auto arg1 = input1->GetArgument();
	auto arg2 = input2->GetArgument();

	auto data1 = arg1->GetData<Number1>();
	auto data2 = arg2->GetData<Number1>();

	Number2 data;
	data.x = *data1;
	data.y = *data2;

	this->GetNode()->GetOutputSocket("out")->GetArgument()->SetData<Number2>(data);
}

void MATD::FUNC::DATA::PROCESS::Num1ToNum2::SetSocketArguments()
{
	auto node = this->GetNode();

	{
		MATD::UUID uuid = MATD::CORE::UUIDGenerator::GenerateUUID();
		node->AddInputSocket("1", std::make_shared<MATD::GRAPH::InputSocket>("1", node, GetArgument("2611")));
		node->AddInputSocket("2", std::make_shared<MATD::GRAPH::InputSocket>("2", node, GetArgument("2612")));
		node->AddOutputSocket("out", std::make_shared<MATD::GRAPH::OutputSocket>("out", node));
	}

	UUID id = MATD::CORE::UUIDGenerator::GenerateUUID();
	node->GetOutputSocket("out")->SetArgument(Argument::ArgumentFactory(id.str(), DATA_TYPES::NUMBER2));
	this->Update();
}
