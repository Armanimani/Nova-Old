#pragma once

#include <chrono>

#include "Engine/core.hpp"

namespace nova
{
	class NOVA_API Stopwatch
	{
	public:
		using ElapsedDurationType = std::chrono::milliseconds;
		
		void start() noexcept;
		void stop() noexcept;
		void reset() noexcept;

		[[nodiscard]] ElapsedDurationType get_elapsed_time() const noexcept;
	private:
		Bool m_is_running{ false };
		std::chrono::time_point<std::chrono::steady_clock> m_start_time{};
		ElapsedDurationType m_elapsed_duration{};
	};
}