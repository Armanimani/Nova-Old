#include "Engine/Clock/CalenderClock.hpp"

#include <chrono>
#include <ctime>

namespace nova
{
	constexpr auto k_year_base = 1900;
	
	CalenderInformation CalenderClock::get_calender_information() noexcept
	{
		const auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
		tm time_structure{};
		localtime_s(&time_structure, &now);
		
		return { time_structure.tm_year + k_year_base, time_structure.tm_mon, time_structure.tm_mday, time_structure.tm_hour, time_structure.tm_min, time_structure.tm_sec };
	}
}
