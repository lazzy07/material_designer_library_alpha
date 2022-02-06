#include "Colorvec3Input.hpp"
#include "../../core/UUIDGenerator.hpp"
#include "../../graphs/core/OutputSocket.hpp"
#include "../../graphs/core/InputSocket.hpp"

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
		node->AddInputSocket("1", std::make_shared<MATD::GRAPH::InputSocket>("1", node, GetArgument("1311")));
		node->AddOutputSocket("out", std::make_shared<MATD::GRAPH::OutputSocket>("out", node));
	}
}

