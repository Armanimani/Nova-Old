#include "GraphicContextManager.hpp"

#include "Engine/Graphics/Platform/OpenGL/OpenGLGraphicContext.hpp"

namespace nova
{
	std::unique_ptr<GraphicContext> GraphicContextManager::m_s_context{};
	
	void GraphicContextManager::Create(const Int64 window_handle, const GraphicAPI graphic_api) noexcept
	{
		if (m_s_context)
		{
			LOG_ENGINE_WARNING("Graphic context is already created");
			return;
		}

		switch (graphic_api)
		{
		case GraphicAPI::OpenGL:
			m_s_context = std::make_unique<OpenGLGraphicContext>(window_handle);
			break;
		default:
			LOG_ENGINE_ERROR("Unable to create Graphic context, unknown API supplied");
		}
	}

	void GraphicContextManager::initialize() noexcept
	{
		m_s_context->initialize();
	}

	void GraphicContextManager::present() noexcept
	{
		m_s_context->present();
	}

	GraphicAPI GraphicContextManager::get_graphic_api() noexcept
	{
		return m_s_context->get_graphic_api();
	}
}
