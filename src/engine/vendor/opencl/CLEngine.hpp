#pragma once
#include <vector>
#include "../../matd/Engine.hpp"
#include "CLPlatform.hpp"
#include <CL/cl.hpp>

namespace MATD{
  namespace ENGINE{
    namespace OPENCL{
      /**
       * @brief OpenCL Engine class, used to select platforms and devices to run kernels on, this class is used to initialize the engine and select the platform and device. And this is a singleton class
       * 
       */
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