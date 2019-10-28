#include "ContextManager.hpp"

#include "Engine/Graphics/Context/GraphicContext.hpp"
#include "Engine/Graphics/Context/GraphicContextManager.hpp"

namespace nova
{
	std::unique_ptr<Context> ContextManager::create(const ApplicationSettings& settings) noexcept
	{
		auto context = std::make_unique<Context>();
		context->graphic_context = graphics::GraphicContextManager::create(settings.graphics);
		return context;
	}
}
