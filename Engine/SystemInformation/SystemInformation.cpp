#include "SystemInformation.hpp"

namespace nova
{
	std::vector<GraphicCardInformation> SystemInformation::graphic_cards{};
	std::mutex SystemInformation::graphic_cards_mutex{};
}