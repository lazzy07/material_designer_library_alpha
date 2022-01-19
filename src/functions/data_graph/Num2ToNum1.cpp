#include "Num2ToNum1.hpp"
#include "../../core/UUIDGenerator.hpp"
#include "../../graphs/core/OutputSocket.hpp"
#include "../../graphs/core/InputSocket.hpp"

MATD::FUNC::DATA::PROCESS::Num2ToNum1::Num2ToNum1(MATD::GRAPH::Node* node) : DataPrimitiveFunction(node)
{
	MATD_CORE_TRACE("MATD::FUNC Num2ToNum1 function created");

	{
		MATD::UUID uuid = MATD::CORE::UUIDGenerator::GenerateUUID();
		node->AddInputSocket(uuid.str(), std::make_shared<MATD::GRAPH::InputSocket>(uuid.str(), node, GetArgument("2711")));
	}

	{
		MATD::UUID uuid = MATD::CORE::UUIDGenerator::GenerateUUID();
		node->SetOutputSocket(uuid.str(), std::make_shared<MATD::GRAPH::OutputSocket>(uuid.str(), node));
	}
}

void MATD::FUNC::DATA::PROCESS::Num2ToNum1::Calculate()
{
}
