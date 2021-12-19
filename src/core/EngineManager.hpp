#pragma once
#include "../engine/matd/Engine.hpp"

namespace MATD{
  namespace CORE{
    enum class SUPPORTED_ENGINES{
      OPEN_CL,
      CUDA
    };

    class EngineManager{
      public:
        static void SelectEngine(SUPPORTED_ENGINES engine);
        static Ref<std::vector<std::string>> GetSupportedEngines();

				inline static const SUPPORTED_ENGINES GetSelectedEngine() { return s_Engine; };
				inline static const Ref<MATD::ENGINE::Engine> GetEngineInstance() { return s_EngineInstance; };
      private:
        static SUPPORTED_ENGINES s_Engine;
        static Ref<MATD::ENGINE::Engine> s_EngineInstance;
    };
  };
}