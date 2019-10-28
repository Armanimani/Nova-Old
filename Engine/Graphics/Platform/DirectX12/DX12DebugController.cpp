#include "DX12DebugController.hpp"

namespace nova::graphics
{
	void DX12DebugController::enable_debug_interface() noexcept
	{
#ifndef DEPLYMENT
		Microsoft::WRL::ComPtr<ID3D12Debug3> debug{};
		
		if (!debug)
		{
			if (FAILED(D3D12GetDebugInterface(IID_PPV_ARGS(&debug))))
			{
				LOG_ENGINE_ERROR("Unable to enable_debug_interface the debugging layer of DirectX12");
			}
			debug->EnableDebugLayer();
		}
#endif
	}

	void DX12DebugController::enable_debug_info_queue(const Microsoft::WRL::ComPtr<ID3D12Device>& device) noexcept
	{
#ifndef DEPLYMENT
		Microsoft::WRL::ComPtr<ID3D12InfoQueue> info_queue{};
		
		if (!info_queue)
		{
			if (FAILED(device.As(&info_queue)))
			{
				LOG_ENGINE_ERROR("Unable to querry the info queue for DirectX12");
			}

			info_queue->SetBreakOnSeverity(D3D12_MESSAGE_SEVERITY_CORRUPTION, TRUE);
			info_queue->SetBreakOnSeverity(D3D12_MESSAGE_SEVERITY_ERROR, TRUE);
			info_queue->SetBreakOnSeverity(D3D12_MESSAGE_SEVERITY_WARNING, TRUE);
		}
#endif
	}
}
