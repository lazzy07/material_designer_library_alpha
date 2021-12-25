#include <CL/opencl.h>
#include "MaterialDesigner.hpp"
#include "Log.hpp"
#include "../engine/matd/WorkItem.hpp"

void MATD::CORE::MaterialDesigner::SelectDevice(uint8_t platformId, uint8_t deviceId)
{
	EngineManager::GetEngineInstance()->SelectPlatform(platformId);
	EngineManager::GetEngineInstance()->SelectDevice(deviceId);
}

void MATD::CORE::MaterialDesigner::SetKenelLibraryFolder(const std::string& path)
{
	m_KernelLibrary->AddKernelPath(path);
}

MATD::CORE::MaterialDesigner::MaterialDesigner(){
	Log::Init();
	MATD_CORE_INFO("MATIREAL_DESIGNER::Engine Started");
	MATD_CORE_TRACE("LOGGER::Initialized");
	EngineManager::SelectEngine(SUPPORTED_ENGINES::OPEN_CL);
	m_KernelLibrary = std::make_shared<MATD::CORE::KernelLibrary>();
};

MATD::CORE::MaterialDesigner::~MaterialDesigner(){
  MATD_CORE_INFO("MATERIAL_DESIGNER::Closed");
}

MATD::Int* MATD::CORE::MaterialDesigner::CreateInt(int val)
{
	return MATD::Argument::Int(val);
}

MATD::Float* MATD::CORE::MaterialDesigner::CreateFloat(float val)
{
	return MATD::Argument::Float(val);
}

MATD::Buffer* MATD::CORE::MaterialDesigner::CreateBuffer(void* val, size_t size, size_t elem_size, buf_type argType)
{
	return MATD::Argument::Buffer(val, size, elem_size, argType);
}

MATD::Image* MATD::CORE::MaterialDesigner::CreateImage(void* val, size_t size, size_t elem_size, size_t width, size_t height, buf_type argType)
{
	return MATD::Argument::Image(val, size, elem_size, width, height, argType);
}

MATD::WorkItem* MATD::CORE::MaterialDesigner::CreateWorkItem(const std::string& kernelName)
{
	MATD::Kernel* kernel = m_KernelLibrary->GetKernel(kernelName);
	return MATD::WorkItem::CreateWorkItem(kernel);
}

MATD::Queue* MATD::CORE::MaterialDesigner::CreateQueue()
{
	return MATD::Queue::CreateQueue();
}

void MATD::CORE::MaterialDesigner::OpenProject(const std::string& JSONString)
{
	this->m_CurrentProject = std::make_shared<MATD::GRAPH::NodeProject>();
	this->m_CurrentProject->OpenProject(JSONString);
}

void MATD::CORE::MaterialDesigner::UpdateProject(const std::string& JSONString)
{
	this->m_CurrentProject->UpdateProject(JSONString);
}

void MATD::CORE::MaterialDesigner::SetSelectedGraph(const std::string& graphID)
{
	this->m_CurrentProject->SetSelectedGraph(graphID);
}

void MATD::CORE::MaterialDesigner::UpdateGraph(const std::string& JSONString)
{
	this->m_CurrentProject->UpdateGraph(JSONString);
}
