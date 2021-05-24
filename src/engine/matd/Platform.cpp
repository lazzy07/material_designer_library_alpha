#include "Platform.hpp"
#include "../../core/ContextManager.hpp"

namespace MATD{
  namespace ENGINE{
    Ref<Platform> Platform::CreatePlatform(){
      CORE::SUPPORTED_CONTEXTS context = CORE::ContextManager::GetSelectedContext();

      switch(context){
        case CORE::SUPPORTED_CONTEXTS::CUDA:
          break;
          
        case CORE::SUPPORTED_CONTEXTS::OPEN_CL:
          break;
      }

      return nullptr;
    }

    void Platform::SetPlatformData(const std::string version, const std::string profile, const std::string name, const std::string vendor){
      m_Version = version;
      m_Profile = profile;
      m_Name = name;
      m_Vendor = vendor;

      MATD_CORE_TRACE("MATD_PLATFORM:: Platform :{} supports:{}", name, version);
    }
  }
}