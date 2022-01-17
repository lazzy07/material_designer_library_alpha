#include "Socket.hpp"
#include "Connection.hpp"

MATD::GRAPH::Socket::Socket(std::string id, MATD::GRAPH::Node* node) : m_Node(node), m_ID(id)
{
	MATD_CORE_TRACE("Socket created ID: {} node ID: {}", m_ID, node->GetID());
}

MATD::GRAPH::Socket::~Socket()
{
}
