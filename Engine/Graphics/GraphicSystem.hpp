#pragma once

#include "Engine/core.hpp"
#include "Engine/Graphics/GraphicSettings.hpp"

#include <memory>

namespace nova::graphics
{
	class NOVA_API GraphicSystem
	{
	public:
		GraphicSystem(GraphicSettings settings, void* window_handle);

		static void initialize() noexcept;
		static void present() noexcept;
	private:
		GraphicSettings m_settings {};
		void* m_window_handle {};
	};
}