#include "MatdV8.hpp"
#include <core/Core.hpp>
#include <core/EngineManager.hpp>
#include "KernelCompilerAsync.hpp"
#include "UpdaterAsync.hpp"

MATD::V8::MatdV8::MatdV8(const Napi::CallbackInfo& info) : ObjectWrap(info)
{
	const Napi::Env env = info.Env();

  this->m_Matd = new MATD::CORE::MaterialDesigner();
	this->m_Matd->SelectDevice(0, 0);
	MATD::CORE::MaterialDesigner::SetUsedByMaterialDesignerApp(true);
	MATD::CORE::MaterialDesigner::SetCallShaderNodeChangeCallback(MatdV8::CallShaderNodeChangeCallback);
}

MATD::V8::MatdV8::~MatdV8()
{
  delete this->m_Matd;
}

Napi::Function MATD::V8::MatdV8::GetClass(Napi::Env env)
{
  return DefineClass(env, "MatdV8", {
			MatdV8::InstanceMethod("openMaterialProject", &MatdV8::OpenMaterialProject),
			MatdV8::InstanceMethod("updateMaterialProject", &MatdV8::UpdateMaterialProject),
			MatdV8::InstanceMethod("updateMaterialGraph", &MatdV8::UpdateMaterialGraph),
			MatdV8::InstanceMethod("selectCurrentMaterialGraph", &MatdV8::SelectCurrentMaterialGraph),

			MatdV8::InstanceMethod("setComputationDevice", &MatdV8::SetComputationDevice),
			MatdV8::InstanceMethod("getAvailableEngines", &MatdV8::GetAvailableEngines),
			MatdV8::InstanceMethod("setEngine", &MatdV8::SetEngine),
			MatdV8::InstanceMethod("getAvailableDevices", &MatdV8::GetAvailableDevices),
			MatdV8::InstanceMethod("compileKernel", &MatdV8::CompileKernel),
			MatdV8::InstanceMethod("setShaderNodeChangeCallback", &MatdV8::SetShaderNodeChangeCallback)
    });
}

Napi::Value MATD::V8::MatdV8::OpenMaterialProject(const Napi::CallbackInfo& info)
{
	const Napi::Env env = info.Env();

	if (info.Length() < 1) {
		Napi::TypeError::New(env, "NodeProject not found!").ThrowAsJavaScriptException();
		return env.Null();
	}

	if (!info[0].IsString()) {
		Napi::TypeError::New(env, "NodeProject needs to be in string format").ThrowAsJavaScriptException();
		return env.Null();
	}

	const auto project = info[0].As<Napi::String>();
	
	MATD_CORE_TRACE("MATD_V8:: Open NodeProject request recieved");
	this->m_Matd->OpenProject(project);

	return env.Null();
}

Napi::Value MATD::V8::MatdV8::UpdateMaterialProject(const Napi::CallbackInfo& info)
{
	const Napi::Env env = info.Env();

	if (info.Length() < 1) {
		Napi::TypeError::New(env, "MaterialProject not found!").ThrowAsJavaScriptException();
		return env.Null();
	}

	if (!info[0].IsString()) {
		Napi::TypeError::New(env, "MaterialProject needs to be in string format").ThrowAsJavaScriptException();
		return env.Null();
	}

	const auto project = info[0].As<Napi::String>();

	MATD_CORE_TRACE("MATD_V8:: Update MaterialProject request recieved");
	this->m_Matd->UpdateProject(project);

	return env.Null();
}

void MATD::V8::MatdV8::UpdateMaterialGraph(const Napi::CallbackInfo& info)
{
	const Napi::Env env = info.Env();

	if (info.Length() < 3) {
		Napi::TypeError::New(env, "Update type, update data and callback are required").ThrowAsJavaScriptException();
	}

	if (!info[0].IsString()) {
		Napi::TypeError::New(env, "Update type needs to be in string format").ThrowAsJavaScriptException();
	}

	if (!info[1].IsString()) {
		Napi::TypeError::New(env, "Graph needs to be in string format").ThrowAsJavaScriptException();
	}

	if (!info[2].IsFunction()) {
		Napi::TypeError::New(env, "Callback needs to be a function").ThrowAsJavaScriptException();
	}

	Napi::String updateType = info[0].As<Napi::String>();
	Napi::String graph = info[1].As<Napi::String>();
	
	UpdaterAsync* kernelCompiler = new UpdaterAsync(info[2].As<Napi::Function>(), this->m_Matd, updateType.Utf8Value(), graph.Utf8Value());
	kernelCompiler->Queue();
}

Napi::Value MATD::V8::MatdV8::SelectCurrentMaterialGraph(const Napi::CallbackInfo& info)
{
	const Napi::Env env = info.Env();

	if (info.Length() < 1) {
		Napi::TypeError::New(env, "graphID not found!").ThrowAsJavaScriptException();
		return env.Null();
	}

	if (!info[0].IsString()) {
		Napi::TypeError::New(env, "graphID needs to be in string format").ThrowAsJavaScriptException();
		return env.Null();
	}

	const auto graphID = info[0].As<Napi::String>();

	MATD_CORE_TRACE("MATD_V8:: Selected Graph Change request recieved");
	this->m_Matd->SetSelectedGraph(graphID);

	return env.Null();
}

