#include "DataPrimitiveFunction.hpp"

MATD::FUNC::DataPrimitiveFunction::DataPrimitiveFunction(MATD::GRAPH::Node* node) : DataFunction(node)
{
}

MATD::FUNC::DataPrimitiveFunction::~DataPrimitiveFunction()
{
}

void MATD::FUNC::DataPrimitiveFunction::Init(MATD::JSON JSONObj)
{
	MATD::JSON data = JSONObj["data"];
	for (MATD::JSON::iterator it = data.begin(); it != data.end(); ++it) {
		auto arg = MATD::FUNC::Argument::ArgumentFactory(*it);
		this->SetArgument(arg);
	}
}
