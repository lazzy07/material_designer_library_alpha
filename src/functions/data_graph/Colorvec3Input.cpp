#include "Colorvec3Input.hpp"
#include "../../core/UUIDGenerator.hpp"
#include "../../graphs/core/OutputSocket.hpp"
#include "../../graphs/core/InputSocket.hpp"

MATD::FUNC::DATA::INPUT::Colorvec3Input::Colorvec3Input(MATD::GRAPH::Node* node) : DataPrimitiveInput(node)
{
	MATD_CORE_TRACE("MATD::FUNC Colorvec1Input function created");
}

void MATD::FUNC::DATA::INPUT::Colorvec3Input::Calculate()
{
	auto input = this->GetNode()->GetInputSocket("1");
	auto arg = input->GetArgument();
	this->GetNode()->GetOutputSocket("out")->GetArgument()->SetData<ColorVec3>(*(arg->GetData<ColorVec3>()));
}

void MATD::FUNC::DATA::INPUT::Colorvec3Input::SetSocketArguments()
{
	auto node = this->GetNode();
	{
		node->AddInputSocket("1", std::make_shared<MATD::GRAPH::InputSocket>("1", node, GetArgument("default")));
		node->AddOutputSocket("out", std::make_shared<MATD::GRAPH::OutputSocket>("out", node));
	}
	UUID id = MATD::CORE::UUIDGenerator::GenerateUUID();
	node->GetOutputSocket("out")->SetArgument(Argument::ArgumentFactory(id.str(), DATA_TYPES::COLORVEC3));
	this->Update();
}
