#include "Engine/Application/Application.hpp"
#include "Engine/Graphics/GraphicSystem.hpp"
#include "Engine/Context/ContextManager.hpp"

#include <iostream>

namespace nova
{
	Application::Application(const ApplicationSettings settings) : m_settings{ settings }
	{
		
	}
	
	void Application::initialize()
	{
		LOG_ENGINE_INFORMATION("Initializing...");
		m_application_stopwatch.start();
		
		m_state.run_state = ApplicationState::RunState::stopped;

		if (!m_settings.graphics.window_handle)
		{
			// TODO: in this case we need to create a window and assign its handle to graphic settings
			LOG_ENGINE_ERROR("window_handle is not specified, creation of the window is not supported yet!");
		}
		
		initialize_context();

		const auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(m_application_stopwatch.get_elapsed_time());
		LOG_ENGINE_INFORMATION("Done! took " + std::to_string(elapsed_time.count()) +" ms");
	}

	void Application::initialize_context() noexcept
	{
		m_context = ContextManager::create(m_settings);
		m_graphic_system = std::make_unique<graphics::GraphicSystem>(m_context->graphic_context.get());
	}

	void Application::start()
	{
		initialize();
		
		LOG_ENGINE_INFORMATION("Running...");
		
		// starting the clocks
		m_logic_clock.start();
		m_frame_clock.start();

		// Note: Initialization of graphic context should be done after creation of the window
		m_graphic_system->initialize();
		
		// starting the main loop
		m_state.run_state.store(ApplicationState::RunState::running);
		while (m_state.run_state != ApplicationState::RunState::stopped)
		{
			m_logic_clock.tick();

			m_graphic_system->present();
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
