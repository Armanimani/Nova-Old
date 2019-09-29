#pragma once

#include <memory>

#include "Engine/core.hpp"

namespace nova
{
	class NOVA_API Application
	{
	public:
		void run();
	};

	std::unique_ptr<Application> create_application();
}