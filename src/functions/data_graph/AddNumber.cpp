#include "AddNumber.hpp"
#include "../../core/UUIDGenerator.hpp"
#include "../../graphs/core/OutputSocket.hpp"
#include "../../graphs/core/InputSocket.hpp"

MATD::FUNC::DATA::PROCESS::AddNumber1::AddNumber1(MATD::GRAPH::Node* node) : DataPrimitiveFunction(node)
{
	MATD_CORE_TRACE("MATD::FUNC AddNumber function created");

	{
		node->AddInputSocket("", std::make_shared<MATD::GRAPH::InputSocket>("1", node, GetArgument("1411")));
		node->AddInputSocket("", std::make_shared<MATD::GRAPH::InputSocket>("2", node, GetArgument("1412")));
		node->SetOutputSocket("", std::make_shared<MATD::GRAPH::OutputSocket>("out", node));
	}
}

void MATD::FUNC::DATA::PROCESS::AddNumber1::Calculate()
{
}
