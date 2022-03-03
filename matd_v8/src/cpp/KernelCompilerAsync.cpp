#include "KernelCompilerAsync.hpp"
#include <core/Log.hpp>

MATD::V8::KernelCompilerAsync::KernelCompilerAsync(Napi::Function& callback, MATD::CORE::MaterialDesigner* matd) : Napi::AsyncWorker(callback), m_MaterialDesignerInstance(matd)
{
}

MATD::V8::KernelCompilerAsync::~KernelCompilerAsync()
{
	MATD_CORE_TRACE("MATD::V8 Kernel Compiler Deleted");
}

void MATD::V8::KernelCompilerAsync::Execute()
{
	std::string error = this->m_MaterialDesignerInstance->CompileKernel();
}

void MATD::V8::KernelCompilerAsync::OnOk()
{
	Callback().Call({});
}
