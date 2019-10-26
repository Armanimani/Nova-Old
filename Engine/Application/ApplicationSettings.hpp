#pragma once

#include "Engine/core.hpp"
#include "Engine/Graphics/GraphicSettings.hpp"

namespace nova
{
	struct NOVA_API ApplicationSettings
	{
		GraphicSettings graphics{};
	};
}