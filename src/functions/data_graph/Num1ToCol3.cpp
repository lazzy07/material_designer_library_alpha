#include "Num1ToCol3.hpp"
#include "../../core/UUIDGenerator.hpp"
#include "../../graphs/core/OutputSocket.hpp"
#include "../../graphs/core/InputSocket.hpp"

MATD::FUNC::DATA::PROCESS::Num1ToCol3::Num1ToCol3(MATD::GRAPH::Node* node) : DataPrimitiveFunction(node)
{
	MATD_CORE_TRACE("MATD::FUNC Num1ToCol3 function created");
}

void MATD::FUNC::DATA::PROCESS::Num1ToCol3::Calculate()
{
	auto input1 = this->GetNode()->GetInputSocket("1");
	auto input2 = this->GetNode()->GetInputSocket("2");
	auto input3 = this->GetNode()->GetInputSocket("3");

	auto arg1 = input1->GetArgument();
	auto arg2 = input2->GetArgument();
	auto arg3 = input3->GetArgument();

	auto data1 = arg1->GetData<Number1>();
	auto data2 = arg2->GetData<Number1>();
	auto data3 = arg3->GetData<Number1>();

	ColorVec3 data;
	data.r = *data1;
	data.g = *data2;
	data.b = *data3;

	this->GetNode()->GetOutputSocket("out")->GetArgument()->SetData<ColorVec3>(data);
}

void MATD::FUNC::DATA::PROCESS::Num1ToCol3::SetSocketArguments()
{
	auto node = this->GetNode();

	{
		node->AddInputSocket("1", std::make_shared<MATD::GRAPH::InputSocket>("1", node, GetArgument("2311")));
		node->AddInputSocket("2", std::make_shared<MATD::GRAPH::InputSocket>("2", node, GetArgument("2312")));
		node->AddInputSocket("3", std::make_shared<MATD::GRAPH::InputSocket>("3", node, GetArgument("2313")));
		node->AddOutputSocket("out", std::make_shared<MATD::GRAPH::OutputSocket>("out", node));
	}
}
