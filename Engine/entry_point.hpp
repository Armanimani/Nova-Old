#pragma once

#include <memory>

#include "Engine/Application/Application.hpp"
#include "Engine/Debug/Logger/LoggerManager.hpp"
#include "Engine/core.hpp"


extern std::unique_ptr<nova::Application> create_application();


#ifdef NOVA_PLATFORM_WINDOWS

int main()
{		
	auto application = create_application();
	application->run();

	return EXIT_SUCCESS;
}
#else
	#error "Nova only compatible with windows!"
#endif