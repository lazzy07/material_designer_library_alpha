#include "../../core/Core.hpp"
#include "Context.hpp"
#include "../../core/ContextManager.hpp"


namespace MATD{
  namespace ENGINE{
    Context* Context::CreateContext(){
      CORE::SUPPORTED_CONTEXTS context = CORE::ContextManager::GetSelectedContext();

      switch(context){
        case CORE::SUPPORTED_CONTEXTS::OPEN_CL:
            MATD_CORE_TRACE("MATD_CONTEXT::Initialized");

          break;

        case CORE::SUPPORTED_CONTEXTS::CUDA:
          MATD_CORE_ASSERT(false,"Context not supported yet")
          return nullptr;
          break;
      }
      MATD_CORE_ASSERT(false, "Unidentified context selected");
      return nullptr;
    }
  }
}