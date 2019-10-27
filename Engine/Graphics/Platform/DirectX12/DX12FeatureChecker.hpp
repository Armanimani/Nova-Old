#pragma once

#include "Engine/core.hpp"

#include <d3d12.h>
#include <wrl.h>

namespace nova::graphics
{
	class NOVA_API DX12FeatureChecker
	{
	public:
		[[nodiscard]] static BOOL is_tearing_supported() noexcept;
	};
}
