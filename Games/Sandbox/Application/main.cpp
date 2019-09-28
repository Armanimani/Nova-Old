#include "Engine/entry_point.hpp"
#include "Application/Sandbox.hpp"


inline std::unique_ptr<nova::Application> create_application()
{
	return std::make_unique<Sandbox>();
}