#pragma once

#include "Engine/core.hpp"

#include <d3d12.h>
#include <wrl.h>

namespace nova::graphics
{
	class NOVA_API DX12CommandAllocatorFactory
	{
	public:
		static Microsoft::WRL::ComPtr<ID3D12CommandAllocator> create(const Microsoft::WRL::ComPtr<ID3D12Device6>& device, D3D12_COMMAND_LIST_TYPE type) noexcept;
	};
}
