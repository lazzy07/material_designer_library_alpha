#pragma once
#include <vector>
#include "../../core/Core.hpp"
#include "Platform.hpp"
#include "Device.hpp"

namespace MATD{
  namespace ENGINE{
    class Engine{
      public:
        virtual ~Engine() {};

        virtual std::vector<Ref<Platform>> GetSupportedPlatforms() = 0;

        static Ref<Engine> CreateEngine();

        inline void SetPlatforms(std::vector<Ref<Platform>> platforms) { m_Platforms = platforms; };

        void SelectPlatform(size_t id);
        void SelectDevice(size_t id);

        inline const Ref<Platform> GetSelectedPlatform() const { return m_SelectedPlatfom; };
        inline const Ref<Device> GetSelectedDevice() const { return m_SelectedDevice; };

      private:
        std::vector<Ref<Platform>> m_Platforms;
        Ref<Platform> m_SelectedPlatfom;
        Ref<Device> m_SelectedDevice;
    };
  };
}