#pragma once

#include "Engine/core.hpp"
#include <dxgi1_6.h>
#include <wrl.h>

namespace nova::graphics
{
	class NOVA_API DX12DXGIFactoryFactory
	{
	public:
		static Microsoft::WRL::ComPtr<IDXGIFactory7> create();
	};
}
