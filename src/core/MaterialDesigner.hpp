#pragma once
#include "Core.hpp"
#include "ContextManager.hpp"

namespace MATD{
  namespace CORE{
    class MaterialDesigner{
      public:
        MaterialDesigner();
        ~MaterialDesigner();

        inline const Ref<ContextManager> GetContextManager() {return m_ContextManager; };
      private:
        Ref<ContextManager> m_ContextManager;
    };
  };
}