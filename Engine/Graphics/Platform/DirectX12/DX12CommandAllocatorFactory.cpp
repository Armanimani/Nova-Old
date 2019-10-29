#include "DX12CommandAllocatorFactory.hpp"

namespace nova::graphics
{
	Microsoft::WRL::ComPtr<ID3D12CommandAllocator> DX12CommandAllocatorFactory::create(
		const Microsoft::WRL::ComPtr<ID3D12Device6>& device, const D3D12_COMMAND_LIST_TYPE type) noexcept
	{
		Microsoft::WRL::ComPtr<ID3D12CommandAllocator> command_allocator{};
		if (FAILED(device->CreateCommandAllocator(type, IID_PPV_ARGS(&command_allocator))))
		{
			LOG_ENGINE_ERROR("Unable to create command allocator for DirectX12");
		}
		return command_allocator;
	}
}
