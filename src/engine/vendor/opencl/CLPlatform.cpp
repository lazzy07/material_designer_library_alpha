#include "CLPlatform.hpp"
#include <CL/opencl.h>
namespace MATD{
  namespace ENGINE{
    namespace OPENCL{
      Platform::~Platform(){
        free(m_PlatformId);
      }

      std::vector<Ref<MATD::ENGINE::Device>>Platform::GetCompatibleDevices(){
        std::vector<Ref<MATD::ENGINE::Device>> devices;
        return devices;
      }
    }
  }
}