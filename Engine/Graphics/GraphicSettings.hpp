#pragma once

#include "Engine/core.hpp"
#include "Engine/Graphics/GraphicAPI.hpp"

namespace nova
{
	struct NOVA_API GraphicSettings
	{
		graphics::GraphicAPI api{ graphics::GraphicAPI::OpenGL };
	};
}