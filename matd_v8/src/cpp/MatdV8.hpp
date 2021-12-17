#pragma once
#include <napi.h>
#include <core/MaterialDesigner.hpp>

namespace MATD{
  namespace V8{
    class MatdV8 : public Napi::ObjectWrap<MatdV8> {
    public:
      MatdV8(const Napi::CallbackInfo& info);
			Napi::Value ParseJSONToNodeGraph(const Napi::CallbackInfo& info);
      static Napi::Function GetClass(Napi::Env env);
    private:
      MATD::CORE::MaterialDesigner* matd;
    };
  }
}