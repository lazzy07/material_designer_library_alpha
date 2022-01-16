#include "Function.hpp"

MATD::FUNC::Function::Function(MATD::GRAPH::Node* node) : m_Node(node)
{

}

MATD::FUNC::Function::~Function()
{
}

void MATD::FUNC::Function::SetArgument(Ref<Argument> arg)
{
	m_Arguments.insert(std::pair<std::string, Ref<Argument>>(arg->GetID(), arg));
}
