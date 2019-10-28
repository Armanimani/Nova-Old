#pragma once

#include "Engine/core.hpp"

#include <wrl.h>
#include <d3d12.h>

namespace nova::graphics
{
	class NOVA_API DX12DebugController
	{
	public:
		static void enable_debug_interface() noexcept;
		static void enable_debug_info_queue(const Microsoft::WRL::ComPtr<ID3D12Device>& device) noexcept;
	};
}