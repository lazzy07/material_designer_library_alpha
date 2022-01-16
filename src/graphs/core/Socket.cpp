#include "Socket.hpp"
#include "Connection.hpp"

MATD::GRAPH::Socket::Socket(std::string id, MATD::GRAPH::Node* node, Ref<MATD::FUNC::Argument> argument) : m_Argument(argument), m_Node(node), m_ID(id)
{
	MATD_CORE_TRACE("Socket created ID: {} node ID: {}", m_ID, node->GetID());
}

MATD::GRAPH::Socket::~Socket()
{
}

MATD::Ref<MATD::FUNC::Argument> MATD::GRAPH::Socket::GetArgument()
{
	if (this->NoOfConnections() == 0) {
		return m_Argument;
	}
	else {
		return m_Connections->GetInput()->GetArgument();
	}
}
