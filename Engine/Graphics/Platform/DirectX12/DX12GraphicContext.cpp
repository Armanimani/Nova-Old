#include "DX12GraphicContext.hpp"

#include "Engine/Graphics/Platform/DirectX12/DX12DeviceFactory.hpp"
#include "Engine/Graphics/Platform/DirectX12/DX12DXGIFactoryFactory.hpp"
#include "Engine/Graphics/Platform/DirectX12/DX12DebugController.hpp"
#include "Engine/Graphics/Platform/DirectX12/DX12CommandQueueFactory.hpp"
#include "Engine/Graphics/Platform/DirectX12/DX12SwapChainFactory.hpp"
#include "Engine/Graphics/Platform/DirectX12/DX12DescriptorHeapFactory.hpp"
#include "Engine/SystemInformation/SystemInformation.hpp"

#include <Windows.h>

namespace nova::graphics
{
	DX12GraphicContext::DX12GraphicContext(const GraphicSettings& settings): GraphicContext(settings)
	{
		m_window_handle = reinterpret_cast<HWND>(settings.window_handle);
		m_buffer_count = settings.buffer_count;
	}

	void DX12GraphicContext::initialize()
	{
		DX12DebugController::enable_debug_interface();
		
		m_device = DX12DeviceFactory::create();
		DX12DebugController::enable_debug_info_queue(m_device);
		
		m_graphic_command_queue = DX12CommandQueueFactory::create(m_device, D3D12_COMMAND_LIST_TYPE_DIRECT);
		m_compute_command_queue = DX12CommandQueueFactory::create(m_device, D3D12_COMMAND_LIST_TYPE_COMPUTE);
		m_copy_command_queue = DX12CommandQueueFactory::create(m_device, D3D12_COMMAND_LIST_TYPE_COPY);
		
		m_swap_chain = DX12SwapChainFactory::create(m_graphic_command_queue, m_window_handle, m_buffer_count);
		
		m_RTV_descriptor_heap = DX12DescriptorHeapFactory::create(m_device, D3D12_DESCRIPTOR_HEAP_TYPE_RTV, m_buffer_count);
		update_render_target_views();
	}

	void DX12GraphicContext::update_render_target_views()
	{
		const auto descriptor_size = m_device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_RTV);

		CD3DX12_CPU_DESCRIPTOR_HANDLE handle(m_RTV_descriptor_heap->GetCPUDescriptorHandleForHeapStart());

		for (auto i = 0;  i != m_buffer_count; ++i)
		{
			Microsoft::WRL::ComPtr<ID3D12Resource1> back_buffer;

			if (FAILED(m_swap_chain->GetBuffer(i, IID_PPV_ARGS(&back_buffer))))
			{
				LOG_ENGINE_ERROR("Unable to create back buffers for DirectX12");
			}

			m_device->CreateRenderTargetView(back_buffer.Get(), nullptr, handle);
			m_back_buffer_list.push_back(back_buffer);
			handle.Offset(descriptor_size);
		}
	}
	
	void DX12GraphicContext::present()
	{
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

	GraphicAPI DX12GraphicContext::get_graphic_api() const noexcept
	{
		return GraphicAPI::DirectX12;
	}
}
