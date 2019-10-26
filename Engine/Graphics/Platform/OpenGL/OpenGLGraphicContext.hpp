#pragma once

#include <windows.h>

#include "Engine/core.hpp"
#include "Engine/Graphics/Context/GraphicContextInterface.hpp"

namespace nova::graphics
{
	class NOVA_API OpenGLGraphicContext: public GraphicContextInterface
	{
	public:
		OpenGLGraphicContext(void* window_handle);
		
		void initialize() final;
		void present() final;
		[[nodiscard]] GraphicAPI get_graphic_api() const noexcept final;
	private:
		HWND m_window_handle{};
		HDC m_device_context_handle{};
	};
}