#include "Log.hpp"
#include <spdlog/sinks/stdout_sinks.h>

namespace MATD {
	namespace CORE {
		Ref<spdlog::logger> Log::s_CoreLogger;
		Ref<spdlog::logger> Log::s_ClientLogger;

		void Log::Init() {
			spdlog::set_pattern("%^[%T] %n: %v%$");
			s_CoreLogger = spdlog::stderr_logger_mt("VULTURE");
			s_CoreLogger->set_level(spdlog::level::trace);
			s_ClientLogger = spdlog::stderr_logger_mt("APPLICATION");
			s_ClientLogger->set_level(spdlog::level::trace);
		}
	}
}