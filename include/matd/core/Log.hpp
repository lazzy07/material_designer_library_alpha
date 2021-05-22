#pragma once

#define FMT_HEADER_ONLY
#define FMT_DEPRECATED

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#include "Core.hpp"

namespace MATD {
	namespace CORE {
		class Log {
		public:
			static void Init();

			inline static Ref<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; };
			inline static Ref<spdlog::logger>& GetClientLogger() { return s_ClientLogger; };

		private:
			static Ref<spdlog::logger> s_CoreLogger;
			static Ref<spdlog::logger> s_ClientLogger;
		};
	}
}

//Core log macros
#define MATD_CORE_TRACE(...)   ::MATD::CORE::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define MATD_CORE_INFO(...)    ::MATD::CORE::Log::GetCoreLogger()->info(__VA_ARGS__)
#define MATD_CORE_WARN(...)    ::MATD::CORE::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define MATD_CORE_ERROR(...)   ::MATD::CORE::Log::GetCoreLogger()->error(__VA_ARGS__)
#define MATD_CORE_FATAL(...)   ::MATD::CORE::Log::GetCoreLogger()->critical(__VA_ARGS__)

//Client log macros
#define MATD_TRACE(...)        ::MATD::CORE::Log::GetClientLogger()->trace(__VA_ARGS__)
#define MATD_INFO(...)         ::MATD::CORE::Log::GetClientLogger()->info(__VA_ARGS__)
#define MATD_WARN(...)         ::MATD::CORE::Log::GetClientLogger()->warn(__VA_ARGS__)
#define MATD_ERROR(...)        ::MATD::CORE::Log::GetClientLogger()->error(__VA_ARGS__)
#define MATD_FATAL(...)        ::MATD::CORE::Log::GetClientLogger()->critical(__VA_ARGS__)