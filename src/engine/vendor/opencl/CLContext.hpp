#pragma once
#include <CL/cl.hpp>
#include "../../../core/Core.hpp"

namespace MATD {
  namespace ENGINE {
    namespace OPENCL {
      class Context {
      public:
        Context(cl::Device device, std::string deviceName);
      private:
        cl::Context m_Context;
        cl::Device m_Device;
        std::string m_DeviceName;
      };
    };
  };
};