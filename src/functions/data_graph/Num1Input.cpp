#include "Num1Input.hpp"
#include "../../core/UUIDGenerator.hpp"
#include "../../graphs/core/OutputSocket.hpp"
#include "../../graphs/core/InputSocket.hpp"

MATD::FUNC::DATA::INPUT::Num1Input::Num1Input(MATD::GRAPH::Node* node) : DataPrimitiveFunction(node)
{
	MATD_CORE_TRACE("MATD::FUNC Num1Input function created");

	{
		

		std::string argId = CORE::UUIDGenerator::GenerateUUID().str();
		Number1* num = (Number1*)malloc(sizeof(Number1));

		if (num) {
			*num = 0;
			Ref<Argument> arg = std::make_shared<Argument>(argId, MATD::DATA_TYPES::NUMBER1, num);
			this->SetOutput(arg);
		}
	}
}

void MATD::FUNC::DATA::INPUT::Num1Input::Calculate()
{
	Ref<MATD::FUNC::Argument> argument1 = this->GetArgument("111");
	this->SetOutput(argument1);
	auto output = this->GetNode()->GetOutput();

}

void MATD::FUNC::DATA::INPUT::Num1Input::SetSocketArguments()
{
	auto node = this->GetNode();

	{
		node->AddInputSocket("1", std::make_shared<MATD::GRAPH::InputSocket>("1", node, GetArgument("111")));
		node->SetOutputSocket("out", std::make_shared<MATD::GRAPH::OutputSocket>("out", node));
	}
}

