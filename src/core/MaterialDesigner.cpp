#include <CL/opencl.h>
#include <vector>
#include "MaterialDesigner.hpp"
#include "Log.hpp"
#include "../engine/matd/WorkItem.hpp"
#include "EngineManager.hpp"
std::vector<size_t> MATD::CORE::MaterialDesigner::SelectDevice(uint8_t platformId, uint8_t deviceId)
{
	size_t selectedPlatform = EngineManager::GetEngineInstance()->SelectPlatform(platformId);
	size_t selectedDevice = EngineManager::GetEngineInstance()->SelectDevice(deviceId);

	return std::vector<size_t> {selectedPlatform, selectedDevice};
}

void MATD::CORE::MaterialDesigner::SetKernelLibraryFolder(const std::string& path) const
{
	m_KernelLibrary->AddKernelPath(path);
}

MATD::CORE::MaterialDesigner::MaterialDesigner(){
	Log::Init();
	MATD_CORE_INFO("MATIREAL_DESIGNER::Engine Started");
	MATD_CORE_INFO("LOGGER::Initialized");
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

MATD::GrayscaleTexture* MATD::CORE::MaterialDesigner::CreateGrayscaleTexture(MATD_TEXTURE_BIT_TYPE bitType,
	size_t width, size_t height, buf_type argType)
{
	return MATD::Argument::GrayscaleTexture(bitType, width, height, argType);
}

MATD::ColorTexture* MATD::CORE::MaterialDesigner::CreateColorTexture(MATD_TEXTURE_BIT_TYPE bitType,
	size_t width, size_t height, buf_type argType)
{
	return MATD::Argument::ColorTexture(bitType, width, height, argType);
}

MATD::WorkItem* MATD::CORE::MaterialDesigner::CreateWorkItem(MATD::Kernel* kernel)
{
	return MATD::WorkItem::CreateWorkItem(kernel);
}

MATD::Queue* MATD::CORE::MaterialDesigner::CreateQueue()
{
	return MATD::Queue::CreateQueue();
}

MATD::MatNumber2* MATD::CORE::MaterialDesigner::CreateNumber2(MATD::Number2 val)
{
	return MATD::Argument::Number2(val);
}

MATD::MatColorVec3* MATD::CORE::MaterialDesigner::CreateColorVec3(MATD::ColorVec3 val)
{
	return MATD::Argument::ColorVec3(val);
}

void MATD::CORE::MaterialDesigner::OpenProject(const std::string& JSONString)
{
	this->m_CurrentProject = std::make_shared<MATD::GRAPH::MaterialProject>();
	this->m_CurrentProject->OpenProject(JSONString);
}

void MATD::CORE::MaterialDesigner::UpdateProject(const std::string& JSONString) const
{
	this->m_CurrentProject->UpdateProject(JSONString);
}

void MATD::CORE::MaterialDesigner::SetSelectedGraph(const std::string& graphID) const
{
	this->m_CurrentProject->SetSelectedGraph(graphID);
}

void MATD::CORE::MaterialDesigner::CreateNode(const std::string& selectedGraphType, const std::string& JSONString) const
{
	this->m_CurrentProject->CreateNode(selectedGraphType, JSONString);
}

void MATD::CORE::MaterialDesigner::RemoveNode(const std::string& selectedGraphType, const std::string& JSONString) const
{
	this->m_CurrentProject->RemoveNode(selectedGraphType, JSONString);
}

void MATD::CORE::MaterialDesigner::AddConnection(const std::string& selectedGraphType, const std::string& JSONString) const
{
	this->m_CurrentProject->AddConnection(selectedGraphType, JSONString);
}

void MATD::CORE::MaterialDesigner::RemoveConnection(const std::string& selectedGraphType, const std::string& JSONString) const
{
	this->m_CurrentProject->RemoveConnection(selectedGraphType, JSONString);
}

void MATD::CORE::MaterialDesigner::Update(const std::string& selectedGraphType, const std::string& JSONString) const
{
	this->m_CurrentProject->Update(selectedGraphType, JSONString);
}

std::string MATD::CORE::MaterialDesigner::CompileKernel() const
{
	return this->m_CurrentProject->CompileKernel();
}

MATD::Ref<MATD::GRAPH::MaterialProject> MATD::CORE::MaterialDesigner::GetNodeProject() const
{ return m_CurrentProject; }

void MATD::CORE::MaterialDesigner::UpdateShaderNodeData(int nodeId, MATD::DTYPES::Texture* texture)
{
	if(m_CallShaderNodeChangeCallback)
	{
		m_CallShaderNodeChangeCallback(nodeId, texture);
	}
}
