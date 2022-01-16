#include "InputSocket.hpp"

MATD::GRAPH::InputSocket::InputSocket(std::string id, Node* node, Ref<MATD::FUNC::Argument> argument) : Socket(id, node, argument)
{
}

MATD::GRAPH::InputSocket::~InputSocket()
{
}

inline int MATD::GRAPH::InputSocket::NoOfConnections()
{
	if (m_Connection != nullptr) {
		return 1;
	}

	return 0;
}
