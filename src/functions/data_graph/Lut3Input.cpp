#include "Lut3Input.hpp"
#include "../../core/UUIDGenerator.hpp"
#include "../../graphs/core/OutputSocket.hpp"
#include "../../graphs/core/InputSocket.hpp"

MATD::FUNC::DATA::INPUT::Lut3Input::Lut3Input(MATD::GRAPH::Node* node) : DataPrimitiveFunction(node)
{
	MATD_CORE_TRACE("MATD::FUNC Lut3Input function created");

}

void MATD::FUNC::DATA::INPUT::Lut3Input::Calculate()
{
	auto input = this->GetNode()->GetInputSocket("1");
	auto arg = input->GetArgument();
	this->GetNode()->GetOutputSocket("out")->GetArgument()->SetData<Lut3>(*(arg->GetData<Lut3>()));
}

void MATD::FUNC::DATA::INPUT::Lut3Input::SetSocketArguments()
{
	auto node = this->GetNode();

	{
		node->AddInputSocket("1", std::make_shared<MATD::GRAPH::InputSocket>("1", node, GetArgument("1111")));
		node->AddOutputSocket("out", std::make_shared<MATD::GRAPH::OutputSocket>("out", node));
	}

	UUID id = MATD::CORE::UUIDGenerator::GenerateUUID();
	node->GetOutputSocket("out")->SetArgument(Argument::ArgumentFactory(id.str(), DATA_TYPES::LUT3));
	this->Update();
}

