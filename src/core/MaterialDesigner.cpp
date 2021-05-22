#include <matd/core/MaterialDesigner.hpp>
#include <CL/opencl.h>
#include <matd/core/Log.hpp>


MATD::CORE::MaterialDesigner::MaterialDesigner(){
	Log::Init();
	MATD_CORE_TRACE("Logger Initialized");
};

MATD::CORE::MaterialDesigner::~MaterialDesigner(){
  
}