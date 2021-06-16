#include "CLEngine.hpp"


namespace MATD{
  namespace ENGINE{
    OPENCL::Engine::Engine(){

    }

    OPENCL::Engine::~Engine(){
    }

    std::vector<Ref<ENGINE::Platform>> OPENCL::Engine::GetSupportedPlatforms(){
      auto vec = std::vector<Ref<ENGINE::Platform>>();
      
      cl::Platform::get(&m_Platforms);

      if (m_Platforms.size() <= 0) {
        MATD_CORE_ERROR("CLENGINE::Couldn't find any platform that support OpenCL");
      }
      size_t i = 0;
      for (auto platform : m_Platforms) {
        Ref<ENGINE::OPENCL::Platform> pf = std::make_shared<ENGINE::OPENCL::Platform>();

        cl_int error = 0;
        std::string name = platform.getInfo<CL_PLATFORM_NAME>(&error);
        std::string profile = platform.getInfo<CL_PLATFORM_PROFILE>(&error);
        std::string version = platform.getInfo<CL_PLATFORM_VERSION>(&error);
        std::string vendor = platform.getInfo<CL_PLATFORM_VENDOR>(&error);

        if (error != CL_SUCCESS) {
          MATD_CORE_ASSERT(false, "Platform Information fetching failed");
        }

        pf->SetPlatformData(version, profile, name, vendor);
        pf->SetId(i);
        pf->SetPlatform(platform);
        pf->InitCompatibleDevices();
        i++;
        vec.push_back(pf);
      }

      return vec;
    }
  }
}