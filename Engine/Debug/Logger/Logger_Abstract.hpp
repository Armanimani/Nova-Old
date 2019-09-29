#pragma once


namespace nova
{
	class NOVA_API Logger_Abstract
	{
	public:
		virtual ~Logger_Abstract() = default;
		
		virtual void log_error(const std::string_view& error_message) const = 0;
		virtual void log_warning(const std::string_view& warning_message) const = 0;
		virtual void log_information(const std::string_view& information_message) const = 0;
	};
}