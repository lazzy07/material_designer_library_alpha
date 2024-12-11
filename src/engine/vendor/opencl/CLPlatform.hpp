#pragma once
#include <CL/cl.hpp>
#include <vector>
#include "../../matd/Platform.hpp"

namespace MATD{
  namespace ENGINE{
    namespace OPENCL{
      /**
       * @brief OpenCL Platform class, used to store the platform information and devices
       * 
       */
      class Platform : public ENGINE::Platform{
      public:
        inline void SetPlatform(cl::Platform platform){m_Platform = platform;};
        inline const std::vector<cl::Device> GetCLDevices() const { return m_Devices; };

				virtual void InitCompatibleDevices() override;
        
      private:
        cl::Platform m_Platform;
        std::vector<cl::Device> m_Devices;
      };
    };
  }
}