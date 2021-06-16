#pragma once
#include "Core.hpp"
#include "../engine/Engine.hpp"

namespace MATD{
  namespace CORE{
    enum SUPPORTED_ENGINES{
      OPEN_CL,
      CUDA
    };

    class EngineManager{
      public:
        //Select the engine that Material Designer use to compute
        void SelectEngine(SUPPORTED_ENGINES engine);
      private:
        static Ref<MATD::ENGINE::Engine> s_EngineInstance;
    };
  };
}