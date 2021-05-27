#pragma once
#include <vector>
#include "../../matd/Engine.hpp"
#include "CLPlatform.hpp"
#include <CL/cl.hpp>

namespace MATD{
  namespace ENGINE{
    namespace OPENCL{
      class Engine : public ENGINE::Engine{
        public:
          Engine();
          ~Engine();
          virtual std::vector<Ref<ENGINE::Platform>> GetSupportedPlatforms() override;

        private:
          std::vector<cl::Platform> m_Platforms;
      };
    };
  }
}