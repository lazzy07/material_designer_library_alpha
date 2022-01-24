#include "Lut1Input.hpp"
#include "../../core/UUIDGenerator.hpp"
#include "../../graphs/core/OutputSocket.hpp"

MATD::FUNC::DATA::INPUT::Lut1Input::Lut1Input(MATD::GRAPH::Node* node) : DataPrimitiveFunction(node)
{
	MATD_CORE_TRACE("MATD::FUNC Lut1Input function created");
}

void MATD::FUNC::DATA::INPUT::Lut1Input::Calculate()
{
}

void MATD::FUNC::DATA::INPUT::Lut1Input::SetSocketArguments()
{
	auto node = this->GetNode();

	{
		node->SetOutputSocket("out", std::make_shared<MATD::GRAPH::OutputSocket>("out", node));
	}
}

