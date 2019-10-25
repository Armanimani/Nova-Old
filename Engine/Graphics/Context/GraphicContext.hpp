#pragma once

#include "Engine/core.hpp"
#include "GraphicAPI.hpp"

#include <memory>

namespace nova
{
	class NOVA_API GraphicContext
	{
	public:
		GraphicContext(Int64 window_handle);
		virtual ~GraphicContext() = default;
		
		virtual void present() = 0;
		virtual void initialize() = 0;

		[[nodiscard]] virtual GraphicAPI get_graphic_api() = 0;
		[[nodiscard]] Int64 get_window_handle() const noexcept;	
	private:
		Int64 m_window_handle{};
	};
}