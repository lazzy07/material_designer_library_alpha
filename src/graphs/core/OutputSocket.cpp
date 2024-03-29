#include "OutputSocket.hpp"
#include "../../functions/core/Function.hpp"
#include "Connection.hpp"
#include "../../core/Time.hpp"

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

void MATD::GRAPH::OutputSocket::RemoveConnection(const std::string& id)
{
	m_Connections.erase(id);
}

inline void MATD::GRAPH::OutputSocket::Update()
{
	for (auto elem : this->m_Connections) {
		auto time = MATD::CORE::Time::GetTime();
		elem.second->Update(time);
	}
}

inline MATD::Ref<MATD::FUNC::Argument> MATD::GRAPH::OutputSocket::GetArgument()
{
	return m_Argument;
}
