#include "UpdaterAsync.hpp"

#include <core/Log.hpp>

MATD::V8::UpdaterAsync::UpdaterAsync(Napi::Function& callback, MATD::CORE::MaterialDesigner* matd, std::string selectedGraphType, std::string updateType, std::string graph) : Napi::AsyncWorker(callback), m_MaterialDesignerInstance(matd),
	m_Graph(graph), m_UpdateType(updateType), m_SelectedGraphType(selectedGraphType)
{
	MATD_CORE_TRACE("MATD::V8 Updater Async Created");
}

MATD::V8::UpdaterAsync::~UpdaterAsync()
{
	MATD_CORE_TRACE("MATD::V8 Updater Async Deleted");
}

void MATD::V8::UpdaterAsync::Execute()
{
	MATD_CORE_TRACE("MATD::V8 Update Process Started");

	if (m_UpdateType == "createNode") {
		MATD_CORE_TRACE("MATD_V8:: Create node request recieved");
		this->m_MaterialDesignerInstance->CreateNode(m_SelectedGraphType, m_Graph);
	}
	else if (m_UpdateType == "removeNode") {
		MATD_CORE_TRACE("MATD_V8:: Remove node request recieved");
		this->m_MaterialDesignerInstance->RemoveNode(m_SelectedGraphType, m_Graph);
	}
	else if (m_UpdateType == "addConnection") {
		MATD_CORE_TRACE("MATD_V8:: Add connection request recieved");
		this->m_MaterialDesignerInstance->AddConnection(m_SelectedGraphType, m_Graph);
	}
	else if (m_UpdateType == "removeConnection") {
		MATD_CORE_TRACE("MATD_V8:: Remove connection request recieved");
		this->m_MaterialDesignerInstance->RemoveConnection(m_SelectedGraphType, m_Graph);
	}
	else if (m_UpdateType == "update") {
		MATD_CORE_TRACE("MATD_V8:: Node data update request recieved");
		this->m_MaterialDesignerInstance->Update(m_SelectedGraphType, m_Graph);
	}
	else {
		MATD_CORE_WARN("MATD::V8 Unknown Update type in UpdateAsync");
	}
	MATD_CORE_TRACE("MATD::V8 Update Process Finished");
}

void MATD::V8::UpdaterAsync::OnOK()
{
	
}

