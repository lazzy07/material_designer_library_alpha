#include <CL/opencl.h>
#include "MaterialDesigner.hpp"
#include "Log.hpp"

MATD::CORE::MaterialDesigner::MaterialDesigner(){
	Log::Init();
	MATD_CORE_TRACE("LOGGER::Initialized");
	MATD_CORE_INFO("MATD::Engine Started");
	m_EngineManager = MATD::Ref<EngineManager>(new EngineManager());
};

MATD::CORE::MaterialDesigner::~MaterialDesigner(){
  MATD_CORE_TRACE("MATERIAL_DESIGNER::Closed");
}