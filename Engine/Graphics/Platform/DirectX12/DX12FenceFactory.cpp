#include "DX12FenceFactory.hpp"

namespace nova::graphics
{
	Microsoft::WRL::ComPtr<ID3D12Fence1> DX12FenceFactory::create(const Microsoft::WRL::ComPtr<ID3D12Device6>& device,
		const D3D12_FENCE_FLAGS flags) noexcept
	{
		Microsoft::WRL::ComPtr<ID3D12Fence1> fence{};

		if(FAILED(device->CreateFence(0, flags, IID_PPV_ARGS(&fence))))
		{
			LOG_ENGINE_ERROR("Unable to create fence for DirectX12");
		}
		
		return fence;
	}
}
