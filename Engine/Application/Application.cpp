#include "Engine//Application/Application.hpp"


namespace nova
{	
	void Application::run()
	{
		LOG_ENGINE_ERROR("Error");
		LOG_ENGINE_WARNING("Warning");
		LOG_ENGINE_INFORMATION("Information");
		LOG_APPLICATION_ERROR("Error");
		LOG_APPLICATION_WARNING("Warning");
		LOG_APPLICATION_INFORMATION("Information");
	}
}
