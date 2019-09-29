#include "Engine/Clock/Stopwatch.hpp"

namespace nova
{
	void Stopwatch::start() noexcept
	{
		if (m_is_running)
			return;
		
		m_start_time = std::chrono::steady_clock::now();
		m_is_running = true;
	}

	void Stopwatch::stop() noexcept
	{
		if (!m_is_running)
			return;

		const auto now = std::chrono::steady_clock::now();
		
		m_elapsed_duration += std::chrono::duration_cast<ElapsedDurationType>(now - m_start_time);
		m_is_running = false;
	}

	void Stopwatch::reset() noexcept
	{
		m_elapsed_duration = {};
		m_start_time = std::chrono::steady_clock::now();
	}

	Stopwatch::ElapsedDurationType Stopwatch::get_elapsed_time() const noexcept
	{
		if (!m_is_running)
		{
			return m_elapsed_duration;
		}

		const auto current_duration = std::chrono::duration_cast<ElapsedDurationType>(std::chrono::steady_clock::now() - m_start_time);
		return m_elapsed_duration + current_duration;
	}
}
