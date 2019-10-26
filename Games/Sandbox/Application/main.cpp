#include "Engine/entry_point.hpp"
#include "Engine/Application/ApplicationSettings.hpp"
#include "Application/Sandbox.hpp"


inline std::unique_ptr<nova::Application> create_application()
{
	nova::ApplicationSettings settings;
	
	return std::make_unique<Sandbox>(settings);
}