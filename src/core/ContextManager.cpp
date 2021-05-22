#include <matd/core/ContextManager.hpp>
#include <matd/core/Log.hpp>


MATD::CORE::ContextManager::ContextManager(){
  MATD_CORE_TRACE("CONTEXT_MANAGER::Initialized");
}

MATD::CORE::ContextManager::~ContextManager(){
  MATD_CORE_TRACE("CONTEXT_MANAGER::CLosed");
}