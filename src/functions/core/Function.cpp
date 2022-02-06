#include "Function.hpp"
#include "../../graphs/core/Node.hpp"
#include "../../graphs/core/OutputSocket.hpp"

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

void MATD::FUNC::Function::Update()
{
	{
		auto outputs = this->GetNode()->GetOutputSockets();

		for (auto output : outputs) {
			output.second->SetUpdateStatus(false);
		}
	}

	this->Calculate();
	this->OnComplete();
}

void MATD::FUNC::Function::OnComplete()
{
	auto outputs = this->GetNode()->GetOutputSockets();

	for (auto output : outputs) {
		output.second->SetUpdateStatus(true);
		output.second->Update();
	}
}
