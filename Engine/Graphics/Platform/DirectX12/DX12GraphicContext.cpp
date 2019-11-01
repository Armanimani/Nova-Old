#include "DX12GraphicContext.hpp"

#include "Engine/SystemInformation/SystemInformation.hpp"

#include "Engine/Graphics/Platform/DirectX12/DX12DeviceFactory.hpp"
#include "Engine/Graphics/Platform/DirectX12/DX12DXGIFactoryFactory.hpp"
#include "Engine/Graphics/Platform/DirectX12/DX12DebugController.hpp"
#include "Engine/Graphics/Platform/DirectX12/DX12CommandQueueFactory.hpp"
#include "Engine/Graphics/Platform/DirectX12/DX12CommandAllocatorFactory.hpp"
#include "Engine/Graphics/Platform/DirectX12/DX12CommandListFactory.hpp"
#include "Engine/Graphics/Platform/DirectX12/DX12SwapChainFactory.hpp"
#include "Engine/Graphics/Platform/DirectX12/DX12DescriptorHeapFactory.hpp"
#include "Engine/Graphics/Platform/DirectX12/DX12FenceFactory.hpp"
#include "Engine/Graphics/Platform/DirectX12/DX12FenceEventFactory.hpp"
#include "Engine/Graphics/Platform/DirectX12/DX12FeatureChecker.hpp"

#include <Windows.h>

namespace nova::graphics
{
	DX12GraphicContext::DX12GraphicContext(const GraphicSettings& settings): GraphicContext(settings)
	{
		m_window_handle = reinterpret_cast<HWND>(settings.window_handle);
		m_buffer_count = settings.buffer_count;
		m_enable_v_sync = settings.enable_v_sync;
	}

	void DX12GraphicContext::initialize()
	{
		DX12DebugController::enable_debug_interface();
			
		m_device = DX12DeviceFactory::create();
		DX12DebugController::enable_debug_info_queue(m_device);
		m_tearing_supported = DX12FeatureChecker::is_tearing_supported();
		
		m_graphic_command_queue = DX12CommandQueueFactory::create(m_device, D3D12_COMMAND_LIST_TYPE_DIRECT);	
		m_swap_chain = DX12SwapChainFactory::create(m_graphic_command_queue, m_window_handle, m_buffer_count);
		m_rtv_descriptor_heap = DX12DescriptorHeapFactory::create(m_device, D3D12_DESCRIPTOR_HEAP_TYPE_RTV, m_buffer_count);

		create_render_target_views();
		create_command_allocators();

		m_graphic_command_list = DX12CommandListFactory::create(m_device, m_command_allocator_list[0], D3D12_COMMAND_LIST_TYPE_DIRECT);
		create_fences();
	}

	void DX12GraphicContext::create_render_target_views()
	{
		m_rtv_descriptor_size = m_device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_RTV);

