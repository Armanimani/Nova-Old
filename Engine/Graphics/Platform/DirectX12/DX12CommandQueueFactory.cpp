#include "DX12CommandQueueFactory.hpp"

namespace nova::graphics
{
	Microsoft::WRL::ComPtr<ID3D12CommandQueue> DX12CommandQueueFactory::create(
		Microsoft::WRL::ComPtr<ID3D12Device6>& device, const D3D12_COMMAND_LIST_TYPE type) noexcept
	{
		return create(device, type, D3D12_COMMAND_QUEUE_PRIORITY_NORMAL, 0);
	}

	Microsoft::WRL::ComPtr<ID3D12CommandQueue> DX12CommandQueueFactory::create(
		Microsoft::WRL::ComPtr<ID3D12Device6>& device, const D3D12_COMMAND_LIST_TYPE type, const INT priority) noexcept
	{
		return create(device, type, priority, 0);
	}

	Microsoft::WRL::ComPtr<ID3D12CommandQueue> DX12CommandQueueFactory::create(
		Microsoft::WRL::ComPtr<ID3D12Device6>& device, const D3D12_COMMAND_LIST_TYPE type, const INT priority,
		const UINT node_mask) noexcept
	{
		Microsoft::WRL::ComPtr<ID3D12CommandQueue> command{};
		const auto descriptor = get_descriptor(type, priority, 0);

		if (FAILED(device->CreateCommandQueue(&descriptor, IID_PPV_ARGS(&command))))
		{
			LOG_ENGINE_ERROR("Unable to create the command queue of DirectX");
		}
		return command;
	}

	D3D12_COMMAND_QUEUE_DESC DX12CommandQueueFactory::get_descriptor(const D3D12_COMMAND_LIST_TYPE type, const INT priority,
		const UINT node_mask) noexcept
	{
		D3D12_COMMAND_QUEUE_DESC descriptor;
		descriptor.Type = type;
		descriptor.Priority = priority;
		descriptor.Flags = D3D12_COMMAND_QUEUE_FLAG_NONE;
		descriptor.NodeMask = node_mask;

		return descriptor;
	}
}
