#include "Num1ToCol3.hpp"
#include "../../core/UUIDGenerator.hpp"
#include "../../graphs/core/OutputSocket.hpp"
#include "../../graphs/core/InputSocket.hpp"

MATD::FUNC::DATA::PROCESS::Num1ToCol3::Num1ToCol3(MATD::GRAPH::Node* node) : DataPrimitiveFunction(node)
{
	MATD_CORE_TRACE("MATD::FUNC Num1ToCol3 function created");

}

void MATD::FUNC::DATA::PROCESS::Num1ToCol3::Calculate()
{
}

void MATD::FUNC::DATA::PROCESS::Num1ToCol3::SetSocketArguments()
{
	auto node = this->GetNode();

	{
		node->AddInputSocket("1", std::make_shared<MATD::GRAPH::InputSocket>("1", node, GetArgument("2311")));
		node->AddInputSocket("2", std::make_shared<MATD::GRAPH::InputSocket>("2", node, GetArgument("2312")));
		node->AddInputSocket("3", std::make_shared<MATD::GRAPH::InputSocket>("3", node, GetArgument("2313")));
		node->AddOutputSocket("out", std::make_shared<MATD::GRAPH::OutputSocket>("out", node));
	}
}
