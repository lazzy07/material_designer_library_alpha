/**
 * @file Log.hpp
 * @author Lasantha M Senanayake (222lasantha@gmail.com)
 * @brief Logger for Material Designer Engine and Editor
 * @version 0.1
 * @date 2024-11-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once

#define FMT_HEADER_ONLY
#define FMT_DEPRECATED

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#include <memory>

namespace MATD {
	namespace CORE {
		enum class LOGLEVEL{
			TRACE,
			INFO,
			WARN,
			ERR,
			FATAL
		};
		/**
		 * @brief Logger class for Material Designer Engine and Editor
		 * 
		 */
		class Log {
		public:
			/**
			 * @brief Initialize the logger
			 * 
			 */
			static void Init();
			/**
			 * @brief Set the Core Log Level object
			 * 
			 * @param logLevel Log level to set
			 */
			static void SetCoreLogLevel(LOGLEVEL logLevel);

			/**
			 * @brief Set the Editor Log Level object
			 * 
			 * @param logLevel Log level to set
			 */
			static void SetAppLogLevel(LOGLEVEL logLevel);

			/**
			 * @brief Get the Core Logger object
			 * 
			 * @return std::shared_ptr<spdlog::logger>& Core logger
			 */
			inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; };

			/**
			 * @brief Get the Core File Logger object
			 * 
			 * @return std::shared_ptr<spdlog::logger>& Core file logger
			 */
			inline static std::shared_ptr<spdlog::logger>& GetCoreFileLogger() { return s_CoreFileLogger; };

			/**
			 * @brief Get the Client Logger object
			 * 
			 * @return std::shared_ptr<spdlog::logger>& Client logger
			 */
			static std::shared_ptr<spdlog::logger>& GetClientLogger();

			/**
			 * @brief Get the Client File Logger object
			 * 
			 * @return std::shared_ptr<spdlog::logger>& Client file logger
			 */
			static std::shared_ptr<spdlog::logger>& GetClientFileLogger();

		private:
			static std::shared_ptr<spdlog::logger> s_CoreLogger;
			static std::shared_ptr<spdlog::logger> s_CoreFileLogger;
			static std::shared_ptr<spdlog::logger> s_ClientLogger;
			static std::shared_ptr<spdlog::logger> s_ClientFileLogger;
		};
	}
}

//Core log macros
#define MATD_CORE_LOG_LEVEL(x) 		 ::MATD::CORE::Log::SetCoreLogLevel(x)
#define MATD_LOG_LEVEL(x) 		 ::MATD::CORE::Log::SetAppLogLevel(x)

#define MATD_CORE_TRACE(...)   ::MATD::CORE::Log::GetCoreLogger()->trace(__VA_ARGS__); MATD::CORE::Log::GetCoreFileLogger()->trace(__VA_ARGS__)
#define MATD_CORE_INFO(...)    ::MATD::CORE::Log::GetCoreLogger()->info(__VA_ARGS__); MATD::CORE::Log::GetCoreFileLogger()->info(__VA_ARGS__)
#define MATD_CORE_WARN(...)    ::MATD::CORE::Log::GetCoreLogger()->warn(__VA_ARGS__); MATD::CORE::Log::GetCoreFileLogger()->warn(__VA_ARGS__)
#define MATD_CORE_ERROR(...)   ::MATD::CORE::Log::GetCoreLogger()->error(__VA_ARGS__); MATD::CORE::Log::GetCoreFileLogger()->error(__VA_ARGS__)
#define MATD_CORE_FATAL(...)   ::MATD::CORE::Log::GetCoreLogger()->critical(__VA_ARGS__); MATD::CORE::Log::GetCoreFileLogger()->critical(__VA_ARGS__)

//Client log macros
#define MATD_TRACE(...)        ::MATD::CORE::Log::GetClientLogger()->trace(__VA_ARGS__); MATD::CORE::Log::GetClientFileLogger()->trace(__VA_ARGS__)
#define MATD_INFO(...)         ::MATD::CORE::Log::GetClientLogger()->info(__VA_ARGS__); MATD::CORE::Log::GetClientFileLogger()->info(__VA_ARGS__)
#define MATD_WARN(...)         ::MATD::CORE::Log::GetClientLogger()->warn(__VA_ARGS__); MATD::CORE::Log::GetClientFileLogger()->warn(__VA_ARGS__)
#define MATD_ERROR(...)        ::MATD::CORE::Log::GetClientLogger()->error(__VA_ARGS__); MATD::CORE::Log::GetClientFileLogger()->error(__VA_ARGS__)
#define MATD_FATAL(...)        ::MATD::CORE::Log::GetClientLogger()->critical(__VA_ARGS__); MATD::CORE::Log::GetClientFileLogger()->critical(__VA_ARGS__)