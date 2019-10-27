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
		update_adapter_information();
	}

	void GraphicSystem::present() noexcept
	{
		GraphicContext::get()->present();
	}

	void GraphicSystem::update_adapter_information() noexcept
	{
		std::lock_guard<std::mutex> loc(SystemInformation::graphic_cards_mutex);
		SystemInformation::graphic_cards = GraphicContext::get()->get_adapter_information();
	}
}
