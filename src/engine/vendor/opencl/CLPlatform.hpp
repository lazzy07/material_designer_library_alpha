#pragma once
#include <CL/opencl.h>
#include <vector>
#include "../../matd/Platform.hpp"

namespace MATD{
  namespace ENGINE{
    namespace OPENCL{
      class Platform : public ENGINE::Platform{
      public:
        inline void SetPlatformID(cl_platform_id id){m_PlatformId = id;};
        virtual std::vector<Ref<MATD::ENGINE::Device>> GetCompatibleDevices() override;
        
      private:
        cl_platform_id m_PlatformId;
        cl_device_id* m_DeviceIds;
      };
    };
  }
}