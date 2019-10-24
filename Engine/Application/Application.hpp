#pragma once

#include <memory>

#include "Engine/core.hpp"
#include "Engine/Application/ApplicationState.hpp"
#include "Engine/Clock/Clock.hpp"
#include "Engine/Clock/Stopwatch.hpp"

namespace nova
{
	class NOVA_API Application
	{
	public:
		Application();
		explicit Application(Int64 window_handle);
		
		void start();
		void pause() noexcept;
		void resume() noexcept;
		void stop() noexcept;

		ApplicationState& get_application_state() noexcept;
	private:
		Int64 m_window_handle{ 0 };
		ApplicationState m_state{};

		Stopwatch m_application_stopwatch{};
		Clock m_frame_clock{};
		Clock m_logic_clock{};

		void initialize();
		void update_engine_state() noexcept;
	};


	std::unique_ptr<Application> create_application();
}