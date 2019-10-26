#pragma once

#include "Engine/core.hpp"
#include "Engine/Graphics/GraphicAPI.hpp"
#include "Engine/Graphics/Context/GraphicContextInterface.hpp"

#include <memory>

namespace nova::graphics
{
	class NOVA_API GraphicContext
	{
	public:
		GraphicContext() = delete;
		~GraphicContext() = delete;
		GraphicContext(const GraphicContext& other) = delete;
		GraphicContext(GraphicContext&& other) noexcept = delete;
		GraphicContext& operator=(const GraphicContext& other) = delete;
		GraphicContext& operator=(GraphicContext&& other) noexcept = delete;

		static void set_window_handle(void* window_handle);
		
		static void set_graphic_api(GraphicAPI graphic_api);		
		static GraphicContextInterface* get();
	private:
		static std::unique_ptr<GraphicContextInterface> m_s_context;
		static void* m_window_handle;
	};

}
