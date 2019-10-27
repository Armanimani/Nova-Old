#include "DX12DXGIFactoryFactory.hpp"

namespace nova::graphics
{
	Microsoft::WRL::ComPtr<IDXGIFactory7> DX12DXGIFactoryFactory::create()
	{
		Microsoft::WRL::ComPtr<IDXGIFactory7> factory {};
#ifndef DEPLOYMENT
		if (!SUCCEEDED(CreateDXGIFactory2(DXGI_CREATE_FACTORY_DEBUG, IID_PPV_ARGS(&factory))))
		{
			LOG_ENGINE_ERROR("Unable to create DXGI factory in debug mode");
		}
#else
		if (!SUCCEEDED(CreateDXGIFactory2(nullptr, IID_PPV_ARGS(&dxgi_factory))))
		{
			LOG_ENGINE_ERROR("Unable to create DXGI factory in development mode");
		}
#endif
		return factory;
	}
}
