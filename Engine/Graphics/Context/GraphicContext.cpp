#include "GraphicContext.hpp"

#include "Engine/Graphics/Platform/OpenGL/OpenGLGraphicContext.hpp"
#include "Engine/Graphics/Platform/DirectX12/DX12GraphicContext.hpp"

namespace nova::graphics
{
	std::unique_ptr<GraphicContextInterface> GraphicContext::m_s_context;
	void* GraphicContext::m_window_handle;
	
	void GraphicContext::set_window_handle(void* window_handle)
	{
		m_window_handle = window_handle;
	}

	void GraphicContext::set_graphic_api(GraphicAPI graphic_api)
	{
		if (m_s_context)
		{
			LOG_ENGINE_ERROR("Hot swapping graphic api is not implemented yet");
		}

		switch (graphic_api)
		{
		case GraphicAPI::OpenGL:
			m_s_context = std::make_unique<OpenGLGraphicContext>(m_window_handle);
			break;
		case GraphicAPI::DirectX12:
			m_s_context = std::make_unique<DX12GraphicContext>(m_window_handle);
		};
	}

	GraphicContextInterface* GraphicContext::get()
	{
		if (!m_s_context)
		{
			LOG_ENGINE_ERROR("The graphic context is not initialized!");
		}

		return m_s_context.get();
	}
}
