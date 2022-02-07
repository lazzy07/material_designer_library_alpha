#include "Colorvec1Input.hpp"
#include "../../core/UUIDGenerator.hpp"
#include "../../graphs/core/OutputSocket.hpp"
#include "../../graphs/core/InputSocket.hpp"

MATD::FUNC::DATA::INPUT::Colorvec1Input::Colorvec1Input(MATD::GRAPH::Node* node) : DataPrimitiveFunction(node)
{
	MATD_CORE_TRACE("MATD::FUNC Colorvec1Input function created");

}

void MATD::FUNC::DATA::INPUT::Colorvec1Input::Calculate()
{
	auto input = this->GetNode()->GetInputSocket("1");
	auto arg = input->GetArgument();
	this->GetNode()->GetOutputSocket("out")->GetArgument()->SetData<ColorVec1>(*(arg->GetData<ColorVec1>()));
}

void MATD::FUNC::DATA::INPUT::Colorvec1Input::SetSocketArguments()
{
	auto node = this->GetNode();
	{
		node->AddInputSocket("1", std::make_shared<MATD::GRAPH::InputSocket>("1", node, GetArgument("1211")));
		node->AddOutputSocket("out", std::make_shared<MATD::GRAPH::OutputSocket>("out", node));
	}
	UUID id = MATD::CORE::UUIDGenerator::GenerateUUID();
	node->GetOutputSocket("out")->SetArgument(Argument::ArgumentFactory(id.str(), DATA_TYPES::COLORVEC1));
	this->Update();
}

