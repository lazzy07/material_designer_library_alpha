#include "OutputSocket.hpp"
#include "../../functions/core/Function.hpp"

MATD::GRAPH::OutputSocket::OutputSocket(std::string id, Node* node) : Socket(id, node)
{
}

MATD::GRAPH::OutputSocket::~OutputSocket()
{
}

MATD::Ref<MATD::FUNC::Argument> MATD::GRAPH::OutputSocket::GetArgument()
{
	return this->GetNode()->GetFunction()->get()->GetOutput();
}
