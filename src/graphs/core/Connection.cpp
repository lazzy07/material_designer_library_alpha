#include "Connection.hpp"

MATD::GRAPH::Connection::Connection(const std::string& id, Ref<MATD::GRAPH::InputSocket> input, Ref<MATD::GRAPH::OutputSocket> output): m_ID(id), m_Input(input), m_Output(output)
{
	MATD_CORE_INFO("Connection Created ID: {} Input: {} Output: {}", 
		this->GetID(), this->GetInput()->GetID(), this->GetOutput()->GetID());
}

MATD::GRAPH::Connection::~Connection()
{
	MATD_CORE_INFO("Connection Deleted ID: {}", this->GetID());
}
