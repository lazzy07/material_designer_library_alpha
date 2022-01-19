#include "Num1Input.hpp"
#include "../../core/UUIDGenerator.hpp"
#include "../../graphs/core/OutputSocket.hpp"
#include "../../graphs/core/InputSocket.hpp"

MATD::FUNC::DATA::INPUT::Num1Input::Num1Input(MATD::GRAPH::Node* node) : DataPrimitiveFunction(node)
{
	MATD_CORE_TRACE("MATD::FUNC Num1Input function created");

	{
		MATD::UUID uuid = MATD::CORE::UUIDGenerator::GenerateUUID();
		node->AddInputSocket(uuid.str(), std::make_shared<MATD::GRAPH::InputSocket>(uuid.str(), node, GetArgument("111")));
	}

	{
		MATD::UUID uuid = MATD::CORE::UUIDGenerator::GenerateUUID();
		node->SetOutputSocket(uuid.str(), std::make_shared<MATD::GRAPH::OutputSocket>(uuid.str(), node));
	}
}

void MATD::FUNC::DATA::INPUT::Num1Input::Calculate()
{
	Ref<MATD::FUNC::Argument> argument1 = this->GetArgument("111");
	this->SetArgument(argument1);
}

