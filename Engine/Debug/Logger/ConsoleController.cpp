#include "Engine/Debug/Logger/ConsoleController.hpp"

#include <iostream>
#include <windows.h>

namespace nova
{	
	void ConsoleController::set_color(const ConsoleColor text_color)
	{
		static HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, text_color);
	}

	void ConsoleController::print_message(const std::string_view& message)
	{
		std::cout << message << '\n';
	}
}
