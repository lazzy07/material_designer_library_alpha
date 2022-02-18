#include "Col3ToNum1.hpp"
#include "../../core/UUIDGenerator.hpp"
#include "../../graphs/core/OutputSocket.hpp"
#include "../../graphs/core/InputSocket.hpp"

MATD::FUNC::DATA::PROCESS::Col3ToNum1::Col3ToNum1(MATD::GRAPH::Node* node) : DataPrimitiveProcess(node)
{
	MATD_CORE_TRACE("MATD::FUNC Col3ToNum1 function created");
}

void MATD::FUNC::DATA::PROCESS::Col3ToNum1::Calculate()
{
	auto input = this->GetNode()->GetInputSocket("1");
	auto arg = input->GetArgument();

	auto data = arg->GetData<ColorVec3>();

	this->GetNode()->GetOutputSocket("out")->GetArgument()->SetData<Number1>(data->r);
	this->GetNode()->GetOutputSocket("out2")->GetArgument()->SetData<Number1>(data->g);
	this->GetNode()->GetOutputSocket("out3")->GetArgument()->SetData<Number1>(data->b);
}

void MATD::FUNC::DATA::PROCESS::Col3ToNum1::SetSocketArguments()
{
	auto node = this->GetNode();

	{
		node->AddInputSocket("1", std::make_shared<MATD::GRAPH::InputSocket>("1", node, GetArgument("2211")));
		node->AddOutputSocket("out", std::make_shared<MATD::GRAPH::OutputSocket>("out", node));
		node->AddOutputSocket("out2", std::make_shared<MATD::GRAPH::OutputSocket>("out2", node));
		node->AddOutputSocket("out3", std::make_shared<MATD::GRAPH::OutputSocket>("out3", node));

		UUID id = MATD::CORE::UUIDGenerator::GenerateUUID();
		node->GetOutputSocket("out")->SetArgument(Argument::ArgumentFactory(id.str(), DATA_TYPES::NUMBER1));
		
		id = MATD::CORE::UUIDGenerator::GenerateUUID();
		node->GetOutputSocket("out2")->SetArgument(Argument::ArgumentFactory(id.str(), DATA_TYPES::NUMBER1));
		
		id = MATD::CORE::UUIDGenerator::GenerateUUID();
		node->GetOutputSocket("out3")->SetArgument(Argument::ArgumentFactory(id.str(), DATA_TYPES::NUMBER1));
		
		this->Update();
	}
}

