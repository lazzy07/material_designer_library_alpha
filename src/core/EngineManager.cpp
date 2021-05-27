#include "EngineManager.hpp"
#include "Log.hpp"
#include "Core.hpp"
#include "../engine/vendor/opencl/CLEngine.hpp"

namespace MATD{
  namespace CORE{
    SUPPORTED_ENGINES EngineManager::s_Engine = SUPPORTED_ENGINES::OPEN_CL;

    EngineManager::EngineManager(SUPPORTED_ENGINES engine){
      MATD_CORE_TRACE("ENGINE_MANAGER::Initialized");

      SelectEngine(engine);
    }
    
    EngineManager::~EngineManager(){
      MATD_CORE_TRACE("ENGINE_MANAGER::Closed");
    }

    void EngineManager::SelectEngine(SUPPORTED_ENGINES engine){
      s_Engine = engine;
      if(engine == SUPPORTED_ENGINES::CUDA){
        //TODO:: Add CUDA SUPPORT
        MATD_CORE_ASSERT(false, "ENGINE_MANAGER::CUDA Not suppoted yet")
      }else if(engine == SUPPORTED_ENGINES::OPEN_CL){
        MATD_CORE_TRACE("ENGINE_MANAGER::Context changed to :: OpenCL");
        m_Engine = MATD::ENGINE::Engine::CreateEngine();
        m_Engine->SetPlatforms(m_Engine->GetSupportedPlatforms());
      }else{
        MATD_CORE_ASSERT(false, "ENGINE_MANAGER::Unknown Context Change Detected")
      };
    }

    void EngineManager::SelectDevice(size_t platform, size_t device) {

    }
  }
}