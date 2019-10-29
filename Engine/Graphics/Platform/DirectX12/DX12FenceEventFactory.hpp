#pragma once

#include "Engine/core.hpp"

#include <windows.h>

namespace nova::graphics
{
	class NOVA_API DX12FenceEventFactory
	{
	public:
		static HANDLE create() noexcept;
	};
}