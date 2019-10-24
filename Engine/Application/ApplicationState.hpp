#pragma once

#include <atomic>
#include <chrono>

#include "Engine/core.hpp"

namespace nova
{
	struct NOVA_API ApplicationState
	{
		enum class RunState
		{
			stopped,
			running,
			paused
		};

		std::atomic<RunState> run_state{ RunState::stopped };
		
		std::atomic<std::chrono::milliseconds> up_time{};
		std::atomic<std::chrono::milliseconds> last_frame_time{};
		std::atomic<std::chrono::milliseconds> last_logic_time{};
		
		std::atomic<float> fps{};
		std::atomic<float> ups{};
	};
}