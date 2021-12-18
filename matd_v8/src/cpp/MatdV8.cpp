#include "MatdV8.hpp"
#include <core/Core.hpp>

MATD::V8::MatdV8::MatdV8(const Napi::CallbackInfo& info) : ObjectWrap(info)
{
  this->matd = new MATD::CORE::MaterialDesigner();
}

MATD::V8::MatdV8::~MatdV8()
{
  delete this->matd;
}

Napi::Function MATD::V8::MatdV8::GetClass(Napi::Env env)
{
  return DefineClass(env, "MatdV8", {
			MatdV8::InstanceMethod("parseJSONToNodeProject", &MatdV8::ParseJSONToNodeProject),
			MatdV8::InstanceMethod("setComputationDevice", &MatdV8::SetComputationDevice),
    });
}

Napi::Value MATD::V8::MatdV8::ParseJSONToNodeProject(const Napi::CallbackInfo& info)
{
  Napi::Env env = info.Env();

  if (info.Length() < 1) {
    Napi::TypeError::New(env, "NodeGraph not found!").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsString()) {
    Napi::TypeError::New(env, "NodeGraph need to be in string format").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::String graph = info[0].As<Napi::String>();

  MATD_TRACE("MATD_V8:: Parse NodeGraph request recieved");
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

  this->matd->SelectDevice(info[0].As<Napi::Number>().Uint32Value(), info[1].As<Napi::Number>().Uint32Value());

	return env.Null();
}