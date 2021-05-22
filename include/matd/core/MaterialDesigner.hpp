#pragma once
#include <matd/core/Core.hpp>
#include <matd/core/ContextManager.hpp>

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