#pragma once

#include <string>
#include <string_view>
#include <unordered_map>

#include "Engine/core.hpp"
#include "Engine/Debug/Logger/ConsoleController.hpp"
#include "Engine/Debug/Logger/Logger_Abstract.hpp"


namespace nova
{
	class NOVA_API Logger: public Logger_Abstract
	{
	public:
		explicit Logger(std::string name);
		
		void log_error(const std::string_view& error_message) const final;
		void log_warning(const std::string_view& warning_message) const final;
		void log_information(const std::string_view& information_message) const final;
	private:
		enum class MessageType
		{
			normal,
			error,
			warning,
			information,
		};

		[[nodiscard]] static ConsoleController::ConsoleColor get_message_color(MessageType message_type);
		[[nodiscard]] static std::string get_formatted_time();
		static std::unordered_map<MessageType, ConsoleController::ConsoleColor> m_color_registry;

		constexpr static ConsoleController::ConsoleColor m_normal_color{ 15 };
		constexpr static ConsoleController::ConsoleColor m_error_color{ 12 };
		constexpr static ConsoleController::ConsoleColor m_warning_color{ 14 };
		constexpr static ConsoleController::ConsoleColor m_information_color{ 10 };
		
		[[nodiscard]] std::string get_formatted_string(const std::string_view& message) const;
		[[nodiscard]] std::string get_formatted_name() const;
		void print_message(const std::string_view& message, MessageType message_type) const;
		
		std::string m_name {};
	};
}