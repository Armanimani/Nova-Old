#pragma once

#include "Engine/core.hpp"
#include "Engine/Graphics/Context/GraphicContext.hpp"

namespace nova
{
	class NOVA_API Context
	{
	public:
		std::unique_ptr<graphics::GraphicContext> graphic_context{};
	};
}
