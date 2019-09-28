#include "Engine/entry_point.hpp"
#include "Application/Application.hpp"


inline std::unique_ptr<nova::Application> create_application()
{
	return std::make_unique<SandboxApplication>();
}