#pragma once
#include <CL/opencl.h>
#include "../../../core/Core.hpp"

namespace MATD {
  namespace ENGINE {
    namespace OPENCL {
      class Context {
      public:
        Context(cl_device_id id, std::string deviceName);
      private:
        cl_context m_Context;
        cl_device_id m_DeviceId;
        std::string m_DeviceName;
      };
    };
  };
};