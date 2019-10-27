#pragma once

#include <d3d12.h>
#include <wrl.h>

#include "Engine/core.hpp"

namespace nova::graphics
{
	class NOVA_API DX12DeviceFactory
	{
	public:
		static Microsoft::WRL::ComPtr<ID3D12Device6> create() noexcept;
		static Microsoft::WRL::ComPtr<ID3D12Device6> create(D3D_FEATURE_LEVEL minimum_feature_level) noexcept;
		static Microsoft::WRL::ComPtr<ID3D12Device6> create(IUnknown* adapter, D3D_FEATURE_LEVEL minimum_feature_level) noexcept;
	};
}