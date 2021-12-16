#pragma once
#include <napi.h>

namespace MATD{
  namespace V8{
    class MatdV8 : public Napi::ObjectWrap<MatdV8> {
    public:
      MatdV8(const Napi::CallbackInfo& info);
			Napi::Value parseJSONToNodeGraph(const Napi::CallbackInfo& info);
      static Napi::Function GetClass(Napi::Env env);
    private:
      static Napi::FunctionReference constructor;
    };
  }
}