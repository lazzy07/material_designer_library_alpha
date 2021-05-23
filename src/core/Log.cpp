#include "Log.hpp"
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/rotating_file_sink.h>

namespace MATD {
	namespace CORE {
		Ref<spdlog::logger> Log::s_CoreLogger;
		Ref<spdlog::logger> Log::s_CoreFileLogger;
		
		Ref<spdlog::logger> Log::s_ClientLogger;
		Ref<spdlog::logger> Log::s_ClientFileLogger;

		void Log::Init() {
			spdlog::set_pattern("%^[%T] %n: %v%$");
			s_CoreLogger = spdlog::stdout_color_mt("MATERIAL_DESIGNER");
			s_ClientLogger = spdlog::stdout_color_mt("APPLICATION");

			auto max_size = 1048576 * 1;
			auto max_files = 3;

			s_CoreFileLogger = spdlog::rotating_logger_mt("MATERIAL_DESIGNER_LOG", "logs/core/matd_log.txt", max_size, max_files);
			s_ClientFileLogger = spdlog::rotating_logger_mt("MATERIAL_DESIGNER_APP_LOG", "logs/app/matd_app_log.txt", max_size, max_files);

			s_CoreLogger->set_level(spdlog::level::trace);
			s_ClientLogger->set_level(spdlog::level::trace);
			s_CoreFileLogger->set_level(spdlog::level::trace);
			s_ClientFileLogger->set_level(spdlog::level::trace);
		}

		void Log::AddCoreLogTrace(char* frmt, ...){
			va_list argp;
			s_CoreFileLogger->trace(frmt, argp);
			s_CoreLogger->trace(frmt, argp);
		}

		
		void Log::AddCoreLogInfo(char* frmt, ...){
			va_list argp;
			s_CoreFileLogger->info(frmt, argp);
			s_CoreLogger->info(frmt, argp);
		}

		
		void Log::AddCoreLogWarn(char* frmt, ...){
			va_list argp;
			s_CoreFileLogger->warn(frmt, argp);
			s_CoreLogger->warn(frmt, argp);
		}

		
		void Log::AddCoreLogError(char* frmt, ...){
			va_list argp;
			s_CoreFileLogger->error(frmt, argp);
			s_CoreLogger->error(frmt, argp);
		}

		
		void Log::AddCoreLogFatal(char* frmt, ...){
			va_list argp;
			s_CoreFileLogger->critical(frmt, argp);
			s_CoreLogger->critical(frmt, argp);
		}


		void Log::AddAppLogTrace(char* frmt, ...){
			va_list argp;
			s_ClientFileLogger->trace(frmt, argp);
			s_ClientLogger->trace(frmt, argp);
		}

		
		void Log::AddAppLogInfo(char* frmt, ...){
			va_list argp;
			s_ClientFileLogger->info(frmt, argp);
			s_ClientLogger->info(frmt, argp);
		}

		
		void Log::AddAppLogWarn(char* frmt, ...){
			va_list argp;
			s_ClientFileLogger->warn(frmt, argp);
			s_ClientLogger->warn(frmt, argp);
		}

		
		void Log::AddAppLogError(char* frmt, ...){
			va_list argp;
			s_ClientFileLogger->error(frmt, argp);
			s_ClientLogger->error(frmt, argp);
		}

		
		void Log::AddAppLogFatal(char* frmt, ...){
			va_list argp;
			s_ClientFileLogger->critical(frmt, argp);
			s_ClientLogger->critical(frmt, argp);
		}
	}
}