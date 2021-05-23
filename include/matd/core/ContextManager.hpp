#pragma once

namespace MATD{
  namespace CORE{
    enum SUPPORTED_CONTEXTS{
      OPEN_CL,
      CUDA
    };

    class ContextManager{
      public:
        void SelectContext(SUPPORTED_CONTEXTS context);
    };
  };
}