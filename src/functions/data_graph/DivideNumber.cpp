#include "DivideNumber.hpp"
#include "../../core/UUIDGenerator.hpp"
#include "../../graphs/core/OutputSocket.hpp"
#include "../../graphs/core/InputSocket.hpp"

MATD::FUNC::DATA::PROCESS::DivideNumber::DivideNumber(MATD::GRAPH::Node* node) : DataPrimitiveFunction(node)
{
	MATD_CORE_TRACE("MATD::FUNC DivideNumber function created");

	{
		MATD::UUID uuid = MATD::CORE::UUIDGenerator::GenerateUUID();
		node->AddInputSocket(uuid.str(), std::make_shared<MATD::GRAPH::InputSocket>(uuid.str(), node, GetArgument("1711")));
	}

	{
		MATD::UUID uuid = MATD::CORE::UUIDGenerator::GenerateUUID();
		node->AddInputSocket(uuid.str(), std::make_shared<MATD::GRAPH::InputSocket>(uuid.str(), node, GetArgument("1712")));
	}

	{
		MATD::UUID uuid = MATD::CORE::UUIDGenerator::GenerateUUID();
		node->SetOutputSocket(uuid.str(), std::make_shared<MATD::GRAPH::OutputSocket>(uuid.str(), node));
	}
}

void MATD::FUNC::DATA::PROCESS::DivideNumber::Calculate()
{
}

void MATD::FUNC::DATA::PROCESS::DivideNumber::Update()
{
}

void MATD::FUNC::DATA::PROCESS::DivideNumber::OnComplete()
{
}
