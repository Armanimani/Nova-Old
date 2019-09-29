#pragma once

#include "Engine/core.hpp"

namespace nova
{
	struct CalenderInformation
	{
		Int32 year{};
		Int32 month{};
		Int32 day{};
		Int32 hour{};
		Int32 minute{};
		Int32 second{};
	};
	
	class NOVA_API CalenderClock
	{
	public:
		static CalenderInformation get_calender_information() noexcept;
	};
}