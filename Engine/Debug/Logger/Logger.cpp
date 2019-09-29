#include "Engine/Debug/Logger/Logger.hpp"

#include <chrono>
#include <unordered_map>
#include <ctime>

namespace nova
{
	std::unordered_map<Logger::MessageType, ConsoleController::ConsoleColor> Logger::m_color_registry
	{
		{ MessageType::normal, m_normal_color },
		{ MessageType::error, m_error_color },
		{ MessageType::warning, m_warning_color },
		{ MessageType::information, m_information_color }
	};
	
	Logger::Logger( std::string name): m_name{std::move(name)}
	{
	}

	void Logger::log_error(const std::string_view& error_message) const
	{
		print_message(error_message, MessageType::error);
	}

	void Logger::log_warning(const std::string_view& warning_message) const
	{
		print_message(warning_message, MessageType::warning);
	}

	void Logger::log_information(const std::string_view& information_message) const
	{
		print_message(information_message, MessageType::information);
	}

	void Logger::print_message(const std::string_view& message, const MessageType message_type) const
	{
		const auto formatted_string = get_formatted_string(message);
		const auto message_color = get_message_color(message_type);
		
		ConsoleController::set_color(message_color);
		ConsoleController::print_message(formatted_string);
		ConsoleController::set_color(m_normal_color);
	}

	ConsoleController::ConsoleColor Logger::get_message_color(const MessageType message_type)
	{
		return m_color_registry[message_type];
	}

	std::string Logger::get_formatted_string(const std::string_view& message) const
	{
		const auto time_str = get_formatted_time();
		const auto name_str = get_formatted_name();

		return time_str + ' ' + name_str + ": " + std::string(message);
	}

	std::string Logger::get_formatted_time()
	{
		const auto time_point = std::chrono::system_clock::now();
		const auto time_t = std::chrono::system_clock::to_time_t(time_point);
		struct tm time_structure {}; 
		const auto local_time = localtime_s(&time_structure, &time_t);

		const auto hour = std::to_string(time_structure.tm_hour);
		const auto minute = std::to_string(time_structure.tm_min);
		const auto second = std::to_string(time_structure.tm_sec);
		
		return { '[' + hour + ':' + minute + ':' + second + ']' };
	}

	std::string Logger::get_formatted_name() const
	{
		return { '[' + m_name + ']' };
	}
}
