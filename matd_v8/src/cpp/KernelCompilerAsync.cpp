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
	MATD_CORE_TRACE("MATD::V8 Compilation Process Started");
	m_KernelError = this->m_MaterialDesignerInstance->CompileKernel();
	MATD_CORE_TRACE("MATD::V8 Compilation Process Finished");
}

void MATD::V8::KernelCompilerAsync::OnOK()
{
	auto arg = Napi::String::New(this->Env(), m_KernelError.size() > 0 ? m_KernelError.c_str() : "");
	Callback().Call({arg});
}

