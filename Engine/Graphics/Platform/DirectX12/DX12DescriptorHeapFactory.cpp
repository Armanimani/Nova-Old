#include "DX12DescriptorHeapFactory.hpp"

namespace nova::graphics
{
	Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> DX12DescriptorHeapFactory::create(
		Microsoft::WRL::ComPtr<ID3D12Device6>& device, const D3D12_DESCRIPTOR_HEAP_TYPE type, const UINT number) noexcept
	{
		const auto descriptor = get_descriptor(type, number);
		Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> descriptor_heap{};
		if (FAILED(device->CreateDescriptorHeap(&descriptor, IID_PPV_ARGS(&descriptor_heap))))
		{
			LOG_ENGINE_ERROR("Unable to create descriptor heap");
		}

		return descriptor_heap;
	}

	D3D12_DESCRIPTOR_HEAP_DESC DX12DescriptorHeapFactory::get_descriptor(const D3D12_DESCRIPTOR_HEAP_TYPE type, const UINT number) noexcept
	{
		D3D12_DESCRIPTOR_HEAP_DESC descriptor {};
		descriptor.Type = type;
		descriptor.NumDescriptors = number;

		return descriptor;
	}
}
