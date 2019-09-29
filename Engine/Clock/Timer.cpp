#include "Engine/Clock/Timer.hpp"

namespace nova
{
	Timer::Timer(const std::chrono::seconds scheduled_duration) : m_scheduled_duration{ std::chrono::duration_cast<std::chrono::milliseconds>(scheduled_duration) }
	{
	}

	Timer::Timer(const std::chrono::milliseconds scheduled_duration) : m_scheduled_duration{ scheduled_duration }
	{
	}

	void Timer::start() noexcept
	{
		m_start_time = std::chrono::steady_clock::now();
		m_is_running = true;
	}

	Bool Timer::is_ready() const noexcept
	{
		if (!m_is_running)
			return false;
		
		const auto now = std::chrono::steady_clock::now();

		return ((now - m_start_time) > m_scheduled_duration);
	}

	Timer::RemainingDurationType Timer::get_scheduled_duration() const noexcept
	{
		return m_scheduled_duration;
	}

	Timer::RemainingDurationType Timer::get_remaining_duration() const noexcept
	{
		if (!m_is_running)
			return m_scheduled_duration;
		
		const auto now = std::chrono::steady_clock::now();
		const auto remaining_duration = m_scheduled_duration - (now - m_start_time);

		if (remaining_duration.count() < 0)
		{
			return {};
		}
		return std::chrono::duration_cast<RemainingDurationType>(remaining_duration);
	}

	Bool Timer::is_running() const noexcept
	{
		return m_is_running;
	}
}
