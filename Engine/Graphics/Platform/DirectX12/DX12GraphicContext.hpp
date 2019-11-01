#pragma once

#include "Engine/core.hpp"
#include "Engine/Graphics/Context/GraphicContext.hpp"

#include <Windows.h>
#include <wrl.h>
#include <d3d12.h>
#include <dxgi1_6.h>
#include <D3DX12/d3dx12.h>
#include <vector>
#include <chrono>


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
		void cleanup() final;
		[[nodiscard]] GraphicAPI get_graphic_api() const noexcept final;
		[[nodiscard]] std::vector<GraphicCardInformation> get_adapter_information() final;
	private:
		// configuration settings
		HWND m_window_handle{};
		INT m_buffer_count{};
		bool m_enable_v_sync{};

		// internal values
		INT m_frame_index{};
		INT m_rtv_descriptor_size{};
		HANDLE m_fence_event{};
		
		bool m_tearing_supported{};

		Microsoft::WRL::ComPtr<ID3D12Device6> m_device{};
		Microsoft::WRL::ComPtr<IDXGISwapChain4> m_swap_chain{};
		Microsoft::WRL::ComPtr<ID3D12GraphicsCommandList5> m_graphic_command_list{};
		Microsoft::WRL::ComPtr<ID3D12CommandQueue> m_graphic_command_queue{};
		Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> m_rtv_descriptor_heap{};
		
		std::vector<Microsoft::WRL::ComPtr<ID3D12Resource1>> m_back_buffer_list{};
		std::vector<Microsoft::WRL::ComPtr<ID3D12CommandAllocator>> m_command_allocator_list{};
		
		std::vector<Microsoft::WRL::ComPtr<ID3D12Fence1>> m_fence_list{};
		std::vector<UINT64> m_fence_value_list{};
		
		void create_render_target_views();
		void create_command_allocators();
		void create_fences();

		void wait_for_previous_frame();
		void update_pipeline();
	};
}
