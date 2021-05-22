#pragma once




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

        void SelectContext(SUPPORTED_CONTEXTS context){m_Context = context;};

      private:
        SUPPORTED_CONTEXTS m_Context;
    };
  };
}