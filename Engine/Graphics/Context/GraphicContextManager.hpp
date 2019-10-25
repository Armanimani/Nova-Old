#pragma once

#include "GraphicContext.hpp"

#include <memory>

namespace nova
{
	class NOVA_API GraphicContextManager
	{
	public:
		static void Create(Int64 window_handle, GraphicAPI graphic_api) noexcept;
		static void initialize() noexcept;
		static void present() noexcept;
		[[nodiscard]] static GraphicAPI get_graphic_api() noexcept;
	private:
		static std::unique_ptr<GraphicContext> m_s_context;
	};
}
