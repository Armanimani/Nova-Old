#include "Engine/Clock/Clock.hpp"

namespace nova
{
	void Clock::start() noexcept
	{
		if (m_is_running)
		{
			LOG_ENGINE_ERROR("Unable to start the clock! The clock is already started!");
			return;
		}

		const auto now{ std::chrono::steady_clock::now() };

		m_is_running = true;
		m_start_time = now;
		m_last_tick_time = now;
	}

	void Clock::stop() noexcept
	{
		if (!m_is_running)
		{
			LOG_ENGINE_WARNING("Unable to stop the clock! The clock is already stopped!");
			return;
		}

		tick();
		m_is_running = false;
	}

	void Clock::tick() noexcept
	{
		update();
	}

	Clock::ElapsedDurationType Clock::get_elapsed_time() const noexcept
	{
		return m_elapsed_duration;
	}

	Clock::TickDurationType Clock::get_last_tick_time() const noexcept
	{
		return m_last_tick_duration;
	}

	Int32 Clock::get_number_of_ticks() const noexcept
	{
		return m_number_of_ticks;
	}

	void Clock::update() noexcept
	{
		if (!m_is_running)
			return;

		auto const now{ std::chrono::steady_clock::now() };

		m_number_of_ticks++;
		m_last_tick_duration = std::chrono::duration_cast<TickDurationType>(now - m_last_tick_time);
		m_elapsed_duration = std::chrono::duration_cast<ElapsedDurationType>(now - m_start_time);

		m_last_tick_time = now;
	}
}
