#pragma once

#include <memory>

#include "Engine/core.hpp"
#include "Engine/Application/ApplicationState.hpp"
#include "Engine/Application/ApplicationSettings.hpp"
#include "Engine/Clock/Clock.hpp"
#include "Engine/Clock/Stopwatch.hpp"
#include "Engine/Graphics/GraphicSystem.hpp"
#include "Engine/Context/Context.hpp"

namespace nova
{
	class NOVA_API Application
	{
	public:
		explicit Application(ApplicationSettings settings);
		
		void start();
		void pause() noexcept;
		void resume() noexcept;
		void stop() noexcept;

		ApplicationState& get_application_state() noexcept;
	private:		
		ApplicationSettings m_settings{};
		std::unique_ptr<Context> m_context{};
		
		ApplicationState m_state{};

		Stopwatch m_application_stopwatch{};
		Clock m_frame_clock{};
		Clock m_logic_clock{};

		std::unique_ptr<graphics::GraphicSystem> m_graphic_system{};

		void initialize_context() noexcept;
		void initialize();
		void update_engine_state() noexcept;
	};


	std::unique_ptr<Application> create_application();
}