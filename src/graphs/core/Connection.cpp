#include "Connection.hpp"

MATD::GRAPH::Connection::Connection(std::string id, Ref<MATD::GRAPH::InputSocket> input, Ref<MATD::GRAPH::OutputSocket> output): m_ID(id), m_Input(input), m_Output(output)
{
	this->GetID();
	this->GetInput()->GetID();
	this->GetOutput()->GetID();
	//MATD_CORE_INFO("Connection Created ID: {} Input: {} Output: {}", );
}

MATD::GRAPH::Connection::~Connection()
{
	MATD_CORE_INFO("Connection Deleted ID: {}", this->GetID());
}
