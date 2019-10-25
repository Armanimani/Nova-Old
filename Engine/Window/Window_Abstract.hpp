#pragma once

#include "Engine/nova.hpp"

namespace nova
{
	class NOVA_API Window_Abstract
	{
	public:
		virtual ~Window_Abstract() = default;
		
		[[nodiscard]] virtual Int64 get_window_handle() const noexcept = 0;

	// TODO: implement the remaining of this class
	};
}