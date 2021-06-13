#include "EngineManager.hpp"
#include "Log.hpp"
#include "Core.hpp"
#include "../engine/vendor/opencl/CLEngine.hpp"

namespace MATD{
  namespace CORE{
    SUPPORTED_ENGINES EngineManager::s_Engine = SUPPORTED_ENGINES::OPEN_CL;
    Ref<ENGINE::Engine> EngineManager::s_EngineInstance = std::make_shared<ENGINE::OPENCL::Engine>();

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
        s_EngineInstance = MATD::ENGINE::Engine::CreateEngine();
        s_EngineInstance->SetPlatforms(s_EngineInstance->GetSupportedPlatforms());
      }else{
        MATD_CORE_ASSERT(false, "ENGINE_MANAGER::Unknown Context Change Detected")
      };
    }
  }
}