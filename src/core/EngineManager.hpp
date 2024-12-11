/**
 * @file EngineManager.hpp
 * @author Lasantha M Senanayake (222lasantha@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2024-11-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once
#include "../engine/matd/Engine.hpp"

namespace MATD{
  namespace CORE{
    enum class SUPPORTED_ENGINES{
      OPEN_CL,
      CUDA
    };
    /**
     * @brief Manages engine selection and instance, this is a singleton class. Which selects the engine types, currently only OpenCL is supported
     * 
     */
    class EngineManager{
      public:
        /**
         * @brief Selects the engine type
         * 
         * @param engine Engine type to select, currently only OpenCL is supported
         */
        static void SelectEngine(const SUPPORTED_ENGINES& engine);

        /**
         * @brief Get the supported engines
         * 
         * @return Ref<std::vector<std::string>> List of supported engines
         */
        static Ref<std::vector<std::string>> GetSupportedEngines();

        /**
         * @brief Get the Selected Engine object
         * 
         * @return SUPPORTED_ENGINES Selected engine type
         */
				static SUPPORTED_ENGINES GetSelectedEngine() { return m_Engine; }

        /**
         * @brief Get the Engine Instance object
         * 
         * @return Ref<MATD::ENGINE::Engine> Engine instance
         */
				static Ref<MATD::ENGINE::Engine> GetEngineInstance() { return m_EngineInstance; }
      private:
        static SUPPORTED_ENGINES m_Engine;
        static Ref<MATD::ENGINE::Engine> m_EngineInstance;
    };
  };
}