#include <CL/opencl.h>
#include "MaterialDesigner.hpp"
#include "Log.hpp"

MATD::CORE::MaterialDesigner::MaterialDesigner(){
	Log::Init();
	MATD_CORE_INFO("MATIREAL_DESIGNER::Engine Started");
	MATD_CORE_TRACE("LOGGER::Initialized");
	EngineManager::SelectEngine(SUPPORTED_ENGINES::OPEN_CL);
};

MATD::CORE::MaterialDesigner::~MaterialDesigner(){
  MATD_CORE_INFO("MATERIAL_DESIGNER::Closed");
}