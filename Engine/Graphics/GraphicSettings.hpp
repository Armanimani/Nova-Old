#pragma once

#include "Engine/core.hpp"
#include "Engine/Graphics/GraphicAPI.hpp"

namespace nova
{
	struct NOVA_API GraphicSettings
	{
		void* window_handle{};
		graphics::GraphicAPI api{ graphics::GraphicAPI::OpenGL };
		Int32 buffer_count{ 3 };
	};
}