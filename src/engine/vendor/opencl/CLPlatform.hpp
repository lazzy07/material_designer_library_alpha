#pragma once
#include <CL/cl.hpp>
#include <vector>
#include "../../matd/Platform.hpp"

namespace MATD{
  namespace ENGINE{
    namespace OPENCL{
      class Platform : public ENGINE::Platform{
      public:
        inline void SetPlatform(cl::Platform platform){m_Platform = platform;};
        virtual std::vector<Ref<MATD::ENGINE::Device>> GetCompatibleDevices() override;
        
      private:
        cl::Platform m_Platform;
        std::vector<cl::Device> m_Devices;
      };
    };
  }
}