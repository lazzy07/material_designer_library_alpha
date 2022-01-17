#include "Num1Input.hpp"
#include "../../core/UUIDGenerator.hpp"
#include "../../graphs/core/OutputSocket.hpp"

MATD::FUNC::DATA::INPUT::Num1Input::Num1Input(MATD::GRAPH::Node* node) : DataPrimitiveFunction(node)
{
	MATD::UUID uuid = MATD::CORE::UUIDGenerator::GenerateUUID();
	node->SetOutputSocket(uuid.str(), std::make_shared<MATD::GRAPH::OutputSocket>(uuid.str(), node));
	MATD_CORE_TRACE("MATD::FUNC Number1Input function created");
}

void MATD::FUNC::DATA::INPUT::Num1Input::Calculate()
{
}

void MATD::FUNC::DATA::INPUT::Num1Input::Update()
{
}

void MATD::FUNC::DATA::INPUT::Num1Input::OnComplete()
{
}
