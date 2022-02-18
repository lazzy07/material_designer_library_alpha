#include "DataPrimitiveOutput.hpp"

MATD::FUNC::DataPrimitiveOutput::DataPrimitiveOutput(MATD::GRAPH::Node* node) : DataPrimitiveFunction(node)
{
	this->SetFunctionType(FUNCTION_TYPE::OUTPUT);
}