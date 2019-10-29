#pragma once

#include "Engine/core.hpp"

#include <d3d12.h>
#include <wrl.h>

namespace nova::graphics
{
	class NOVA_API DX12CommandListFactory
	{
	public:
		static Microsoft::WRL::ComPtr<ID3D12CommandList> create(const Microsoft::WRL::ComPtr<ID3D12Device6>& device, const Microsoft::WRL::ComPtr<ID3D12CommandAllocator>& allocator,
			D3D12_COMMAND_LIST_TYPE type) noexcept;
	};
}
