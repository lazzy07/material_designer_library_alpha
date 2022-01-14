#include "Function.hpp"
#include "../data_graph/DataGraphFunctions.hpp"


MATD::Ref<MATD::FUNC::Function> MATD::FUNC::Function::FunctionFactory(MATD::GRAPH::Node* node, const std::string& initialID, MATD::JSON JSONObj)
{
	if (initialID == "1" || initialID == "2") {
		auto func = std::make_shared<MATD::FUNC::DATA::INPUT::Number1Input>(node);
		func->Init(JSONObj);
		return func;
	}
	else if (initialID == "3") {
		auto func = std::make_shared<MATD::FUNC::DATA::INPUT::Number1Input>(node);
		func->Init(JSONObj);
		return func;
	}

	return nullptr;
}

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
