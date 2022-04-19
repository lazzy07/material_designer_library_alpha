#include "EngineManager.hpp"
#include "Log.hpp"
#include "Core.hpp"
#include "../engine/vendor/opencl/CLEngine.hpp"

namespace MATD{
  namespace CORE{
    SUPPORTED_ENGINES EngineManager::m_Engine = SUPPORTED_ENGINES::OPEN_CL;
    Ref<ENGINE::Engine> EngineManager::m_EngineInstance = std::make_shared<ENGINE::OPENCL::Engine>();

    void EngineManager::SelectEngine(const SUPPORTED_ENGINES& engine){
      m_Engine = engine;
      if(engine == SUPPORTED_ENGINES::CUDA){
        //TODO:: Add CUDA SUPPORT
        MATD_CORE_ASSERT(false, "ENGINE_MANAGER::CUDA Not suppoted yet")
      }else if(engine == SUPPORTED_ENGINES::OPEN_CL){
        MATD_CORE_INFO("ENGINE_MANAGER::Context changed to :: OpenCL");
        m_EngineInstance = MATD::ENGINE::Engine::CreateEngine();
        m_EngineInstance->SetPlatforms(m_EngineInstance->GetSupportedPlatforms());
      }else{
        MATD_CORE_ASSERT(false, "ENGINE_MANAGER::Unknown Context Change Detected")
      };
    }

		Ref<std::vector<std::string>> EngineManager::GetSupportedEngines()
		{
      Ref<std::vector<std::string>> engines = std::make_shared<std::vector<std::string>>();
			engines->push_back("OpenCL");
			engines->push_back("CUDA");

      return engines;
		}
  }
}