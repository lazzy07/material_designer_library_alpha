#include <matd/core/ContextManager.hpp>
#include <matd/core/Log.hpp>


MATD::CORE::ContextManager::ContextManager(){
  MATD_CORE_TRACE("CONTEXT_MANAGER::Initialized");
}

MATD::CORE::ContextManager::~ContextManager(){
  MATD_CORE_TRACE("CONTEXT_MANAGER::Closed");
}

void MATD::CORE::ContextManager::SelectContext(SUPPORTED_CONTEXTS context){
  std::string ctx;

  if(context == MATD::CORE::CUDA){
    ctx = "CUDA";
  }else if(context == MATD::CORE::OPEN_CL){
    ctx = "OPEN_CL";
  }else{
    MATD_ASSERT(false, "CONTEXT_MANAGER::Unknown Context Change Detected")
  };

  MATD_CORE_TRACE("CONTEXT_MANAGER::Context changed to {}", ctx);
  m_Context = context;
}