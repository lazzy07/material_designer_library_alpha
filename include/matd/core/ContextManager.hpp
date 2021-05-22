#pragma once
#include <vector>

namespace MATD{
  namespace CORE{
    enum SUPPORTED_CONTEXTS{
      OPEN_CL,
      CUDA
    };

    class ContextManager{
      public:
        ContextManager();
        ~ContextManager();

        inline void SelectContext(SUPPORTED_CONTEXTS context){m_Context = context;};

      private:
        SUPPORTED_CONTEXTS m_Context = OPEN_CL;
        std::vector<int> m_Devices;
    };
  };
}