#include "DX12SwapChainFactory.hpp"
#include "DX12DXGIFactoryFactory.hpp"
#include "DX12FeatureChecker.hpp"

namespace nova::graphics
{
	Microsoft::WRL::ComPtr<IDXGISwapChain4> DX12SwapChainFactory::create(
		Microsoft::WRL::ComPtr<ID3D12CommandQueue>& command_queue, const HWND window_handle, UINT buffer_count) noexcept
	{
		return create(command_queue, window_handle, 0, 0, buffer_count);
	}

	Microsoft::WRL::ComPtr<IDXGISwapChain4> DX12SwapChainFactory::create(
		Microsoft::WRL::ComPtr<ID3D12CommandQueue>& command_queue, const HWND window_handle, const UINT resolution_x, const UINT resolution_y, const UINT buffer_count) noexcept
	{
		Microsoft::WRL::ComPtr<IDXGISwapChain1> swap_chain1;
		auto factory = DX12DXGIFactoryFactory::create();
		const auto descriptor = get_descriptor(resolution_x, resolution_y, buffer_count);
		if (!SUCCEEDED(factory->CreateSwapChainForHwnd(command_queue.Get(), window_handle, &descriptor, nullptr, nullptr, &swap_chain1)))
		{
			LOG_ENGINE_ERROR("Unable to create swap chain for DirectX12");
		}

		// Disable the alt-enter for exclusive full-screen
		if (!SUCCEEDED(factory->MakeWindowAssociation(window_handle, DXGI_MWA_NO_ALT_ENTER)))
		{
			LOG_ENGINE_ERROR("Unable to disable the alt-enger combination for exclusive full-screen");
		}

		// Convert the swap chain to type 4
		Microsoft::WRL::ComPtr<IDXGISwapChain4> swap_chain4;
		if (!SUCCEEDED(swap_chain1.As(&swap_chain4)))
		{
			LOG_ENGINE_ERROR("Unable to convert swapchain of type 1 to type 4");
		}

		return swap_chain4;
	}

	DXGI_SWAP_CHAIN_DESC1 DX12SwapChainFactory::get_descriptor(const UINT resolution_x, const UINT resolution_y, const UINT buffer_count) noexcept
	{		
		DXGI_SWAP_CHAIN_DESC1 descriptor;
		descriptor.Width = resolution_x;
		descriptor.Height = resolution_y;
		descriptor.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
		descriptor.Stereo = FALSE;
		descriptor.SampleDesc = { 1, 0 };
		descriptor.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
		descriptor.BufferCount = buffer_count;
		descriptor.Scaling = DXGI_SCALING_STRETCH;
		descriptor.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD;
		descriptor.AlphaMode = DXGI_ALPHA_MODE_UNSPECIFIED;
		descriptor.Flags = DX12FeatureChecker::is_tearing_supported() ? DXGI_SWAP_CHAIN_FLAG_ALLOW_TEARING : 0;

		return descriptor;
	}
}
