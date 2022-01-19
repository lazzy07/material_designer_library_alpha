#include "MultiplyNumber.hpp"
#include "../../core/UUIDGenerator.hpp"
#include "../../graphs/core/OutputSocket.hpp"
#include "../../graphs/core/InputSocket.hpp"

MATD::FUNC::DATA::PROCESS::MultiplyNumber::MultiplyNumber(MATD::GRAPH::Node* node) : DataPrimitiveFunction(node)
{
	MATD_CORE_TRACE("MATD::FUNC MultiplyNumber function created");

	{
		MATD::UUID uuid = MATD::CORE::UUIDGenerator::GenerateUUID();
		node->AddInputSocket(uuid.str(), std::make_shared<MATD::GRAPH::InputSocket>(uuid.str(), node, GetArgument("1611")));
	}

	{
		MATD::UUID uuid = MATD::CORE::UUIDGenerator::GenerateUUID();
		node->AddInputSocket(uuid.str(), std::make_shared<MATD::GRAPH::InputSocket>(uuid.str(), node, GetArgument("1612")));
	}

	{
		MATD::UUID uuid = MATD::CORE::UUIDGenerator::GenerateUUID();
		node->SetOutputSocket(uuid.str(), std::make_shared<MATD::GRAPH::OutputSocket>(uuid.str(), node));
	}
}

void MATD::FUNC::DATA::PROCESS::MultiplyNumber::Calculate()
{
}

