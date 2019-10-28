#pragma once

#include <windows.h>

#include "Engine/core.hpp"
#include "Engine/Graphics/Context/GraphicContext.hpp"

namespace nova::graphics
{
	class NOVA_API OpenGLGraphicContext: public GraphicContext
	{
	public:
		OpenGLGraphicContext(const GraphicSettings& settings);
		~OpenGLGraphicContext();

		OpenGLGraphicContext(const OpenGLGraphicContext& other) = delete;
		OpenGLGraphicContext(OpenGLGraphicContext&& other) noexcept = delete;
		OpenGLGraphicContext& operator=(const OpenGLGraphicContext& other) = delete;
		OpenGLGraphicContext& operator=(OpenGLGraphicContext&& other) noexcept = delete;
		
		void initialize() final;
		void present() final;
		[[nodiscard]] GraphicAPI get_graphic_api() const noexcept final;
		[[nodiscard]] std::vector<GraphicCardInformation> get_adapter_information() final;
	private:
		HWND m_window_handle{};
		HDC m_device_context_handle{};
		HGLRC m_rendering_context_handle{};
	};
}