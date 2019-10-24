#include "EngineController.hpp"

EngineController::EngineController(const int window_handle)
{
	m_engine = std::make_unique<EngineApplication>(window_handle);
	m_thread = std::make_unique<std::thread>([this]()
		{
			this->m_engine->start();
		}
	);
}

EngineController::~EngineController()
{
	m_engine->stop();
	m_thread->join();
}

EngineApplication* EngineController::get_engine() noexcept
{
	return m_engine.get();
}
