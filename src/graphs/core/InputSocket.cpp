#include "InputSocket.hpp"
#include "Connection.hpp"

MATD::GRAPH::InputSocket::InputSocket(std::string id, Node* node, Ref<FUNC::Argument> argument) : Socket(id, node), m_Argument(std::move(argument))
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

void MATD::GRAPH::InputSocket::AddConnection(Ref<MATD::GRAPH::Connection> connection)
{
	m_Connection = connection;
}

void MATD::GRAPH::InputSocket::RemoveConnection(const std::string& id)
{
	m_Connection = nullptr;
}

bool MATD::GRAPH::InputSocket::IsUpdated()
{
	if(this->NoOfConnections())
	{
		if(this->GetConnection("")->GetUpdateStatus() == CONNECTION_UPDATE_STATUS::UPDATED)
		{
			return true;
		}

		return false;
	}

	return true;
}

MATD::Ref<MATD::FUNC::Argument> MATD::GRAPH::InputSocket::GetArgument()
{
	if (this->NoOfConnections() > 0) {
		if (const auto output = m_Connection->GetOutput()) {
			return output->GetArgument();
		}
	}

	return this->m_Argument;
}

inline void MATD::GRAPH::InputSocket::Update()
{
	this->GetNode()->GetFunction()->get()->Update();
}
