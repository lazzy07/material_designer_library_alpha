#include "Num1ToNum2.hpp"
#include "../../core/UUIDGenerator.hpp"
#include "../../graphs/core/OutputSocket.hpp"
#include "../../graphs/core/InputSocket.hpp"

MATD::FUNC::DATA::PROCESS::Num1ToNum2::Num1ToNum2(MATD::GRAPH::Node* node) : DataPrimitiveFunction(node)
{
	MATD_CORE_TRACE("MATD::FUNC Num1ToNum2 function created");

	{
		MATD::UUID uuid = MATD::CORE::UUIDGenerator::GenerateUUID();
		node->AddInputSocket("1", std::make_shared<MATD::GRAPH::InputSocket>("1", node, GetArgument("2611")));
		node->AddInputSocket("2", std::make_shared<MATD::GRAPH::InputSocket>("2", node, GetArgument("2612")));
		node->SetOutputSocket("out", std::make_shared<MATD::GRAPH::OutputSocket>("out", node));
	}
}

void MATD::FUNC::DATA::PROCESS::Num1ToNum2::Calculate()
{
}
