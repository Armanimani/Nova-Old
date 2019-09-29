#pragma once

#include <chrono>

#include "Engine/core.hpp"

namespace nova
{
	class NOVA_API Timer
	{
	public:
		using RemainingDurationType = std::chrono::milliseconds;
		
		explicit Timer(std::chrono::seconds scheduled_duration);
		explicit Timer(std::chrono::milliseconds scheduled_duration);
		
		void start() noexcept;
		[[nodiscard]] Bool is_ready() const noexcept;
		[[nodiscard]] RemainingDurationType get_scheduled_duration() const noexcept;
		[[nodiscard]] RemainingDurationType get_remaining_duration() const noexcept;
		[[nodiscard]] Bool is_running() const noexcept;
	private:
		Bool m_is_running{ false };
		std::chrono::time_point<std::chrono::steady_clock> m_start_time{};
		RemainingDurationType m_scheduled_duration{};
	};
}