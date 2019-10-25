#pragma once

#include "Engine/core.hpp"
#include "Engine/Graphics/Context/GraphicAPI.hpp"

namespace nova
{
	struct NOVA_API ApplicationSettings
	{
		GraphicAPI graphic_api = GraphicAPI::OpenGL;
	};
}