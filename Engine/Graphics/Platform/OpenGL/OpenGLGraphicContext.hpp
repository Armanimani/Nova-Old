#pragma once

#include "Engine/Graphics/Context/GraphicContext.hpp"

namespace nova
{
	class OpenGLGraphicContext: public GraphicContext
	{
	public:
		OpenGLGraphicContext(Int64 window_handle);
		
		void initialize() final;
		void present() final;
		[[nodiscard]] GraphicAPI get_graphic_api() final;
	private:
		Int64 m_handle_device_context{};
	};
}