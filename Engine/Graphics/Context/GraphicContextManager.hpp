#pragma once

#include "Engine/core.hpp"
#include "Engine/Graphics/Context/GraphicContext.hpp"
#include "Engine/Graphics/GraphicSettings.hpp"

#include <memory>

namespace nova::graphics
{
	class NOVA_API GraphicContextManager
	{
	public:
		static std::unique_ptr<GraphicContext> create(const GraphicSettings& settings);
	};
}
