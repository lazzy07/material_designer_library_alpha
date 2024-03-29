#pragma once

#include <napi.h>
#include <core/MaterialDesigner.hpp>

/**
 * \brief This will be used to check whether the MATD library is running in Node environment
 */
#define V8_ENGINE

namespace MATD{
  namespace V8{
    class MatdV8 : public Napi::ObjectWrap<MatdV8> {
    public:
      MatdV8(const Napi::CallbackInfo& info);
      ~MatdV8();
			Napi::Value OpenMaterialProject(const Napi::CallbackInfo& info);
			Napi::Value UpdateMaterialProject(const Napi::CallbackInfo& info);
			void UpdateMaterialGraph(const Napi::CallbackInfo& info);
			Napi::Value SelectCurrentMaterialGraph(const Napi::CallbackInfo& info);

      Napi::Value SetComputationDevice(const Napi::CallbackInfo& info);
      Napi::Value SetEngine(const Napi::CallbackInfo& info);

      Napi::Value GetAvailableEngines(const Napi::CallbackInfo& info);
			Napi::Value GetAvailableDevices(const Napi::CallbackInfo& info);

      void CompileKernel(const Napi::CallbackInfo& info);
      void SetShaderNodeChangeCallback(const Napi::CallbackInfo& info);

    	static void CallShaderNodeChangeCallback(int nodeId, MATD::DTYPES::Texture* texture);

      static Napi::Function GetClass(Napi::Env env);
    private:
      MATD::CORE::MaterialDesigner* m_Matd;
      
      inline static Napi::ThreadSafeFunction m_ShaderNodeChangeCallback;
    };
  }
}