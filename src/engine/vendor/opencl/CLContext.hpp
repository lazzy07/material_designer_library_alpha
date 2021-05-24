#pragma once
#include <vector>
#include "../../matd/Context.hpp"
#include "CLPlatform.hpp"
#include <CL/opencl.h>

namespace MATD{
  namespace ENGINE{
    namespace OPENCL{
      class Context : public ENGINE::Context{
        public:
          Context();
          ~Context();
          virtual std::vector<Ref<ENGINE::Platform>> GetSupportedPlatforms() override;

        private:
          cl_platform_id* m_Platforms;
      };
    };
  }
}