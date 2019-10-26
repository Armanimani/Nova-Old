#pragma once

#include <memory>

#include "Engine/core.hpp"
#include "Engine/Application/ApplicationState.hpp"
#include "Engine/Application/ApplicationSettings.hpp"
#include "Engine/Clock/Clock.hpp"
#include "Engine/Clock/Stopwatch.hpp"
#include "Engine/Graphics/GraphicSystem.hpp"

namespace nova
{
	class NOVA_API Application
	{
	public:
		Application(ApplicationSettings settings);
		explicit Application(ApplicationSettings settings, void* window_handle);
		
		void start();
		void pause() noexcept;
		void resume() noexcept;
		void stop() noexcept;

		ApplicationState& get_application_state() noexcept;
	private:
		void* m_window_handle{};
		
		ApplicationState m_state{};
		ApplicationSettings m_settings{};

		Stopwatch m_application_stopwatch{};
		Clock m_frame_clock{};
		Clock m_logic_clock{};

		std::unique_ptr<graphics::GraphicSystem> m_graphic_system{};

		void initialize();
		void update_engine_state() noexcept;
	};


	std::unique_ptr<Application> create_application();
}