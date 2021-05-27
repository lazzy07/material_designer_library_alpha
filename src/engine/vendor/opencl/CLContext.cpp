#include "CLContext.hpp"
#include "../../../core/Log.hpp"


namespace MATD{
  namespace ENGINE{
    namespace OPENCL{
      Context::Context(cl::Device device, std::string deviceName) : m_Device(device), m_DeviceName(deviceName) {
        cl_int error = 0;
        m_Context = cl::Context(device);

        if (error != CL_SUCCESS) {
          MATD_CORE_ERROR("Creation of context failed");
          return;
        }
        MATD_CORE_TRACE("CLCONTEXT::Context created for: {}", deviceName);
      }
    }
  }
}