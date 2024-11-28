#include "Log.hpp"
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/rotating_file_sink.h>

namespace MATD {
	namespace CORE {
		std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
		std::shared_ptr<spdlog::logger> Log::s_CoreFileLogger;
		
		std::shared_ptr<spdlog::logger> Log::s_ClientLogger;
		std::shared_ptr<spdlog::logger> Log::s_ClientFileLogger;

		std::shared_ptr<spdlog::logger>& Log::GetClientLogger(){
			return Log::s_ClientLogger;
		}

		std::shared_ptr<spdlog::logger>& Log::GetClientFileLogger(){
			return Log::s_ClientFileLogger;
		}

		void Log::Init() {
			if (s_CoreLogger.get() != nullptr) {
				return;
			}

			spdlog::set_pattern("%^[%T] %n: %v%$");
			s_CoreLogger = spdlog::stdout_color_mt("MATD_CORE");
			s_ClientLogger = spdlog::stdout_color_mt("MATD_APP");

			auto max_size = 1048576 * 1;
			auto max_files = 3;

			s_CoreFileLogger = spdlog::rotating_logger_mt("MATD_CORE_LOG", "logs/core/matd_log.txt", max_size, max_files);
			s_ClientFileLogger = spdlog::rotating_logger_mt("MATD_APP_LOG", "logs/app/matd_app_log.txt", max_size, max_files);

			SetCoreLogLevel(LOGLEVEL::TRACE);
			SetAppLogLevel(LOGLEVEL::TRACE);
		}

		void Log::SetCoreLogLevel(LOGLEVEL logLevel){
			switch(logLevel){
				case LOGLEVEL::TRACE:
						s_CoreLogger->set_level(spdlog::level::trace);
						s_CoreFileLogger->set_level(spdlog::level::trace);
					break;

				case LOGLEVEL::INFO:
						s_CoreLogger->set_level(spdlog::level::info);
						s_CoreFileLogger->set_level(spdlog::level::info);
					break;

				case LOGLEVEL::WARN:
						s_CoreLogger->set_level(spdlog::level::warn);
						s_CoreFileLogger->set_level(spdlog::level::warn);
					break;

				case LOGLEVEL::ERR:
						s_CoreLogger->set_level(spdlog::level::err);
						s_CoreFileLogger->set_level(spdlog::level::err);
				break;

				case LOGLEVEL::FATAL:
						s_CoreLogger->set_level(spdlog::level::critical);
						s_CoreFileLogger->set_level(spdlog::level::critical);
				break;
			}
		}

		void Log::SetAppLogLevel(LOGLEVEL logLevel){
			switch(logLevel){
				case LOGLEVEL::TRACE:
						s_ClientLogger->set_level(spdlog::level::trace);
						s_ClientFileLogger->set_level(spdlog::level::trace);
					break;

				case LOGLEVEL::INFO:
						s_ClientLogger->set_level(spdlog::level::info);
						s_ClientFileLogger->set_level(spdlog::level::info);
					break;

				case LOGLEVEL::WARN:
						s_ClientLogger->set_level(spdlog::level::warn);
						s_ClientFileLogger->set_level(spdlog::level::warn);
					break;

				case LOGLEVEL::ERR:
						s_ClientLogger->set_level(spdlog::level::err);
						s_ClientFileLogger->set_level(spdlog::level::err);
				break;

				case LOGLEVEL::FATAL:
						s_ClientLogger->set_level(spdlog::level::critical);
						s_ClientFileLogger->set_level(spdlog::level::critical);
				break;
			}
		}
	}
}