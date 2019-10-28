#pragma once

#include "Engine/core.hpp"
#include "Engine/Graphics/Context/GraphicContext.hpp"

namespace nova::graphics
{
	class NOVA_API GraphicSystem
	{
	public:
		explicit GraphicSystem(GraphicContext* context);

		void initialize() const noexcept;
		void present() const noexcept;
	private:
		GraphicContext* m_context;
		void update_adapter_information() const noexcept;
	};
}