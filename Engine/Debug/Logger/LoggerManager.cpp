#include "Engine/Debug/Logger/LoggerManager.hpp"
#include "Engine/Debug/Logger/Logger.hpp"

namespace  nova
{
	std::unordered_map<std::string, std::unique_ptr<Logger_Abstract>> LoggerManager::m_registry = []()
	{
		std::unordered_map<std::string, std::unique_ptr<Logger_Abstract>> map;
		map[m_engine_logger_name] = std::make_unique<Logger>(m_engine_logger_name);
		map[m_application_logger_name] = std::make_unique<Logger>(m_application_logger_name);
		return  map;
	}();
	
	void LoggerManager::create_logger(const std::string& logger_name)
	{			
		m_registry.insert({ logger_name, std::make_unique<Logger>(logger_name) });
	}

	Logger_Abstract* LoggerManager::get_logger(const std::string& logger_name)
	{
		return m_registry[logger_name].get();
	}

	Logger_Abstract* LoggerManager::get_engine_logger()
	{
		return m_registry[m_engine_logger_name].get();
	}

	Logger_Abstract* LoggerManager::get_application_logger()
	{
		return m_registry[m_application_logger_name].get();
	}
}
