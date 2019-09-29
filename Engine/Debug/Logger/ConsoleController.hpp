#pragma once

#include <string_view>

#include "Engine/core.hpp"

namespace nova
{
	// TODO this class need to support multi-threading in the future
	class ConsoleController
	{
	public:	
		using ConsoleColor = Int32;

		ConsoleController() = delete;
		
		static void set_color(ConsoleColor text_color);
		static void print_message(const std::string_view& message);
	};
}
