#pragma once

#include <thread>
#include <memory>

#include "Application/EngineApplication.hpp"
#include "Engine/core.hpp"

class EngineController
{
public:
	EngineController(nova::ApplicationSettings settings, void* window_handle);
	~EngineController();

	[[nodiscard]] EngineApplication* get_engine() noexcept;
private:
	std::unique_ptr<EngineApplication> m_engine{};
	
	std::unique_ptr<std::thread> m_thread{};
};