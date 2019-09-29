#include <thread>

#include "Engine/Clock/Timer.hpp"
#include "gtest/gtest.h"

void timer_wait()
{
	std::this_thread::sleep_for(std::chrono::milliseconds{ 5 });
}

TEST(Timer, Timer_WithoutStart)
{
	constexpr std::chrono::milliseconds scheduled_time_in_ms{ 2 };
	const nova::Timer timer{ scheduled_time_in_ms };

	timer_wait();

	ASSERT_EQ(timer.get_scheduled_duration().count(), scheduled_time_in_ms.count());
	ASSERT_EQ(timer.get_remaining_duration().count(), scheduled_time_in_ms.count());
	ASSERT_EQ(timer.is_ready(), false);
	ASSERT_EQ(timer.is_running(), false);
}

TEST(Timer, Timer_WithStart_TimerExpired)
{
	constexpr std::chrono::milliseconds scheduled_time_in_ms{ 2 };
	nova::Timer timer{ scheduled_time_in_ms };

	timer.start();
	timer_wait();

	ASSERT_EQ(timer.get_scheduled_duration().count(), scheduled_time_in_ms.count());
	ASSERT_EQ(timer.get_remaining_duration().count(), 0);
	ASSERT_EQ(timer.is_ready(), true);
	ASSERT_EQ(timer.is_running(), true);
}

TEST(Timer, Timer_WithStart_TimerRunning)
{
	constexpr std::chrono::milliseconds scheduled_time_in_ms{ 100 };
	nova::Timer timer{ scheduled_time_in_ms };

	timer.start();
	timer_wait();

	ASSERT_EQ(timer.get_scheduled_duration().count(), scheduled_time_in_ms.count());
	ASSERT_GE(timer.get_remaining_duration().count(), 0);
	ASSERT_EQ(timer.is_ready(), false);
	ASSERT_EQ(timer.is_running(), true);
}