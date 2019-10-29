#pragma once

#include "Engine/core.hpp"

#include <d3d12.h>
#include <wrl.h>

namespace nova::graphics
{
	class NOVA_API DX12FenceFactory
	{
	public:
		static Microsoft::WRL::ComPtr<ID3D12Fence1> create(const Microsoft::WRL::ComPtr<ID3D12Device6>& device, D3D12_FENCE_FLAGS flags) noexcept;
	};
}