#include "Colorvec3Input.hpp"
#include "../../core/UUIDGenerator.hpp"
#include "../../graphs/core/OutputSocket.hpp"

MATD::FUNC::DATA::INPUT::Colorvec3Input::Colorvec3Input(MATD::GRAPH::Node* node) : DataPrimitiveFunction(node)
{
	MATD_CORE_TRACE("MATD::FUNC Colorvec1Input function created");
}

void MATD::FUNC::DATA::INPUT::Colorvec3Input::Calculate()
{
}

void MATD::FUNC::DATA::INPUT::Colorvec3Input::SetSocketArguments()
{
	auto node = this->GetNode();
	{
		node->SetOutputSocket("out", std::make_shared<MATD::GRAPH::OutputSocket>("out", node));
	}
}

