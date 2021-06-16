#pragma once
#include "../core/Core.hpp"
#include "../engine/Platform.hpp"
#include "../engine/Device.hpp"
namespace MATD{
  namespace ENGINE {
    class Engine {
    public:
      void SelectPlatform(size_t id);
      void SelectDevice(size_t id);

      Ref<Platform> GetSelectedPlatform();
      Ref<Device> GetSelectedDevice();
    };
  };
}