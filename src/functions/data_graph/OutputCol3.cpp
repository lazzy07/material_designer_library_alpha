#include "OutputCol3.hpp"
#include "../../core/UUIDGenerator.hpp"
#include "../../graphs/core/OutputSocket.hpp"
#include "../../graphs/core/InputSocket.hpp"

MATD::FUNC::DATA::OUTPUT::OutputCol3::OutputCol3(MATD::GRAPH::Node* node) : DataPrimitiveFunction(node)
{
	MATD_CORE_TRACE("MATD::FUNC OutputCol3 function created");

	{
		MATD::UUID uuid = MATD::CORE::UUIDGenerator::GenerateUUID();
		node->AddInputSocket(uuid.str(), std::make_shared<MATD::GRAPH::InputSocket>(uuid.str(), node, GetArgument("3111")));
	}

	{
		MATD::UUID uuid = MATD::CORE::UUIDGenerator::GenerateUUID();
		node->SetOutputSocket(uuid.str(), std::make_shared<MATD::GRAPH::OutputSocket>(uuid.str(), node));
	}
}

void MATD::FUNC::DATA::OUTPUT::OutputCol3::Calculate()
{
}

void MATD::FUNC::DATA::OUTPUT::OutputCol3::Update()
{
}

void MATD::FUNC::DATA::OUTPUT::OutputCol3::OnComplete()
{
}
