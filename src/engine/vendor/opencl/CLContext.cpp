#include "CLContext.hpp"


namespace MATD{
  namespace ENGINE{
    OPENCL::Context::Context(){

    }

    std::vector<Ref<ENGINE::Platform>> OPENCL::Context::GetSupportedPlatforms(){
      cl_uint noOfPlatforms;

      cl_int err = clGetPlatformIDs(0, NULL, &noOfPlatforms);
      if(err < 0){
        MATD_CORE_ERROR("Couldn't find any platforms that support OpenCL");
      }

      MATD_CORE_INFO("No of OpenCL Platforms Found: {}", noOfPlatforms);

      return std::vector<Ref<ENGINE::Platform>>();
    }
  }
}