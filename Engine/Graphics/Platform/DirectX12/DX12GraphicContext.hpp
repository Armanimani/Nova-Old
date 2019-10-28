#pragma once

#include "Engine/core.hpp"
#include "Engine/Graphics/Context/GraphicContext.hpp"

#include <Windows.h>
#include <wrl.h>
#include <d3d12.h>
#include <dxgi1_6.h>
#include <D3DX12/d3dx12.h>


namespace nova::graphics
{
	class NOVA_API DX12GraphicContext : public GraphicContext
	{
	public:
		explicit DX12GraphicContext(const GraphicSettings& settings);
		~DX12GraphicContext() = default;
		DX12GraphicContext(const DX12GraphicContext& other) = delete;
		DX12GraphicContext(DX12GraphicContext&& other) noexcept = delete;
		DX12GraphicContext& operator=(const DX12GraphicContext& other) = delete;
		DX12GraphicContext& operator=(DX12GraphicContext&& other) noexcept = delete;
		
		void initialize() final;
		void present() final;
		[[nodiscard]] GraphicAPI get_graphic_api() const noexcept final;
		[[nodiscard]] std::vector<GraphicCardInformation> get_adapter_information() final;
	private:
		HWND m_window_handle{};
		INT m_buffer_count{};

		Microsoft::WRL::ComPtr<ID3D12Device6> m_device{};
		Microsoft::WRL::ComPtr<IDXGISwapChain4> m_swap_chain{};
		
		Microsoft::WRL::ComPtr<ID3D12CommandQueue> m_graphic_command_queue{};
		Microsoft::WRL::ComPtr<ID3D12CommandQueue> m_compute_command_queue{};
		Microsoft::WRL::ComPtr<ID3D12CommandQueue> m_copy_command_queue{};
		
		Microsoft::WRL::ComPtr<ID3D12Resource1> m_back_buffer{};
		Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> m_RTV_descriptor_heap{};
		
		UINT m_RTV_descriptor_size{};
	};
}
