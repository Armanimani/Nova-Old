#include "Engine/Debug/Logger/Logger.hpp"

#include <unordered_map>

#include "Engine/Clock/CalenderClock.hpp"

namespace nova
{
	constexpr auto k_time_delimiter = ':';
	constexpr auto k_date_delimiter = '/';
	constexpr auto k_time_date_delimiter = "-";
	constexpr auto k_name_prefix = '[';
	constexpr auto k_name_postfix = ']';
	constexpr auto k_message_prefix = ": ";
	constexpr auto k_calender_information_postfix = ' ';
	constexpr auto k_message_type_prefix = '[';
	constexpr auto k_message_type_postfix = ']';
	
	std::unordered_map<Logger::MessageType, ConsoleController::ConsoleColor> Logger::m_color_registry
	{
		{ MessageType::normal, m_normal_color },
		{ MessageType::error, m_error_color },
		{ MessageType::warning, m_warning_color },
		{ MessageType::information, m_information_color }
	};

	std::unordered_map<Logger::MessageType, std::string> Logger::m_message_type_dictionary
	{
		{ MessageType::normal, "MESSAGE    " },
		{ MessageType::error, "ERROR      " },
		{ MessageType::warning, "WARNING    " },
		{ MessageType::information, "INFORMATION" }
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
		const auto formatted_string = get_formatted_string(message, message_type);
		const auto message_color = get_message_color(message_type);
		
		ConsoleController::set_color(message_color);
		ConsoleController::print_message(formatted_string);
		ConsoleController::set_color(m_normal_color);
	}

	ConsoleController::ConsoleColor Logger::get_message_color(const MessageType message_type)
	{
		return m_color_registry[message_type];
	}

	std::string Logger::get_formatted_string(const std::string_view& message, const MessageType message_type) const
	{
		const auto time_str = get_formatted_time();
		const auto name_str = get_formatted_name();
		const auto message_type_str = get_formatted_message_type(message_type);

		return time_str + k_calender_information_postfix + name_str + message_type_str + k_message_prefix + std::string(message);
	}

	std::string Logger::get_formatted_time()
	{
		const auto calender_information = CalenderClock::get_calender_information();

		const auto year = std::to_string(calender_information.year);
		const auto month = std::to_string(calender_information.month);
		const auto day = std::to_string(calender_information.day);
		const auto hour = std::to_string(calender_information.hour);
		const auto minute = std::to_string(calender_information.minute);
		const auto second = std::to_string(calender_information.second);

		const auto time_information{ hour + k_time_delimiter + minute + k_time_delimiter + second };
		const auto date_information{ day + k_date_delimiter + month + k_date_delimiter + year };
		
		return { date_information + k_time_date_delimiter + time_information };
	}

	std::string Logger::get_formatted_name() const
	{
		return { k_name_prefix + m_name + k_name_postfix };
	}

	std::string Logger::get_formatted_message_type(MessageType message_type) const
	{
		return { k_message_type_prefix + m_message_type_dictionary[message_type] + k_message_type_postfix };
	}
}
