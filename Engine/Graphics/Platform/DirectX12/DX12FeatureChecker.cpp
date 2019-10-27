#include "DX12FeatureChecker.hpp"
#include "DX12DXGIFactoryFactory.hpp"

namespace nova::graphics
{
	BOOL DX12FeatureChecker::is_tearing_supported() noexcept
	{
		BOOL result = FALSE;

		auto factory = DX12DXGIFactoryFactory::create();
		if (FAILED(factory->CheckFeatureSupport(DXGI_FEATURE_PRESENT_ALLOW_TEARING, &result, sizeof(result))))
		{
			LOG_ENGINE_ERROR("Unable to get the tearing support");
			return FALSE;
		}
		return result;
	}
}
