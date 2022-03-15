#pragma once
#include <napi.h>
#include <core/MaterialDesigner.hpp>

namespace MATD{
  namespace V8{
    class UpdaterAsync : public Napi::AsyncWorker {
    public:
      UpdaterAsync(Napi::Function& callback, MATD::CORE::MaterialDesigner* matd, const Napi::String& updateType, const Napi::String& graph);
      ~UpdaterAsync();

      void Execute() override;
      void OnOK() override;
    private:
      MATD::CORE::MaterialDesigner* m_MaterialDesignerInstance;
      Napi::String m_Graph;
      Napi::String m_UpdateType;
    };
  }
}