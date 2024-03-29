#include "Num2ToNum1.hpp"
#include "../../core/UUIDGenerator.hpp"
#include "../../graphs/core/OutputSocket.hpp"
#include "../../graphs/core/InputSocket.hpp"

MATD::FUNC::DATA::PROCESS::Num2ToNum1::Num2ToNum1(MATD::GRAPH::Node* node) : DataPrimitiveProcess(node)
{
	MATD_CORE_TRACE("MATD::FUNC Num2ToNum1 function created");
}

void MATD::FUNC::DATA::PROCESS::Num2ToNum1::Calculate()
{

}

void MATD::FUNC::DATA::PROCESS::Num2ToNum1::SetSocketArguments()
{
	auto node = this->GetNode();

	{
		node->AddInputSocket("1", std::make_shared<MATD::GRAPH::InputSocket>("1", node, GetArgument("default")));
		node->AddOutputSocket("out", std::make_shared<MATD::GRAPH::OutputSocket>("out", node));
		node->AddOutputSocket("out2", std::make_shared<MATD::GRAPH::OutputSocket>("out2", node));
	}

	UUID id = MATD::CORE::UUIDGenerator::GenerateUUID();
	node->GetOutputSocket("out")->SetArgument(Argument::ArgumentFactory(id.str(), DATA_TYPES::NUMBER1));

	id = MATD::CORE::UUIDGenerator::GenerateUUID();
	node->GetOutputSocket("out2")->SetArgument(Argument::ArgumentFactory(id.str(), DATA_TYPES::NUMBER1));

	this->Update();
}
