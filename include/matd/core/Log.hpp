#pragma once
#include <spdlog/spdlog.h>

namespace MATD {
	namespace CORE {
		enum LOGLEVEL{
			TRACE,
			INFO,
			WARN,
			ERR,
			FATAL
		};
		
		class Log {
		public:
			static void SetCoreLogLevel(LOGLEVEL logLevel);
			static void SetAppLogLevel(LOGLEVEL logLevel);

			static std::shared_ptr<spdlog::logger>& GetClientLogger();
			static std::shared_ptr<spdlog::logger>& GetClientFileLogger();
		};
	}
}

//Client log macros
#define MATD_CORE_LOG_LEVEL(x) 		 ::MATD::CORE::Log::SetCoreLogLevel(x)
#define MATD_LOG_LEVEL(x) 		 ::MATD::CORE::Log::SetAppLogLevel(x)

//Client log macros
#define MATD_TRACE(...)        ::MATD::CORE::Log::GetClientLogger()->trace(__VA_ARGS__); MATD::CORE::Log::GetClientFileLogger()->trace(__VA_ARGS__)
#define MATD_INFO(...)         ::MATD::CORE::Log::GetClientLogger()->info(__VA_ARGS__); MATD::CORE::Log::GetClientFileLogger()->info(__VA_ARGS__)
#define MATD_WARN(...)         ::MATD::CORE::Log::GetClientLogger()->warn(__VA_ARGS__); MATD::CORE::Log::GetClientFileLogger()->warn(__VA_ARGS__)
#define MATD_ERROR(...)        ::MATD::CORE::Log::GetClientLogger()->error(__VA_ARGS__); MATD::CORE::Log::GetClientFileLogger()->error(__VA_ARGS__)
#define MATD_FATAL(...)        ::MATD::CORE::Log::GetClientLogger()->critical(__VA_ARGS__); MATD::CORE::Log::GetClientFileLogger()->critical(__VA_ARGS__)