#pragma once

#include <memory>
#include <string>
#include <unordered_map>

#include "Engine/core.hpp"
#include "Engine/Debug/Logger/Logger_Abstract.hpp"

namespace nova
{
	class NOVA_API LoggerManager
	{
	public:
		static void create_logger(const std::string& logger_name);
		static Logger_Abstract* get_logger(const std::string& logger_name);

		static Logger_Abstract* get_engine_logger();
		static Logger_Abstract* get_application_logger();
	private:
		constexpr static auto m_engine_logger_name = "Engine";
		constexpr static auto m_application_logger_name = "Application";
		
		static std::unordered_map<std::string, std::unique_ptr<Logger_Abstract>> m_registry;
	};
}