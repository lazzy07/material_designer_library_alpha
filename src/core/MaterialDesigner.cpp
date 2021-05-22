#include <matd/core/MaterialDesigner.hpp>
#include <CL/opencl.h>
#include <matd/core/Log.hpp>


MATD::CORE::MaterialDesigner::MaterialDesigner(){
	Log::Init();
	MATD_CORE_TRACE("LOGGER::Initialized");

	m_ContextManager = MATD::Ref<ContextManager>(new ContextManager());
};

MATD::CORE::MaterialDesigner::~MaterialDesigner(){
  MATD_CORE_TRACE("MATERIAL_DESIGNER::CLosed");
}