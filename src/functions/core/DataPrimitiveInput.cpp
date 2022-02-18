#include "DataPrimitiveInput.hpp"

MATD::FUNC::DataPrimitiveInput::DataPrimitiveInput(MATD::GRAPH::Node* node) : DataPrimitiveFunction(node)
{
	this->SetFunctionType(FUNCTION_TYPE::INPUT);
}
