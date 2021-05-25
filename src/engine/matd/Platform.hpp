#pragma once

#include <string>
#include <vector>
#include "../../core/Core.hpp"
#include "Device.hpp"

namespace MATD{
  namespace ENGINE{
    class Platform{
      public:
        virtual std::vector<Ref<MATD::ENGINE::Device>> GetCompatibleDevices() = 0;
        
        void SetPlatformData(const std::string version, const std::string profile, const std::string name, const std::string vendor);

        inline std::string GetName() const {return m_Name;};
        inline void SetDevices(std::vector<Ref<Device>> devices) { m_Devices = devices; };

      private:
        std::string m_Version;
        std::string m_Profile;
        std::string m_Name;
        std::string m_Vendor;

        std::vector<Ref<Device>> m_Devices;
    };
  };
};