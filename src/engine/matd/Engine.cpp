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

    void Engine::SelectPlatform(size_t id)
    {
      for (auto platform : m_Platforms) {
        if (id == platform->GetId()) {
          m_SelectedPlatfom = platform;
          MATD_CORE_INFO("MATD_ENGINE::Platform Selected {}", platform->GetName());
        }
      }
    }

    void Engine::SelectDevice(size_t id)
    {
      MATD_CORE_ASSERT(m_SelectedPlatfom, "MATD_ENGINE::Device Not been selected");
      for (auto device : m_SelectedPlatfom->GetDevices()) {
        if (id == device->GetId()) {
          m_SelectedDevice = device;
          MATD_CORE_INFO("MATD_ENGINE::Device Selected {}", device->GetDeviceName());
        }
      }
    }
  }
}