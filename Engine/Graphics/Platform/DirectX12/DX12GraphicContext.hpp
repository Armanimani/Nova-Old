#pragma once

#include <Windows.h>

#include "Engine/core.hpp"
#include "Engine/Graphics/Context/GraphicContextInterface.hpp"

namespace nova::graphics
{
	class NOVA_API DX12GraphicContext : public GraphicContextInterface
	{
	public:
		DX12GraphicContext(void* window_handle);

		void initialize() final;
		void present() final;
		[[nodiscard]] GraphicAPI get_graphic_api() const noexcept final;
	private:
		HWND m_window_handle{};
	};
}
