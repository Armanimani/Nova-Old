#include "GraphicSystem.hpp"

#include "Engine/Graphics/Context/GraphicContext.hpp"

namespace nova::graphics
{
	GraphicSystem::GraphicSystem(const GraphicSettings settings, void* window_handle)
		: m_settings{ settings }, m_window_handle {window_handle}
	{
		GraphicContext::set_window_handle(m_window_handle);
		GraphicContext::set_graphic_api(m_settings.api);
	}

	void GraphicSystem::initialize() noexcept
	{
		GraphicContext::get()->initialize();
	}

	void GraphicSystem::present() noexcept
	{
		GraphicContext::get()->present();
	}
}
