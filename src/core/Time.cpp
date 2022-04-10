#include "Time.hpp"
#include <chrono>

uint64_t MATD::CORE::Time::GetTime()
{
	return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}
