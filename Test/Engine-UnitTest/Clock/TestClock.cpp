#include <thread>

#include "Engine/Clock/Clock.hpp"
#include "gtest/gtest.h"

void wait()
{
	std::this_thread::sleep_for(std::chrono::milliseconds{ 2 });
}


TEST(Clock, TestInitialization)
{
	const nova::Clock clock {};

	EXPECT_EQ(std::chrono::duration_cast<std::chrono::milliseconds>(clock.get_elapsed_time()).count(), 0.0);
	EXPECT_EQ(std::chrono::duration_cast<std::chrono::milliseconds>(clock.get_last_tick_time()).count(), 0.0);
	EXPECT_EQ(clock.get_number_of_ticks(), 0);
}

TEST(Clock, TestTick_withoutStart)
{
	nova::Clock clock {};

	wait();
	clock.tick();

	EXPECT_EQ(std::chrono::duration_cast<std::chrono::milliseconds>(clock.get_elapsed_time()).count(), 0.0);
	EXPECT_EQ(std::chrono::duration_cast<std::chrono::milliseconds>(clock.get_last_tick_time()).count(), 0.0);
	EXPECT_EQ(clock.get_number_of_ticks(), 0);
}

TEST(Clock, TestTick_withStart)
{
	nova::Clock clock{};

	clock.start();
	wait();
	clock.tick();

	EXPECT_NE(std::chrono::duration_cast<std::chrono::milliseconds>(clock.get_elapsed_time()).count(), 0.0);
	EXPECT_NE(std::chrono::duration_cast<std::chrono::milliseconds>(clock.get_last_tick_time()).count(), 0.0);
	EXPECT_NE(clock.get_number_of_ticks(), 0);
	EXPECT_EQ(clock.get_number_of_ticks(), 1);
}

TEST(Clock, TestTick_multipleStart)
{
	nova::Clock clock{};

	clock.start();
	wait();
	clock.tick();

	const auto initial_elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(clock.get_elapsed_time());
	const auto initial_tick_time = std::chrono::duration_cast<std::chrono::microseconds>(clock.get_last_tick_time());
	const auto initial_tick_count = clock.get_number_of_ticks();
	
	clock.start();
	
	const auto final_elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(clock.get_elapsed_time());
	const auto final_tick_time = std::chrono::duration_cast<std::chrono::microseconds>(clock.get_last_tick_time());
	const auto final_tick_count = clock.get_number_of_ticks();

	EXPECT_EQ(initial_elapsed_time.count(), final_elapsed_time.count());
	EXPECT_EQ(initial_tick_time.count(), final_tick_time.count());
	EXPECT_EQ(initial_tick_count, final_tick_count);
}

TEST(Clock, TestStop_withoutStart)
{
	nova::Clock clock{};

	wait();
	clock.stop();

	EXPECT_EQ(std::chrono::duration_cast<std::chrono::milliseconds>(clock.get_elapsed_time()).count(), 0.0);
	EXPECT_EQ(std::chrono::duration_cast<std::chrono::milliseconds>(clock.get_last_tick_time()).count(), 0.0);
	EXPECT_EQ(clock.get_number_of_ticks(), 0);
}

TEST(Clock, TestStop_withoutStart_withTick)
{
	nova::Clock clock{};

	wait();
	clock.tick();
	wait();
	clock.stop();

	EXPECT_EQ(std::chrono::duration_cast<std::chrono::milliseconds>(clock.get_elapsed_time()).count(), 0.0);
	EXPECT_EQ(std::chrono::duration_cast<std::chrono::milliseconds>(clock.get_last_tick_time()).count(), 0.0);
	EXPECT_EQ(clock.get_number_of_ticks(), 0);
}

TEST(Clock, TestStop_withStart)
{
	nova::Clock clock{};

	clock.start();
	wait();
	clock.stop();

	EXPECT_NE(std::chrono::duration_cast<std::chrono::milliseconds>(clock.get_elapsed_time()).count(), 0.0);
	EXPECT_NE(std::chrono::duration_cast<std::chrono::milliseconds>(clock.get_last_tick_time()).count(), 0.0);
	EXPECT_EQ(clock.get_number_of_ticks(), 1);
}

TEST(Clock, TestStop_withStart_withTick)
{
	nova::Clock clock{};

	clock.start();
	wait();
	clock.tick();
	wait();
	clock.stop();

	EXPECT_NE(std::chrono::duration_cast<std::chrono::milliseconds>(clock.get_elapsed_time()).count(), 0.0);
	EXPECT_NE(std::chrono::duration_cast<std::chrono::milliseconds>(clock.get_last_tick_time()).count(), 0.0);
	EXPECT_EQ(clock.get_number_of_ticks(), 2);
}

TEST(Clock, TestStop_multipleStop)
{
	nova::Clock clock{};

	clock.start();
	wait();
	clock.tick();

	const auto initial_elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(clock.get_elapsed_time());
	const auto initial_tick_time = std::chrono::duration_cast<std::chrono::microseconds>(clock.get_last_tick_time());
	const auto initial_tick_count = clock.get_number_of_ticks();

	wait();
	wait();
	clock.stop();

	const auto final_elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(clock.get_elapsed_time());
	const auto final_tick_time = std::chrono::duration_cast<std::chrono::microseconds>(clock.get_last_tick_time());
	const auto final_tick_count = clock.get_number_of_ticks();

	EXPECT_NE(initial_elapsed_time.count(), final_elapsed_time.count());
	EXPECT_NE(initial_tick_time.count(), final_tick_time.count());
	EXPECT_EQ(initial_tick_count + 1, final_tick_count);
}