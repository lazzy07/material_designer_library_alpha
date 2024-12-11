#pragma once
#include <CL/cl.hpp>
#include "../../../core/Core.hpp"

namespace MATD {
  namespace ENGINE {
    namespace OPENCL {
      /**
       * @brief Context class for OpenCL, used to store the context of the device
       * 
       */
      class Context {
      public:
        Context(cl::Device device, std::string deviceName);
        const cl::Context GetCLContext() const { return m_Context; };
      private:
        cl::Context m_Context;
        cl::Device m_Device;
        std::string m_DeviceName;
        
      };
    };
  };
};