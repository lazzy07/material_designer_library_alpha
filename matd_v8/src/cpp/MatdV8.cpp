#include "MatdV8.hpp"
#include <core/Core.hpp>
#include <core/EngineManager.hpp>

MATD::V8::MatdV8::MatdV8(const Napi::CallbackInfo& info) : ObjectWrap(info)
{
  this->m_Matd = new MATD::CORE::MaterialDesigner();
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
    });
}

Napi::Value MATD::V8::MatdV8::OpenMaterialProject(const Napi::CallbackInfo& info)
{
	Napi::Env env = info.Env();

	if (info.Length() < 1) {
		Napi::TypeError::New(env, "NodeProject not found!").ThrowAsJavaScriptException();
		return env.Null();
	}

	if (!info[0].IsString()) {
		Napi::TypeError::New(env, "NodeProject needs to be in string format").ThrowAsJavaScriptException();
		return env.Null();
	}

	Napi::String project = info[0].As<Napi::String>();
	
	MATD_CORE_TRACE("MATD_V8:: Open NodeProject request recieved");
	this->m_Matd->OpenProject(project);

	return env.Null();
}

Napi::Value MATD::V8::MatdV8::UpdateMaterialProject(const Napi::CallbackInfo& info)
{
	Napi::Env env = info.Env();

	if (info.Length() < 1) {
		Napi::TypeError::New(env, "MaterialProject not found!").ThrowAsJavaScriptException();
		return env.Null();
	}

	if (!info[0].IsString()) {
		Napi::TypeError::New(env, "MaterialProject needs to be in string format").ThrowAsJavaScriptException();
		return env.Null();
	}

	Napi::String project = info[0].As<Napi::String>();

	MATD_CORE_TRACE("MATD_V8:: Update MaterialProject request recieved");
	this->m_Matd->UpdateProject(project);

	return env.Null();
}

Napi::Value MATD::V8::MatdV8::UpdateMaterialGraph(const Napi::CallbackInfo& info)
{
	Napi::Env env = info.Env();

	if (info.Length() < 2) {
		Napi::TypeError::New(env, "Update type and update data required").ThrowAsJavaScriptException();
		return env.Null();
	}

	if (!info[0].IsString()) {
		Napi::TypeError::New(env, "Update type needs to be in string format").ThrowAsJavaScriptException();
		return env.Null();
	}

	if (!info[1].IsString()) {
		Napi::TypeError::New(env, "MaterialGraph needs to be in string format").ThrowAsJavaScriptException();
		return env.Null();
	}

	Napi::String updateType = info[0].As<Napi::String>();
	Napi::String graph = info[1].As<Napi::String>();
	

	if (updateType.Utf8Value() == "createNode") {
		MATD_CORE_TRACE("MATD_V8:: Create node request recieved");
		this->m_Matd->CreateNode(graph);
	}
	else if (updateType.Utf8Value() == "removeNode") {
		MATD_CORE_TRACE("MATD_V8:: Remove node request recieved");
		this->m_Matd->RemoveNode(graph);
	}
	else if (updateType.Utf8Value() == "addConnection") {
		MATD_CORE_TRACE("MATD_V8:: Add connection request recieved");
		this->m_Matd->AddConnection(graph);
	}
	else if (updateType.Utf8Value() == "removeConnection") {
		MATD_CORE_TRACE("MATD_V8:: Remove connection request recieved");
		this->m_Matd->RemoveConnection(graph);
	}
	else if (updateType.Utf8Value() == "update") {
		MATD_CORE_TRACE("MATD_V8:: Node data update request recieved");
		this->m_Matd->Update(graph);
	}
	else {
		MATD_CORE_TRACE("MATD_V8:: Unknown update format!");
		Napi::TypeError::New(env, "Unknown update format").ThrowAsJavaScriptException();
		return env.Null();
	}

	return env.Null();
}

Napi::Value MATD::V8::MatdV8::SelectCurrentMaterialGraph(const Napi::CallbackInfo& info)
{
	Napi::Env env = info.Env();

	if (info.Length() < 1) {
		Napi::TypeError::New(env, "graphID not found!").ThrowAsJavaScriptException();
		return env.Null();
	}

	if (!info[0].IsString()) {
		Napi::TypeError::New(env, "graphID needs to be in string format").ThrowAsJavaScriptException();
		return env.Null();
	}

	Napi::String graphID = info[0].As<Napi::String>();

	MATD_CORE_TRACE("MATD_V8:: Selected Graph Change request recieved");
	this->m_Matd->SetSelectedGraph(graphID);

	return env.Null();
}

Napi::Value MATD::V8::MatdV8::SetComputationDevice(const Napi::CallbackInfo& info)
{
  Napi::Env env = info.Env();

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
	Napi::Env env = info.Env();
  Napi::Array arr = Napi::Array::New(env);
  
  MATD::Ref<std::vector<std::string>> engines = MATD::CORE::EngineManager::GetSupportedEngines();

  for (int i = 0; i < engines->size(); i++) {
    arr.Set(i, Napi::String::New(env, engines->at(i)));
  }

	return arr;
}

Napi::Value MATD::V8::MatdV8::SetEngine(const Napi::CallbackInfo& info)
{
  Napi::Env env = info.Env();

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