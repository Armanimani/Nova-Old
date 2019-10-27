#include "DXD12DebugController.hpp"

namespace nova::graphics
{
	Microsoft::WRL::ComPtr<ID3D12Debug3> DXD12DebugController::m_s_debug;
	Microsoft::WRL::ComPtr<ID3D12InfoQueue> DXD12DebugController::m_s_info_queue;
	
	void DXD12DebugController::enable_debug_interface() noexcept
	{
#ifndef DEPLYMENT
		if (!m_s_debug)
		{
			if (!SUCCEEDED(D3D12GetDebugInterface(IID_PPV_ARGS(&m_s_debug))))
			{
				LOG_ENGINE_ERROR("Unable to enable_debug_interface the debugging layer of DirectX12");
			}
			m_s_debug->EnableDebugLayer();
		}
#endif
	}

	void DXD12DebugController::enable_debug_info_queue(const Microsoft::WRL::ComPtr<ID3D12Device>& device) noexcept
	{
#ifndef DEPLYMENT
		if (!m_s_info_queue)
		{
			if (!SUCCEEDED(device.As(&m_s_info_queue)))
			{
				LOG_ENGINE_ERROR("Unable to querry the info queue for DirectX12");
			}

			m_s_info_queue->SetBreakOnSeverity(D3D12_MESSAGE_SEVERITY_CORRUPTION, TRUE);
			m_s_info_queue->SetBreakOnSeverity(D3D12_MESSAGE_SEVERITY_ERROR, TRUE);
			m_s_info_queue->SetBreakOnSeverity(D3D12_MESSAGE_SEVERITY_WARNING, TRUE);
		}
#endif
	}
}
