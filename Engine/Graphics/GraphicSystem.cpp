#include "GraphicSystem.hpp"

#include "Engine/Graphics/Context/GraphicContext.hpp"

namespace nova::graphics
{
	GraphicSystem::GraphicSystem(GraphicContext* context)
		: m_context{context}
	{
	}

	void GraphicSystem::initialize() const noexcept
	{
		m_context->initialize();
		update_adapter_information();
	}

	void GraphicSystem::present() const noexcept
	{
		m_context->present();
	}

	void GraphicSystem::update_adapter_information() const noexcept
	{
		std::lock_guard<std::mutex> loc(SystemInformation::graphic_cards_mutex);

		SystemInformation::graphic_cards = m_context->get_adapter_information();
	}
}
