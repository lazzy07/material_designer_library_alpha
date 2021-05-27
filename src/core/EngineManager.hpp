#pragma once
#include <vector>
#include "../engine/matd/Engine.hpp"

namespace MATD{
  namespace CORE{
    enum class SUPPORTED_ENGINES{
      OPEN_CL,
      CUDA
    };

    class EngineManager{
      public:
        EngineManager(SUPPORTED_ENGINES engine = SUPPORTED_ENGINES::OPEN_CL);
        ~EngineManager();

        void SelectEngine(SUPPORTED_ENGINES engine);

        inline static const SUPPORTED_ENGINES GetSelectedEngine() { return s_Engine; };

        void SelectDevice(size_t device);
        void SelectPlatform(size_t platform);

      private:
        static SUPPORTED_ENGINES s_Engine;
        Ref<MATD::ENGINE::Engine> m_Engine;
        Ref<MATD::ENGINE::Platform> m_Platform;
        Ref<MATD::ENGINE::Device> m_Device;
    };
  };
}