Napi::Value MATD::V8::MatdV8::SetComputationDevice(const Napi::CallbackInfo& info)
{
	const Napi::Env env = info.Env();

  if (info.Length() < 2) {
		Napi::TypeError::New(env, "Setting Computation Device requires 2 Number values").ThrowAsJavaScriptException();
		return env.Null();
  }

  if (!info[0].IsNumber()) {
		Napi::TypeError::New(env, "Vendor type need to be a Int value").ThrowAsJavaScriptException();
		return env.Null();
  }

	if (!info[1].IsNumber()) {
		Napi::TypeError::New(env, "Device type need to be a Int value").ThrowAsJavaScriptException();
		return env.Null();
	}

  this->m_Matd->SelectDevice(info[0].As<Napi::Number>().Uint32Value(), info[1].As<Napi::Number>().Uint32Value());
	return Napi::Boolean::New(env, true);
}

Napi::Value MATD::V8::MatdV8::GetAvailableEngines(const Napi::CallbackInfo& info)
{
	const Napi::Env env = info.Env();
  Napi::Array arr = Napi::Array::New(env);

	const MATD::Ref<std::vector<std::string>> engines = MATD::CORE::EngineManager::GetSupportedEngines();

  for (int i = 0; i < engines->size(); i++) {
    arr.Set(i, Napi::String::New(env, engines->at(i)));
  }

	return arr;
}

Napi::Value MATD::V8::MatdV8::SetEngine(const Napi::CallbackInfo& info)
{
	const Napi::Env env = info.Env();

	if (info.Length() < 1) {
		Napi::TypeError::New(env, "Engine cannot be undefined").ThrowAsJavaScriptException();
		return env.Null();
	}

	if (!info[0].IsNumber()) {
		Napi::TypeError::New(env, "Expects an integer value").ThrowAsJavaScriptException();
		return env.Null();
	}

	MATD::CORE::EngineManager::SelectEngine((MATD::CORE::SUPPORTED_ENGINES)info[0].As<Napi::Number>().Uint32Value());

  return env.Null();
}

Napi::Value MATD::V8::MatdV8::GetAvailableDevices(const Napi::CallbackInfo& info)
{
	Napi::Env env = info.Env();
  
  auto platforms = MATD::CORE::EngineManager::GetEngineInstance()->GetSupportedPlatforms();
  Napi::Array arr = Napi::Array::New(env);

  for (int i = 0; i < platforms.size(); i++) {
    MATD::Ref<MATD::ENGINE::Platform> platform = platforms.at(i);

    auto devices = platform->GetDevices();

    for (int j = 0; j < devices.size(); j++) {
      Napi::Object obj = Napi::Object::New(env);
			obj.Set(Napi::String::New(env, "platformID"), Napi::Number::New(env, platform->GetId()));
			obj.Set(Napi::String::New(env, "deviceID"), Napi::Number::New(env, devices.at(j)->GetId()));
			obj.Set(Napi::String::New(env, "platformName"), Napi::String::New(env, platform->GetName()));
      obj.Set(Napi::String::New(env, "deviceName"), Napi::String::New(env, devices.at(j)->GetDeviceName()));

      arr.Set(arr.Length(), obj);
    }
  }

  return arr;
}

void MATD::V8::MatdV8::CompileKernel(const Napi::CallbackInfo& info)
{
	Napi::Env env = info.Env();

	MATD_CORE_TRACE("MATD_V8:: Compile kernel request recieved");
	KernelCompilerAsync* kernelCompiler = new KernelCompilerAsync(info[0].As<Napi::Function>(), this->m_Matd);
	kernelCompiler->Queue();
}

void MATD::V8::MatdV8::SetShaderNodeChangeCallback(const Napi::CallbackInfo& info)
{
	const Napi::Env env = info.Env();

	if (info.Length() < 1) {
		Napi::TypeError::New(env, "Engine cannot be undefined").ThrowAsJavaScriptException();
	}

	if (!info[0].IsFunction()) {
		Napi::TypeError::New(env, "Expects an integer value").ThrowAsJavaScriptException();
	}

	m_ShaderNodeChangeCallback = Napi::ThreadSafeFunction::New(env, info[0].As<Napi::Function>(), "Check", 0, 1);
}

struct DataCb
{
	int m_NodeId;
	void* m_Buffer;
	size_t m_ByteSize;
	size_t m_ElementSize;
};

void MATD::V8::MatdV8::CallShaderNodeChangeCallback(int nodeId, MATD::DTYPES::Texture* texture)
{
	const auto data = new DataCb();
	data->m_Buffer = texture->GetBuffer();
	data->m_ByteSize = texture->GetSize();
	data->m_ElementSize = texture->GetElementSize();
	data->m_NodeId = nodeId;

	auto cb = [](Napi::Env env, Napi::Function callback, DataCb* data)
	{
		callback.Call({ Napi::Number::New(env, data->m_NodeId), Napi::Number::New(env, data->m_ElementSize),Napi::ArrayBuffer::New(env, data->m_Buffer, data->m_ByteSize)});
		delete data;
	};

	m_ShaderNodeChangeCallback.NonBlockingCall(data, cb);
}
