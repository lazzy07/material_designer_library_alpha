#include "CLPlatform.hpp"
#include <CL/opencl.h>
namespace MATD{
  namespace ENGINE{
    namespace OPENCL{
      std::vector<Ref<MATD::ENGINE::Device>> Platform::GetCompatibleDevices(){
        std::vector<Ref<MATD::ENGINE::Device>> devices;

        cl_int error = 0;
        cl_uint numOfDevices = 0;

        error = clGetDeviceIDs(m_PlatformId, CL_DEVICE_TYPE_ALL, 0, NULL, &numOfDevices);

        if(error != CL_SUCCESS){
          MATD_CORE_ERROR("Couldn't find any device that support OpenCL");
        }
        MATD_CORE_TRACE("MATD_CLPLATFORM:: Platform: {} devices {}", GetName(), numOfDevices);
        return devices;
      }
    }
  }
}