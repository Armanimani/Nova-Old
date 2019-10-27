#pragma once

#include "Engine/core.hpp"
#include "Engine/Graphics/GraphicAPI.hpp"
#include "Engine/SystemInformation/SystemInformation.hpp"

namespace nova::graphics
{
	class NOVA_API GraphicContextInterface
	{
	public:
		virtual ~GraphicContextInterface() = default;
		
		virtual void initialize() = 0;
		virtual void present() = 0;
		[[nodiscard]] virtual std::vector<GraphicCardInformation> get_adapter_information() = 0;
		[[nodiscard]] virtual GraphicAPI get_graphic_api() const noexcept = 0;
	};
}
