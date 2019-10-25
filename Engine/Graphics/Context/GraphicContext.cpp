#include "GraphicContext.hpp"

namespace nova
{
	GraphicContext::GraphicContext(Int64 window_handle): m_window_handle{window_handle}
	{
	}

	Int64 GraphicContext::get_window_handle() const noexcept
	{
		return m_window_handle;
	}
}
