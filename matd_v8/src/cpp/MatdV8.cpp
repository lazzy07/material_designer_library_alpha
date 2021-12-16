#include "MatdV8.hpp"
#include <core/Core.hpp>

MATD::V8::MatdV8::MatdV8(const Napi::CallbackInfo& info) : ObjectWrap(info)
{
}

Napi::Function MATD::V8::MatdV8::GetClass(Napi::Env env)
{
  return DefineClass(env, "MatdV8", {
      MatdV8::InstanceMethod("parseJSONToNodeGraph", &MatdV8::parseJSONToNodeGraph),
    });
}

Napi::Value MATD::V8::MatdV8::parseJSONToNodeGraph(const Napi::CallbackInfo& info)
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

  MATD_CORE_TRACE("MATD::V8:: Graph\n", graph.Utf8Value().c_str());

  return env.Null();
}