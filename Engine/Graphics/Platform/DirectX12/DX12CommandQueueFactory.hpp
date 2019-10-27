#pragma once

#include "Engine/core.hpp"

#include <d3d12.h>
#include <wrl.h>

namespace nova::graphics
{
	class NOVA_API DX12CommandQueueFactory
	{
	public:
		static Microsoft::WRL::ComPtr<ID3D12CommandQueue> create(Microsoft::WRL::ComPtr<ID3D12Device6>& device, D3D12_COMMAND_LIST_TYPE type) noexcept;
		static Microsoft::WRL::ComPtr<ID3D12CommandQueue> create(Microsoft::WRL::ComPtr<ID3D12Device6>& device, D3D12_COMMAND_LIST_TYPE type, INT priority) noexcept;
		static Microsoft::WRL::ComPtr<ID3D12CommandQueue> create(Microsoft::WRL::ComPtr<ID3D12Device6>& device, D3D12_COMMAND_LIST_TYPE type, INT priority, UINT node_mask) noexcept;
	private:
		static D3D12_COMMAND_QUEUE_DESC get_descriptor(D3D12_COMMAND_LIST_TYPE type, INT priority, UINT node_mask) noexcept;
	};
}