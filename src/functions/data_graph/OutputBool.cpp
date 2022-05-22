#include "OutputBool.hpp"
#include "../../core/UUIDGenerator.hpp"
#include "../../graphs/core/OutputSocket.hpp"
#include "../../graphs/core/InputSocket.hpp"

MATD::FUNC::DATA::OUTPUT::OutputBool::OutputBool(MATD::GRAPH::Node* node) : DataPrimitiveOutput(node)
{
	MATD_CORE_TRACE("MATD::FUNC OutputBool function created");
}

void MATD::FUNC::DATA::OUTPUT::OutputBool::Calculate()
{
	auto input = this->GetNode()->GetInputSocket("1");
	auto arg = input->GetArgument();
	this->GetNode()->GetOutputSocket("out")->GetArgument()->SetData<bool>(*(arg->GetData<bool>()));
}

void MATD::FUNC::DATA::OUTPUT::OutputBool::SetSocketArguments()
{
	auto node = this->GetNode();

	{
		node->AddInputSocket("1", std::make_shared<MATD::GRAPH::InputSocket>("1", node, GetArgument("default")));
		node->AddOutputSocket("out", std::make_shared<MATD::GRAPH::OutputSocket>("out", node));
	}
}
