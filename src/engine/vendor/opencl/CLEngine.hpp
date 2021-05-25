#pragma once
#include <vector>
#include "../../matd/Engine.hpp"
#include "CLPlatform.hpp"
#include <CL/opencl.h>

namespace MATD{
  namespace ENGINE{
    namespace OPENCL{
      class Engine : public ENGINE::Engine{
        public:
          Engine();
          ~Engine();
          virtual std::vector<Ref<ENGINE::Platform>> GetSupportedPlatforms() override;

        private:
          cl_platform_id* m_Platforms;
      };
    };
  }
}