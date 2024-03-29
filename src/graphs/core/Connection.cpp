#include "Connection.hpp"

MATD::GRAPH::Connection::Connection(std::string id, Ref<MATD::GRAPH::InputSocket> input, Ref<MATD::GRAPH::OutputSocket> output): m_ID(id), m_Input(input), m_Output(output)
{
	MATD_CORE_INFO("Connection Created ID: {} Input: {} Output: {}", this->GetID(), this->GetInput()->GetID(), this->GetOutput()->GetID());
}

MATD::GRAPH::Connection::~Connection()
{
	MATD_CORE_INFO("Connection Deleted ID: {}", this->GetID());
}

void MATD::GRAPH::Connection::Update(uint64_t time)
{
	if (m_UpdatedTime <= time) {
		m_UpdateStatus = CONNECTION_UPDATE_STATUS::UPDATED;
		m_UpdatedTime = time;

		auto node = m_Input->GetNode();
		for (auto inputSocket : node->GetInputSockets()) {
			auto connection = inputSocket.second->GetConnection("");
			if (connection) {
				if (connection->GetUpdateStatus() == CONNECTION_UPDATE_STATUS::IN_PROGRESS) {
					return;
				}
			}
		}
		node->GetFunction()->get()->Update();
	}
}
