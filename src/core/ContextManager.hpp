#pragma once
#include <vector>
#include "../engine/matd/Context.hpp"

namespace MATD{
  namespace CORE{
    enum class SUPPORTED_CONTEXTS{
      OPEN_CL,
      CUDA
    };

    class ContextManager{
      public:
        ContextManager(SUPPORTED_CONTEXTS context = SUPPORTED_CONTEXTS::OPEN_CL);
        ~ContextManager();

        void SelectContext(SUPPORTED_CONTEXTS context);
        inline static const SUPPORTED_CONTEXTS GetSelectedContext() { return s_Context; };
      private:
        static SUPPORTED_CONTEXTS s_Context;
        Ref<MATD::ENGINE::Context> m_Context;
    };
  };
}