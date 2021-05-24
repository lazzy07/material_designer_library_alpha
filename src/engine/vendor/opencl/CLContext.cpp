#include "CLContext.hpp"


namespace MATD{
  namespace ENGINE{
    OPENCL::Context::Context(){

    }

    OPENCL::Context::~Context(){
      free(m_Platforms);
    }

    std::vector<Ref<ENGINE::Platform>> OPENCL::Context::GetSupportedPlatforms(){
      cl_uint noOfPlatforms;

      cl_int err = clGetPlatformIDs(0, NULL, &noOfPlatforms);
      if(err < 0){
        MATD_CORE_ERROR("Couldn't find any platforms that support OpenCL");
      }

      m_Platforms = (cl_platform_id*) malloc(sizeof(cl_platform_id) * noOfPlatforms);
      clGetPlatformIDs(noOfPlatforms, m_Platforms, &noOfPlatforms);

      MATD_CORE_TRACE("MATD_CLCONTEXT:: {} OpenCL Platforms Found", noOfPlatforms);
      auto vec = std::vector<Ref<ENGINE::Platform>>();

      for(cl_uint i=0; i< noOfPlatforms; i++){
        Ref<ENGINE::OPENCL::Platform> pf = std::make_shared<ENGINE::OPENCL::Platform>();

        cl_int error = 0;
        size_t paramSize = 0;

        error = clGetPlatformInfo(m_Platforms[i], CL_PLATFORM_VERSION, 0, NULL, &paramSize);
        char* version = (char*)malloc(sizeof(char)*paramSize);
        error = clGetPlatformInfo(m_Platforms[i], CL_PLATFORM_VERSION, paramSize, version, NULL);

        error = clGetPlatformInfo(m_Platforms[i], CL_PLATFORM_PROFILE, 0, NULL, &paramSize);
        char* profile = (char*)malloc(sizeof(char)*paramSize);
        error = clGetPlatformInfo(m_Platforms[i], CL_PLATFORM_PROFILE, paramSize, profile, NULL);

        error = clGetPlatformInfo(m_Platforms[i], CL_PLATFORM_NAME, 0, NULL, &paramSize);
        char* name = (char*)malloc(sizeof(char)*paramSize);
        error = clGetPlatformInfo(m_Platforms[i], CL_PLATFORM_NAME, paramSize, name, NULL);

        error = clGetPlatformInfo(m_Platforms[i], CL_PLATFORM_VENDOR, 0, NULL, &paramSize);
        char* vendor = (char*)malloc(sizeof(char)*paramSize);
        error = clGetPlatformInfo(m_Platforms[i], CL_PLATFORM_VENDOR, paramSize, vendor, NULL);

        if(error != CL_SUCCESS){
          MATD_CORE_ERROR("Couldn't find any platforms that support OpenCL");
          return std::vector<Ref<ENGINE::Platform>>();
        }

        std::string ver(version);
        std::string pro(profile);
        std::string nam(name);
        std::string ven(vendor);

        pf->SetPlatformData(ver, pro, nam, ven);

        cl_platform_id* id = (cl_platform_id*)malloc(sizeof(cl_platform_id));
        memcpy(id, m_Platforms[i], sizeof(cl_platform_id));

        pf->SetPlatformID(id);
        vec.push_back(pf);

        free(version);
        free(profile);
        free(name);
        free(vendor);
      }

      return vec;
    }
  }
}