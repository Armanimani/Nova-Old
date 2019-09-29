#include <thread>

#include "Engine/Clock/CalenderClock.hpp"
#include "gtest/gtest.h"

TEST(CalenderClock, test_value)
{
	// catch the initial time structure returned by the clock
	const auto initial_state = nova::CalenderClock::get_calender_information();

	// force a sleep for few seconds
	std::this_thread::sleep_for(std::chrono::milliseconds{ 750 });

	// get the new value
	const auto final_state = nova::CalenderClock::get_calender_information();
	
	// the value for second is now defiantly different with respect to initial value
	EXPECT_NE(initial_state.second, final_state.second);
}
