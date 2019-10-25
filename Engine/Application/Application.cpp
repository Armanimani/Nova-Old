#include "Engine/Application/Application.hpp"
#include "Engine/Graphics/Context/GraphicContextManager.hpp"

#include <thread>
#include <GL/glew.h>
#include <iostream>

namespace nova
{
	Application::Application(const ApplicationSettings settings) : m_settings{ settings }
	{		
		//TODO: Create a window here and assign the handle to m_window_handle

		initialize();
	}

	Application::Application(const ApplicationSettings settings, const Int64 window_handle) : m_settings{ settings }, m_window_handle { window_handle }
	{
		initialize();
	}

	void Application::initialize()
	{
		LOG_ENGINE_INFORMATION("Initializing...");
		m_application_stopwatch.start();

		GraphicContextManager::Create(m_window_handle, m_settings.graphic_api);
		
		m_state.run_state = ApplicationState::RunState::stopped;

		const auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(m_application_stopwatch.get_elapsed_time());
		LOG_ENGINE_INFORMATION("Done! took " + std::to_string(elapsed_time.count()) +" ms");
	}

	void Application::start()
	{
		LOG_ENGINE_INFORMATION("Running...");
		
		// starting the clocks
		m_logic_clock.start();
		m_frame_clock.start();

		// Note: Initialization of graphic context should be done after creation of the window
		GraphicContextManager::initialize();
		
		// starting the main loop
		m_state.run_state.store(ApplicationState::RunState::running);
		while (m_state.run_state != ApplicationState::RunState::stopped)
		{
			m_logic_clock.tick();

			GraphicContextManager::present();
			update_engine_state();
		}

		LOG_ENGINE_INFORMATION("Done! took " + std::to_string(m_state.up_time.load().count()) + " ms");
	}

	void Application::pause() noexcept
	{
		if (m_state.run_state == ApplicationState::RunState::running)
		{
			m_state.run_state.store(ApplicationState::RunState::paused);
			LOG_ENGINE_INFORMATION("Paused!");
		}
		else
		{
			LOG_ENGINE_WARNING("Unable to pause the application, the application is not in running state!");
		}
	}

	void Application::resume() noexcept
	{
		if (m_state.run_state == ApplicationState::RunState::paused)
		{
			m_state.run_state.store(ApplicationState::RunState::running);
			LOG_ENGINE_INFORMATION("Resumed!");
		}
		else
		{
			LOG_ENGINE_WARNING("Unable to resume the application, the application is not paused!");
		}
	}

	void Application::stop() noexcept
	{
		m_state.run_state.store(ApplicationState::RunState::stopped);
		LOG_ENGINE_INFORMATION("Stopped!");
	}

	ApplicationState& Application::get_application_state() noexcept
	{
		return m_state;
	}

	void Application::update_engine_state() noexcept
	{
		const auto up_time{ m_application_stopwatch.get_elapsed_time() };
		m_state.up_time.store(up_time);

		constexpr auto milliseconds_in_second{ 1000.0f };
		
		const auto last_frame_time{ m_frame_clock.get_last_tick_time() };
		m_state.last_frame_time.store(last_frame_time);
		m_state.fps.store(milliseconds_in_second / last_frame_time.count());

		const auto last_logic_time{ m_logic_clock.get_last_tick_time() };
		m_state.last_logic_time.store(last_logic_time);
		m_state.ups.store(milliseconds_in_second / last_logic_time.count());
	}
}
