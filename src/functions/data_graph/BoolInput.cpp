#include "BoolInput.hpp"
#include "../../core/UUIDGenerator.hpp"
#include "../../graphs/core/OutputSocket.hpp"

MATD::FUNC::DATA::INPUT::BoolInput::BoolInput(MATD::GRAPH::Node* node) : DataPrimitiveFunction(node)
{
	MATD_CORE_TRACE("MATD::FUNC BoolInput function created");

	{
		node->SetOutputSocket("out", std::make_shared<MATD::GRAPH::OutputSocket>("out", node));
	}
}

void MATD::FUNC::DATA::INPUT::BoolInput::Calculate()
{
}