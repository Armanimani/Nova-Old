#pragma once

#include "Engine/core.hpp"

#include <d3d12.h>
#include <wrl.h>
#include <dxgi1_6.h>

namespace nova::graphics
{
	class NOVA_API DX12SwapChainFactory
	{
	public:
		static Microsoft::WRL::ComPtr<IDXGISwapChain4> create(Microsoft::WRL::ComPtr<ID3D12CommandQueue>& command_queue,
			HWND window_handle) noexcept;
		static Microsoft::WRL::ComPtr<IDXGISwapChain4> create(Microsoft::WRL::ComPtr<ID3D12CommandQueue>& command_queue,
			HWND window_handle, UINT resolution_x, UINT resolution_y) noexcept;
	private:
		static DXGI_SWAP_CHAIN_DESC1 get_descriptor(UINT resolution_x, UINT resolution_y) noexcept;
	};
}