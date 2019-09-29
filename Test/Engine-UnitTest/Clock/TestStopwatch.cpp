#include <thread>

#include "Engine/Clock/Stopwatch.hpp"
#include "gtest/gtest.h"

void stopwatch_wait()
{
	std::this_thread::sleep_for(std::chrono::milliseconds{ 2 });
}

TEST(Stopwatch, Initialization)
{
	const nova::Stopwatch stopwatch;
	stopwatch_wait();

	ASSERT_EQ(stopwatch.get_elapsed_time().count(), 0.0);
}

TEST(Stopwatch, Start)
{
	nova::Stopwatch stopwatch;

	stopwatch.start();
	stopwatch_wait();

	ASSERT_NE(stopwatch.get_elapsed_time().count(), 0.0);
}

TEST(Stopwatch, Stop)
{
	nova::Stopwatch stopwatch;

	stopwatch.start();
	stopwatch_wait();

	stopwatch.stop();

	const auto initial_elapsed_time = stopwatch.get_elapsed_time();

	stopwatch_wait();
	const auto final_elapsed_time = stopwatch.get_elapsed_time();
	
	ASSERT_EQ(initial_elapsed_time.count(), final_elapsed_time.count());
}

TEST(Stopwatch, Reset_WithStop)
{
	nova::Stopwatch stopwatch;

	stopwatch.start();
	stopwatch_wait();

	stopwatch.stop();

	ASSERT_NE(stopwatch.get_elapsed_time().count(), 0);

	stopwatch.reset();
	stopwatch_wait();
	ASSERT_EQ(stopwatch.get_elapsed_time().count(), 0);
}

TEST(Stopwatch, Reset_WithoutStop)
{
	nova::Stopwatch stopwatch;

	stopwatch.start();
	stopwatch_wait();

	ASSERT_NE(stopwatch.get_elapsed_time().count(), 0);

	stopwatch.reset();
	stopwatch_wait();
	ASSERT_NE(stopwatch.get_elapsed_time().count(), 0);
}