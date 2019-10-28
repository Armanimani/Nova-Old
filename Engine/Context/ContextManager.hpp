#pragma once

#include "Engine/core.hpp"
#include "Engine/Application/ApplicationSettings.hpp"
#include "Engine/Context/Context.hpp"


namespace nova
{
	class NOVA_API ContextManager
	{
	public:
		[[nodiscard]] static std::unique_ptr<Context> create(const ApplicationSettings& settings) noexcept;
	};
}
