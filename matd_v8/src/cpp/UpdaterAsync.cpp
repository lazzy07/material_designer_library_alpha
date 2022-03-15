#include "UpdaterAsync.hpp"

#include <core/Log.hpp>

MATD::V8::UpdaterAsync::UpdaterAsync(Napi::Function& callback, MATD::CORE::MaterialDesigner* matd, const Napi::String& updateType, const Napi::String& graph) : Napi::AsyncWorker(callback), m_MaterialDesignerInstance(matd), m_UpdateType(updateType), m_Graph(graph)
{
}

MATD::V8::UpdaterAsync::~UpdaterAsync()
{
	MATD_CORE_TRACE("MATD::V8 Kernel Compiler Deleted");
}

void MATD::V8::UpdaterAsync::Execute()
{
	MATD_CORE_TRACE("MATD::V8 Update Process Started");

	auto graph = m_Graph;
	auto updateType = m_UpdateType;

	if (updateType.Utf8Value() == "createNode") {
		MATD_CORE_TRACE("MATD_V8:: Create node request recieved");
		this->m_MaterialDesignerInstance->CreateNode(graph);
	}
	else if (updateType.Utf8Value() == "removeNode") {
		MATD_CORE_TRACE("MATD_V8:: Remove node request recieved");
		this->m_MaterialDesignerInstance->RemoveNode(graph);
	}
	else if (updateType.Utf8Value() == "addConnection") {
		MATD_CORE_TRACE("MATD_V8:: Add connection request recieved");
		this->m_MaterialDesignerInstance->AddConnection(graph);
	}
	else if (updateType.Utf8Value() == "removeConnection") {
		MATD_CORE_TRACE("MATD_V8:: Remove connection request recieved");
		this->m_MaterialDesignerInstance->RemoveConnection(graph);
	}
	else if (updateType.Utf8Value() == "update") {
		MATD_CORE_TRACE("MATD_V8:: Node data update request recieved");
		this->m_MaterialDesignerInstance->Update(graph);
	}
	else {
		MATD_CORE_WARN("MATD::V8 Unknown Update type in UpdateAsync");
	}
	MATD_CORE_TRACE("MATD::V8 Update Process Finished");
}

void MATD::V8::UpdaterAsync::OnOK()
{
	Callback().Call({});
}

