#include "DX12GraphicContext.hpp"

#include <Windows.h>

namespace nova::graphics
{
	DX12GraphicContext::DX12GraphicContext(void* window_handle)
	{
		m_window_handle = reinterpret_cast<HWND>(window_handle);
	}

	void DX12GraphicContext::initialize()
	{
		
	}

	void DX12GraphicContext::present()
	{
	}

	GraphicAPI DX12GraphicContext::get_graphic_api() const noexcept
	{
		return GraphicAPI::DirectX12;
	}
}
