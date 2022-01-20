#include "OutputSocket.hpp"
#include "../../functions/core/Function.hpp"
#include "Connection.hpp"

MATD::GRAPH::OutputSocket::OutputSocket(std::string id, Node* node) : Socket(id, node), m_IsUpdated(false)
{
}

MATD::GRAPH::OutputSocket::~OutputSocket()
{
}

void MATD::GRAPH::OutputSocket::AddConnection(Ref<MATD::GRAPH::Connection> connection)
{
	auto id = connection->GetID();
	m_Connections[id] = connection;
}

MATD::Ref<MATD::FUNC::Argument> MATD::GRAPH::OutputSocket::GetArgument()
{
	return this->GetNode()->GetFunction()->get()->GetOutput();
}
