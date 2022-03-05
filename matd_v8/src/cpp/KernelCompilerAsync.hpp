#pragma once
#include <napi.h>
#include <core/MaterialDesigner.hpp>

namespace MATD{
  namespace V8{
    class KernelCompilerAsync : public Napi::AsyncWorker {
    public:
      KernelCompilerAsync(Napi::Function& callback, MATD::CORE::MaterialDesigner* matd);
      ~KernelCompilerAsync();

      void Execute() override;
      void OnOK() override;
    private:
      MATD::CORE::MaterialDesigner* m_MaterialDesignerInstance;
      std::string m_KernelError;
    };
  }
}