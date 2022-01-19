#include "InputSocket.hpp"
#include "Connection.hpp"

MATD::GRAPH::InputSocket::InputSocket(std::string id, Node* node, Ref<MATD::FUNC::Argument> argument) : Socket(id, node), m_Argument(argument)
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

MATD::Ref<MATD::FUNC::Argument> MATD::GRAPH::InputSocket::GetArgument()
{
	if (this->NoOfConnections() == 0) {
		return this->m_Argument;
	}
	else {
		return m_Connection->GetInput()->GetArgument();
	}
}

bool MATD::GRAPH::InputSocket::GetUpdateStatus()
{
	auto connection = this->GetConnection("");
	if (connection) {
		auto input = connection->GetInput();
		return input->GetUpdateStatus();
	}
	else {
		return true;
	}
}
