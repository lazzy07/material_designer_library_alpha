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
        static void SelectEngine(const SUPPORTED_ENGINES& engine);
        static Ref<std::vector<std::string>> GetSupportedEngines();

				static SUPPORTED_ENGINES GetSelectedEngine() { return m_Engine; }
				static Ref<MATD::ENGINE::Engine> GetEngineInstance() { return m_EngineInstance; }
      private:
        static SUPPORTED_ENGINES m_Engine;
        static Ref<MATD::ENGINE::Engine> m_EngineInstance;
    };
  };
}