#include "DX12DeviceFactory.hpp"


namespace nova::graphics
{
	Microsoft::WRL::ComPtr<ID3D12Device6> DX12DeviceFactory::create() noexcept
	{
		return create(nullptr, D3D_FEATURE_LEVEL_12_1);
	}

	Microsoft::WRL::ComPtr<ID3D12Device6> DX12DeviceFactory::create(
		const D3D_FEATURE_LEVEL minimum_feature_level) noexcept
	{
		return create(nullptr, minimum_feature_level);
	}

	Microsoft::WRL::ComPtr<ID3D12Device6> DX12DeviceFactory::create(IUnknown* adapter,
		const D3D_FEATURE_LEVEL minimum_feature_level) noexcept
	{
		Microsoft::WRL::ComPtr<ID3D12Device6> device{};
		if (!SUCCEEDED(D3D12CreateDevice(adapter, minimum_feature_level, IID_PPV_ARGS(&device))))
		{
			LOG_ENGINE_ERROR("Unable to create the DirectX12 device");
		}
		return device;
	}
}
