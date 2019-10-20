#pragma once

#include <memory>

#include "Engine/core.hpp"

namespace nova
{
	class NOVA_API Application
	{
	public:
		Application();
		explicit Application(Int64 window_handle);
		void run();
	private:
		Int64 m_window_handle = 0;
	};

	std::unique_ptr<Application> create_application();
}