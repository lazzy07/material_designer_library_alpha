#include "CLContext.hpp"
#include "../../../core/Log.hpp"


namespace MATD{
  namespace ENGINE{
    namespace OPENCL{
      Context::Context(cl_device_id id, std::string deviceName) : m_DeviceId(id), m_DeviceName(deviceName) {
        cl_int error;
        m_Context = clCreateContext(NULL, 1, &m_DeviceId, NULL, NULL, &error);

        if (error != CL_SUCCESS) {
          MATD_CORE_ERROR("Creation of context failed");
          return;
        }
        MATD_CORE_TRACE("CLCONTEXT::Context created for: {}", deviceName);
      }
    }
  }
}