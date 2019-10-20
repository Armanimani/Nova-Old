#include "Engine/Application/Application.hpp"

#include "Engine/Clock/Clock.hpp"
#include <thread>

namespace nova
{
	Application::Application()
	{
		//TODO: Create a window here and assign the handle to m_window_handle
	}

	Application::Application(Int64 window_handle) : m_window_handle{window_handle}
	{
	}

	void Application::run()
	{
		LOG_ENGINE_ERROR("Error");
		LOG_ENGINE_WARNING("Warning");
		LOG_ENGINE_INFORMATION("Information");
		LOG_APPLICATION_ERROR("Error");
		LOG_APPLICATION_WARNING("Warning");
		LOG_APPLICATION_INFORMATION("Information");

		Clock clock;
		clock.start();

		for (int i = 0; i != 10; ++i)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds{1000});
			LOG_ENGINE_INFORMATION(
				"tick time -> " + std::to_string(clock.get_last_tick_time().count()) + " ms " + 
				"elapsed time -> " + std::to_string(clock.get_elapsed_time().count()) + " s");
			clock.tick();
		}
		clock.stop();

		LOG_ENGINE_INFORMATION("total time -> " + std::to_string(clock.get_elapsed_time().count()) + " s");
	}
}
