#include "Function.hpp"

MATD::FUNC::Function::Function(MATD::GRAPH::Node* node) : m_Node(node)
{

}

MATD::FUNC::Function::~Function()
{
}

void MATD::FUNC::Function::SetArgument(std::string id, DATA_TYPES dataType, void* data)
{
	auto arg = std::make_shared<Argument>();

	arg->id = id;
	arg->dataType = dataType;
	arg->data = data;

	m_Arguments.insert(std::pair<std::string, Ref<Argument>>(id, arg));
}
