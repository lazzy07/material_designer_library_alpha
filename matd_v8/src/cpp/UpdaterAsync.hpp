#pragma once
#include <napi.h>
#include <core/MaterialDesigner.hpp>

namespace MATD{
  namespace V8{
    class UpdaterAsync : public Napi::AsyncWorker {
    public:
      UpdaterAsync(Napi::Function& callback, MATD::CORE::MaterialDesigner* matd, std::string selectedGraphType, std::string updateType, std::string graph);
      ~UpdaterAsync();

      void Execute() override;
      void OnOK() override;
    private:
      MATD::CORE::MaterialDesigner* m_MaterialDesignerInstance;
      std::string m_Graph;
      std::string m_UpdateType;
      std::string m_SelectedGraphType;
    };
  }
}