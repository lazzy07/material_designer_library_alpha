#include "Lut3Input.hpp"
#include "../../core/UUIDGenerator.hpp"
#include "../../graphs/core/OutputSocket.hpp"

MATD::FUNC::DATA::INPUT::Lut3Input::Lut3Input(MATD::GRAPH::Node* node) : DataPrimitiveFunction(node)
{
	MATD_CORE_TRACE("MATD::FUNC Lut3Input function created");

	{
		node->SetOutputSocket("out", std::make_shared<MATD::GRAPH::OutputSocket>("out", node));
	}
}

void MATD::FUNC::DATA::INPUT::Lut3Input::Calculate()
{
}

