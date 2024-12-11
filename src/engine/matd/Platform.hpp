#pragma once

#include <string>
#include <vector>
#include "../../core/Core.hpp"
#include "Device.hpp"

namespace MATD{
  namespace ENGINE{

    /**
     * @brief Platform class, used to store platform information and devices, this is the main class that is used to select the platform and devices. 
     * Platform can have multiple devices, from multiple vendors (Eg: Nvidia, Intel etc.), and multiple profiles
     * 
     */
    class Platform{
      public:
				virtual void InitCompatibleDevices() = 0;
        
        void SetPlatformData(const std::string version, const std::string profile, const std::string name, const std::string vendor);

        inline std::string GetName() const {return m_Name;};
				inline void SetDevices(std::vector<Ref<Device>> devices) { m_Devices = devices; };
				inline const std::vector<Ref<Device>> GetDevices() { return m_Devices; };
        inline size_t GetId() const { return m_Id; };
        inline void SetId(size_t id) { m_Id = id; };

      private:
        size_t m_Id;
        std::string m_Version;
        std::string m_Profile;
        std::string m_Name;
        std::string m_Vendor;

        std::vector<Ref<Device>> m_Devices;
    };
  };
};