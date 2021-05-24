#include "../../core/Core.hpp"
#include "Context.hpp"
#include "../../core/ContextManager.hpp"
#include "../vendor/opencl/CLContext.hpp"
#include <memory>

namespace MATD{
  namespace ENGINE{
    Ref<Context> Context::CreateContext(){
      CORE::SUPPORTED_CONTEXTS context = CORE::ContextManager::GetSelectedContext();

      switch(context){
        case CORE::SUPPORTED_CONTEXTS::OPEN_CL:
            MATD_CORE_TRACE("MATD_CONTEXT::Created context with OpenCL");
            return std::make_shared<ENGINE::OPENCL::Context>();
          break;

        case CORE::SUPPORTED_CONTEXTS::CUDA:
          MATD_CORE_ASSERT(false,"Context not supported yet")
          return nullptr;
          break;
      }
      MATD_CORE_ASSERT(false, "Un-identified context selected");
      return nullptr;
    }
  }
}