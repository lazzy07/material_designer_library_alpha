#include "ContextManager.hpp"
#include "Log.hpp"
#include "Core.hpp"
#include "../engine/vendor/opencl/CLContext.hpp"

namespace MATD{
  namespace CORE{
    SUPPORTED_CONTEXTS ContextManager::s_Context = SUPPORTED_CONTEXTS::OPEN_CL;

    ContextManager::ContextManager(SUPPORTED_CONTEXTS context){
      MATD_CORE_TRACE("CONTEXT_MANAGER::Initialized");

      SelectContext(context);
    }
    
    ContextManager::~ContextManager(){
      MATD_CORE_TRACE("CONTEXT_MANAGER::Closed");
    }

    void ContextManager::SelectContext(SUPPORTED_CONTEXTS context){
      std::string ctx = "";

      if(context == SUPPORTED_CONTEXTS::CUDA){
        //TODO:: Add CUDA SUPPORT
        MATD_CORE_TRACE("CONTEXT_MANAGER::Context changed to :: CUDA");
        MATD_CORE_ASSERT(false, "CONTEXT_MANAGER::CUDA Not suppoted yet")
      }else if(context == SUPPORTED_CONTEXTS::OPEN_CL){
        m_Context = std::make_shared<MATD::ENGINE::OPENCL::Context>();
        MATD_CORE_TRACE("CONTEXT_MANAGER::Context changed to :: OPENCL");
      }else{
        MATD_CORE_ASSERT(false, "CONTEXT_MANAGER::Unknown Context Change Detected")
      };

      s_Context = context;
    }
  }
}