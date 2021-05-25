#include "../../core/Core.hpp"
#include "Engine.hpp"
#include "../../core/EngineManager.hpp"
#include "../vendor/opencl/CLEngine.hpp"
#include <memory>

namespace MATD{
  namespace ENGINE{
    Ref<Engine> Engine::CreateEngine(){
      CORE::SUPPORTED_ENGINES context = CORE::EngineManager::GetSelectedEngine();

      switch(context){
        case CORE::SUPPORTED_ENGINES::OPEN_CL:
            MATD_CORE_TRACE("MATD_ENGINE::Created engine with OpenCL");
            return std::make_shared<ENGINE::OPENCL::Engine>();
          break;

        case CORE::SUPPORTED_ENGINES::CUDA:
          MATD_CORE_ASSERT(false,"Engine not supported yet")
          return nullptr;
          break;
      }
      MATD_CORE_ASSERT(false, "Un-identified engine type selected");
      return nullptr;
    }
  }
}