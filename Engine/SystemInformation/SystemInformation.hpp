#pragma once

#include "Engine/core.hpp"

#include <vector>
#include <string>
#include <mutex>

namespace nova
{
	constexpr Float k_byte_to_gigabyte_ratio = 1.0f / 1024.0f / 1024.0f / 1024.0f;
	
	struct NOVA_API GraphicCardInformation
	{
		std::size_t dedicated_video_memory{};
		std::size_t dedicated_system_memory{};
		std::size_t system_shared_memory{};
		std::string description{};
	};
	
	struct NOVA_API SystemInformation
	{
		static std::mutex graphic_cards_mutex;
		static std::vector<GraphicCardInformation> graphic_cards;
	};
}
