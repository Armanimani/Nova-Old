#include "GraphicContextManager.hpp"

#include "Engine/Graphics/Platform/DirectX12/DX12GraphicContext.hpp"
#include "Engine/Graphics/Platform/OpenGL/OpenGLGraphicContext.hpp"

namespace nova::graphics
{
	std::unique_ptr<GraphicContext> GraphicContextManager::create(const GraphicSettings& settings)
	{
		switch (settings.api)
		{
		case GraphicAPI::OpenGL:
			return std::make_unique<OpenGLGraphicContext>(settings);
		case GraphicAPI::DirectX12:
			return std::make_unique<DX12GraphicContext>(settings);
		}
		LOG_ENGINE_ERROR("Unable to create the contex, invalid rendering API supplied");
		return nullptr;
	}

}