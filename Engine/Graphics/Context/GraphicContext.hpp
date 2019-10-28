#pragma once

#include "Engine/core.hpp"
#include "Engine/Graphics/GraphicAPI.hpp"
#include "Engine/Graphics/GraphicSettings.hpp"
#include "Engine/SystemInformation/SystemInformation.hpp"

namespace nova::graphics
{
	class NOVA_API GraphicContext
	{
	public:
		explicit GraphicContext(const GraphicSettings& settings);
		virtual ~GraphicContext() = default;
		GraphicContext(const GraphicContext& other) = default;
		GraphicContext(GraphicContext&& other) noexcept = delete;
		GraphicContext& operator=(const GraphicContext& other) = delete;
		GraphicContext& operator=(GraphicContext&& other) noexcept = delete;
		
		virtual void initialize() = 0;
		virtual void present() = 0;
		[[nodiscard]] virtual std::vector<GraphicCardInformation> get_adapter_information() = 0;
		[[nodiscard]] virtual GraphicAPI get_graphic_api() const noexcept = 0;

		[[nodiscard]] const GraphicSettings* get_settings() const noexcept;
	private:
		const GraphicSettings* m_settings{};
	};

}
