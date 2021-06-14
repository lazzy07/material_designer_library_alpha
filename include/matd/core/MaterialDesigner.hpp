#pragma once
#include "Core.hpp"
#include "EngineManager.hpp"

namespace MATD{
  namespace CORE{
    class MaterialDesigner{
      public:
        MaterialDesigner();
        ~MaterialDesigner();

        inline const Ref<EngineManager> GetEngineManager() {return m_EngineManager; };
        
      private:
        Ref<EngineManager> m_EngineManager;
    };
  }
}