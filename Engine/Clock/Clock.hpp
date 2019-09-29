#pragma once

#include <chrono>

#include "Engine/core.hpp"

namespace nova
{	
	class NOVA_API Clock
	{
	public:
		using TickDurationType = std::chrono::milliseconds;
		using ElapsedDurationType = std::chrono::milliseconds;
		
		void start() noexcept;
		void stop() noexcept;
		void tick() noexcept;

		[[nodiscard]] ElapsedDurationType get_elapsed_time() const noexcept;
		[[nodiscard]] TickDurationType get_last_tick_time() const noexcept;
		[[nodiscard]] Int32 get_number_of_ticks() const noexcept;
	private:
		Bool m_is_running{ false };
		Int32 m_number_of_ticks{};
		std::chrono::time_point<std::chrono::steady_clock> m_start_time{};
		std::chrono::time_point<std::chrono::steady_clock> m_last_tick_time{};
		TickDurationType m_last_tick_duration{};
		ElapsedDurationType m_elapsed_duration{};

		void update() noexcept;
	};
}
