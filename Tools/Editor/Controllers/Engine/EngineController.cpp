#include "EngineController.hpp"
#include "Engine/Application/ApplicationState.hpp"

EngineController::EngineController(const nova::ApplicationSettings settings, void* window_handle)
{
	m_engine = std::make_unique<EngineApplication>(settings, window_handle);
	m_thread = std::make_unique<std::thread>([this]()
		{
			this->m_engine->start();
		}
	);
}

EngineController::~EngineController()
{
	if (m_engine->get_application_state().run_state != nova::ApplicationState::RunState::stopped)
		m_engine->stop();
	
	m_thread->join();
}

EngineApplication* EngineController::get_engine() noexcept
{
	return m_engine.get();
}
