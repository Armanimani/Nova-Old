#include "DX12FenceEventFactory.hpp"

namespace nova::graphics
{
	HANDLE DX12FenceEventFactory::create() noexcept
	{
		const auto fence_event = CreateEvent(nullptr, false, false, nullptr);

		if(!fence_event)
		{
			LOG_ENGINE_ERROR("Unable to create fence event for DirectX12");
		}

		return fence_event;
	}
}
