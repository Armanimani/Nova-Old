#pragma once

#include "Engine/nova.hpp"

#include <d3d12.h>
#include <wrl.h>

namespace nova::graphics
{
	class NOVA_API DX12DescriptorHeapFactory
	{
	public:
		static Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> create(Microsoft::WRL::ComPtr<ID3D12Device6>& device, 
			D3D12_DESCRIPTOR_HEAP_TYPE type, UINT number) noexcept;
	private:
		[[nodiscard]] static D3D12_DESCRIPTOR_HEAP_DESC get_descriptor(D3D12_DESCRIPTOR_HEAP_TYPE type, UINT number) noexcept;
	};
}
