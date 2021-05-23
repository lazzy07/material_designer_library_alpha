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

		class Log {
		public:
			static void Init();
			static void SetCoreLogLevel(LOGLEVEL logLevel);
			static void SetAppLogLevel(LOGLEVEL logLevel);

			inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; };
			inline static std::shared_ptr<spdlog::logger>& GetCoreFileLogger() { return s_CoreFileLogger; };
			inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; };
			inline static std::shared_ptr<spdlog::logger>& GetClientFileLogger() { return s_ClientFileLogger; };

			static void AddCoreLogTrace(char* frmt, ...);
			static void AddCoreLogInfo(char* frmt, ...);
			static void AddCoreLogWarn(char* frmt, ...);
			static void AddCoreLogError(char* frmt, ...);
			static void AddCoreLogFatal(char* frmt, ...);

			static void AddAppLogTrace(char* frmt, ...);
			static void AddAppLogInfo(char* frmt, ...);
			static void AddAppLogWarn(char* frmt, ...);
			static void AddAppLogError(char* frmt, ...);
			static void AddAppLogFatal(char* frmt, ...);

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

#define MATD_CORE_TRACE(...)   ::MATD::CORE::Log::AddCoreLogTrace(__VA_ARGS__)
#define MATD_CORE_INFO(...)    ::MATD::CORE::Log::AddCoreLogInfo(__VA_ARGS__)
#define MATD_CORE_WARN(...)    ::MATD::CORE::Log::AddCoreLogWarn(__VA_ARGS__)
#define MATD_CORE_ERROR(...)   ::MATD::CORE::Log::AddCoreLogError(__VA_ARGS__)
#define MATD_CORE_FATAL(...)   ::MATD::CORE::Log::AddCoreLogFatal(__VA_ARGS__)

//Client log macros
#define MATD_TRACE(...)        ::MATD::CORE::Log::AddAppLogTrace(__VA_ARGS__)
#define MATD_INFO(...)         ::MATD::CORE::Log::AddAppLogInfo(__VA_ARGS__)
#define MATD_WARN(...)         ::MATD::CORE::Log::AddAppLogWarn(__VA_ARGS__)
#define MATD_ERROR(...)        ::MATD::CORE::Log::AddAppLogError(__VA_ARGS__)
#define MATD_FATAL(...)        ::MATD::CORE::Log::AddAppLogFatal(__VA_ARGS__)