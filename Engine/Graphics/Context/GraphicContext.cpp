#include "GraphicContext.hpp"

namespace nova::graphics
{
	GraphicContext::GraphicContext(const GraphicSettings& settings)
		: m_settings{&settings}
	{
	}

	const GraphicSettings* GraphicContext::get_settings() const noexcept
	{
		return m_settings;
	}
}
