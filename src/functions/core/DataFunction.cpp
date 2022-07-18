#include "DataFunction.hpp"
#include "../data_graph/DataGraphFunctions.hpp"

MATD::Ref<MATD::FUNC::DataFunction> MATD::FUNC::DataFunction::FunctionFactory(MATD::GRAPH::Node* node, const std::string& initialID, MATD::JSON JSONObj)
{
	if (initialID == "1" || initialID == "2" || initialID == "6" || initialID == "8") {
		auto func = std::make_shared<MATD::FUNC::DATA::INPUT::Num1Input>(node);
		func->Init(JSONObj);
		return func;
	}
	else if (initialID == "3" || initialID == "9") {
		auto func = std::make_shared<MATD::FUNC::DATA::INPUT::Num2Input>(node);
		func->Init(JSONObj);
		return func;
	}
	else if (initialID == "4") {
		auto func = std::make_shared<MATD::FUNC::DATA::INPUT::BoolInput>(node);
		func->Init(JSONObj);
		return func;
	}
	else if (initialID == "5") {
		auto func = std::make_shared<MATD::FUNC::DATA::INPUT::BoolInput>(node);
		func->Init(JSONObj);
		return func;
	}
	else if (initialID == "10") {
		auto func = std::make_shared<MATD::FUNC::DATA::INPUT::Lut1Input>(node);
		func->Init(JSONObj);
		return func;
	}
	else if (initialID == "11") {
		auto func = std::make_shared<MATD::FUNC::DATA::INPUT::Lut3Input>(node);
		func->Init(JSONObj);
		return func;
	}
	else if (initialID == "12") {
		auto func = std::make_shared<MATD::FUNC::DATA::INPUT::Colorvec1Input>(node);
		func->Init(JSONObj);
		return func;
	}
	else if (initialID == "13") {
		auto func = std::make_shared<MATD::FUNC::DATA::INPUT::Colorvec3Input>(node);
		func->Init(JSONObj);
		return func;
	}
	else if (initialID == "14") {
		auto func = std::make_shared<MATD::FUNC::DATA::PROCESS::AddNumber>(node);
		func->Init(JSONObj);
		return func;
	}
	else if (initialID == "15") {
		auto func = std::make_shared<MATD::FUNC::DATA::PROCESS::SubstractNumber>(node);
		func->Init(JSONObj);
		return func;
	}
	else if (initialID == "16") {
		auto func = std::make_shared<MATD::FUNC::DATA::PROCESS::MultiplyNumber>(node);
		func->Init(JSONObj);
		return func;
	}
	else if (initialID == "17") {
		auto func = std::make_shared<MATD::FUNC::DATA::PROCESS::DivideNumber>(node);
		func->Init(JSONObj);
		return func;
	}
	else if (initialID == "18") {
		auto func = std::make_shared<MATD::FUNC::DATA::PROCESS::PowerNumber>(node);
		func->Init(JSONObj);
		return func;
	}
	else if (initialID == "19") {
		auto func = std::make_shared<MATD::FUNC::DATA::PROCESS::SqrtNumber>(node);
		func->Init(JSONObj);
		return func;
	}
	else if (initialID == "20") {
		auto func = std::make_shared<MATD::FUNC::DATA::PROCESS::Col1ToNum1>(node);
		func->Init(JSONObj);
		return func;
	}
	else if (initialID == "21") {
		auto func = std::make_shared<MATD::FUNC::DATA::PROCESS::Num1ToCol1>(node);
		func->Init(JSONObj);
		return func;
	}
	else if (initialID == "22") {
		auto func = std::make_shared<MATD::FUNC::DATA::PROCESS::Col3ToNum1>(node);
		func->Init(JSONObj);
		return func;
	}
	else if (initialID == "23") {
		auto func = std::make_shared<MATD::FUNC::DATA::PROCESS::Num1ToCol3>(node);
		func->Init(JSONObj);
		return func;
	}
	else if (initialID == "24") {
		auto func = std::make_shared<MATD::FUNC::DATA::PROCESS::BoolToNum1>(node);
		func->Init(JSONObj);
		return func;
	}
	else if (initialID == "25") {
		auto func = std::make_shared<MATD::FUNC::DATA::PROCESS::Num1ToBool>(node);
		func->Init(JSONObj);
		return func;
	}
	else if (initialID == "26") {
		auto func = std::make_shared<MATD::FUNC::DATA::PROCESS::Num1ToNum2>(node);
		func->Init(JSONObj);
		return func;
	}
	else if (initialID == "27") {
		auto func = std::make_shared<MATD::FUNC::DATA::PROCESS::Num2ToNum1>(node);
		func->Init(JSONObj);
		return func;
	}
	else if (initialID == "28") {
		auto func = std::make_shared<MATD::FUNC::DATA::OUTPUT::OutputNum1>(node);
		func->Init(JSONObj);
		return func;
	}
	else if (initialID == "29") {
		auto func = std::make_shared<MATD::FUNC::DATA::OUTPUT::OutputNum2>(node);
		func->Init(JSONObj);
		return func;
	}
	else if (initialID == "30") {
		auto func = std::make_shared<MATD::FUNC::DATA::OUTPUT::OutputCol1>(node);
		func->Init(JSONObj);
		return func;
	}
	else if (initialID == "31") {
		auto func = std::make_shared<MATD::FUNC::DATA::OUTPUT::OutputCol3>(node);
		func->Init(JSONObj);
		return func;
	}
	else if (initialID == "32") {
		auto func = std::make_shared<MATD::FUNC::DATA::OUTPUT::OutputBool>(node);
		func->Init(JSONObj);
		return func;
	}
	else if (initialID == "33") {
		auto func = std::make_shared<MATD::FUNC::DATA::OUTPUT::OutputLut1>(node);
		func->Init(JSONObj);
		return func;
	}
	else if (initialID == "34") {
		auto func = std::make_shared<MATD::FUNC::DATA::OUTPUT::OutputLut3>(node);
		func->Init(JSONObj);
		return func;
	} else if (initialID == "35")
	{
		auto func = std::make_shared<MATD::FUNC::DATA::OUTPUT::DataRef>(node);
		func->Init(JSONObj);
		return func;
	}
	
	auto func = std::make_shared<MATD::FUNC::DATA::PROCESS::DataGraphNode>(node);
	func->Init(JSONObj);
	return func;
}

MATD::FUNC::DataFunction::DataFunction(MATD::GRAPH::Node* node) : Function(node)
{
}

MATD::FUNC::DataFunction::~DataFunction()
{
}