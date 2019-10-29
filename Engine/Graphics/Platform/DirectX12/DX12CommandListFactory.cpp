#include "DX12CommandListFactory.hpp"

namespace nova::graphics
{
	Microsoft::WRL::ComPtr<ID3D12GraphicsCommandList5> DX12CommandListFactory::create(
		const Microsoft::WRL::ComPtr<ID3D12Device6>& device,
		const Microsoft::WRL::ComPtr<ID3D12CommandAllocator>& allocator, const D3D12_COMMAND_LIST_TYPE type) noexcept
	{
		Microsoft::WRL::ComPtr<ID3D12GraphicsCommandList5> command_list{};
		if (FAILED(device->CreateCommandList(0, type, allocator.Get(), nullptr, IID_PPV_ARGS(&command_list))))
		{
			LOG_ENGINE_ERROR("Unable to create the command list for DirectX12");
		}
		return command_list;
	}
}