		CD3DX12_CPU_DESCRIPTOR_HANDLE handle(m_rtv_descriptor_heap->GetCPUDescriptorHandleForHeapStart());
		for (auto i = 0;  i != m_buffer_count; ++i)
		{
			m_back_buffer_list.emplace_back(nullptr);
			const auto result = m_swap_chain->GetBuffer(i, IID_PPV_ARGS(&m_back_buffer_list[i]));

			if (FAILED(result))
			{
				LOG_ENGINE_ERROR("Unable to get the back buffer from swap chain for DirectX12");
			}

			m_device->CreateRenderTargetView(m_back_buffer_list[i].Get(), nullptr, handle);
			handle.Offset(m_rtv_descriptor_size);
		}
	}

	void DX12GraphicContext::create_command_allocators()
	{
		for (auto i = 0; i != m_buffer_count; ++i)
		{
			m_command_allocator_list.push_back(DX12CommandAllocatorFactory::create(m_device, D3D12_COMMAND_LIST_TYPE_DIRECT));
		}
	}

	void DX12GraphicContext::create_fences()
	{
		for (auto i = 0; i != m_buffer_count; ++i)
		{
			const auto fence = DX12FenceFactory::create(m_device, D3D12_FENCE_FLAG_NONE);
			m_fence_list.push_back(fence);
			m_fence_value_list.push_back(0);
		}
	}

	void DX12GraphicContext::wait_for_previous_frame()
	{
		m_frame_index = m_swap_chain->GetCurrentBackBufferIndex();

		if (m_fence_list[m_frame_index]->GetCompletedValue() < m_fence_value_list[m_frame_index])
		{
			if (FAILED(m_fence_list[m_frame_index]->SetEventOnCompletion(m_fence_value_list[m_frame_index], m_fence_event)))
			{
				LOG_ENGINE_ERROR("Unable to set the event for fence");
			}
			WaitForSingleObject(m_fence_event, INFINITE);
		}

		m_fence_value_list[m_frame_index]++;
	}

	void DX12GraphicContext::update_pipeline()
	{
		wait_for_previous_frame();

		if (FAILED(m_command_allocator_list[m_frame_index]->Reset()))
		{
			LOG_ENGINE_ERROR("Unable to reset the command allocator");
		}

		if (FAILED(m_graphic_command_list->Reset(m_command_allocator_list[m_frame_index].Get(), NULL)))
		{
			LOG_ENGINE_ERROR("Unable to reset the command allocator");
		}

		const auto rtv_barrier = CD3DX12_RESOURCE_BARRIER::Transition(m_back_buffer_list[m_frame_index].Get(), D3D12_RESOURCE_STATE_PRESENT, D3D12_RESOURCE_STATE_RENDER_TARGET);
		m_graphic_command_list->ResourceBarrier(1, &rtv_barrier);

		CD3DX12_CPU_DESCRIPTOR_HANDLE handle(m_rtv_descriptor_heap->GetCPUDescriptorHandleForHeapStart(), m_frame_index, m_rtv_descriptor_size);
		m_graphic_command_list->OMSetRenderTargets(1, &handle, FALSE, nullptr);

		const float color[] = { 0.0f, 0.2f, 0.4f, 1.0f };
		m_graphic_command_list->ClearRenderTargetView(handle, color, 0, nullptr);

		const auto state_present_barrier = CD3DX12_RESOURCE_BARRIER::Transition(m_back_buffer_list[m_frame_index].Get(), D3D12_RESOURCE_STATE_RENDER_TARGET, D3D12_RESOURCE_STATE_PRESENT);
		m_graphic_command_list->ResourceBarrier(1, &state_present_barrier);

		if (FAILED(m_graphic_command_list->Close()))
		{
			LOG_ENGINE_ERROR("Unable to close the graphic command list");
		}
		
	}

	void DX12GraphicContext::present()
	{
		update_pipeline();

		ID3D12CommandList* const command_list[] =
		{
			m_graphic_command_list.Get()
		};
		
		m_graphic_command_queue->ExecuteCommandLists(1, command_list);

		if (FAILED(m_graphic_command_queue->Signal(m_fence_list[m_frame_index].Get(), m_fence_value_list[m_frame_index])))
		{
			LOG_ENGINE_ERROR("Unable to signal the fence value");
		}

		if (FAILED(m_swap_chain->Present(0, 0)))
		{
			LOG_ENGINE_ERROR("Unable to present");
		}
	}

	void DX12GraphicContext::cleanup()
	{
		for (auto i = 0; i != m_buffer_count; ++i)
		{
			m_frame_index = i;
			wait_for_previous_frame();
		}

		BOOL full_screen_state = FALSE;
		if (m_swap_chain->GetFullscreenState(&full_screen_state, nullptr))
		{
			m_swap_chain->SetFullscreenState(FALSE, nullptr);
		}
	}

	GraphicAPI DX12GraphicContext::get_graphic_api() const noexcept
	{
		return GraphicAPI::DirectX12;
	}

	std::vector<GraphicCardInformation> DX12GraphicContext::get_adapter_information()
	{
		std::vector<GraphicCardInformation> result{};
		
		auto factory = DX12DXGIFactoryFactory::create();
		Microsoft::WRL::ComPtr<IDXGIAdapter1> adapter{};
		for (UINT i = 0; factory->EnumAdapters1(i, &adapter) != DXGI_ERROR_NOT_FOUND; ++i)
		{
			DXGI_ADAPTER_DESC1 descriptor;
			adapter->GetDesc1(&descriptor);

			if ((descriptor.Flags & DXGI_ADAPTER_FLAG_SOFTWARE) == 0)
			{
				GraphicCardInformation information;
				information.dedicated_video_memory = descriptor.DedicatedVideoMemory;
				information.dedicated_system_memory = descriptor.DedicatedSystemMemory;
				information.system_shared_memory = descriptor.SharedSystemMemory;

#pragma warning (push)
#pragma warning (disable: 4244)
				const auto description = std::wstring(std::wstring(descriptor.Description));
				information.description = std::string(description.cbegin(), description.cend());
#pragma warning (pop)
				result.push_back(information);
			}
		}
		return result;
	}
}
