#include <matd/core/Log.hpp>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace MATD {
	namespace CORE {
		Ref<spdlog::logger> Log::s_CoreLogger;
		Ref<spdlog::logger> Log::s_ClientLogger;

		void Log::Init() {
			spdlog::set_pattern("%^[%T] %n: %v%$");
			s_CoreLogger = spdlog::stdout_color_mt("MATERIAL_DESIGNER");
			s_CoreLogger->set_level(spdlog::level::trace);
			s_ClientLogger = spdlog::stdout_color_mt("APPLICATION");
			s_ClientLogger->set_level(spdlog::level::trace);
		}
	}
}