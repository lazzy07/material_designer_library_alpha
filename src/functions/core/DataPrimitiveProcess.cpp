#include "DataPrimitiveProcess.hpp"

MATD::FUNC::DataPrimitiveProcess::DataPrimitiveProcess(MATD::GRAPH::Node* node) : DataPrimitiveFunction(node)
{
	this->SetFunctionType(FUNCTION_TYPE::PROCESS);
}