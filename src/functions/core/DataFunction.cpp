#include "DataFunction.hpp"
#include "../data_graph/DataGraphFunctions.hpp"

MATD::Ref<MATD::FUNC::DataFunction> MATD::FUNC::DataFunction::FunctionFactory(MATD::GRAPH::Node* node, const std::string& initialID, MATD::JSON JSONObj)
{
	if (initialID == "1" || initialID == "2") {
		auto func = std::make_shared<MATD::FUNC::DATA::INPUT::Num1Input>(node);

		func->Init(JSONObj);
		return func;
	}
	else if (initialID == "3") {
		auto func = std::make_shared<MATD::FUNC::DATA::INPUT::Num1Input>(node);
		func->Init(JSONObj);
		return func;
	}

	return nullptr;
}

MATD::FUNC::DataFunction::DataFunction(MATD::GRAPH::Node* node) : Function(node)
{
}

MATD::FUNC::DataFunction::~DataFunction()
{
}
