#pragma once

#include <ostream>
#include <QtWidgets/QTextEdit>

class StreamOutputController final : public std::basic_streambuf<char>
{
public:
	StreamOutputController(std::ostream& stream, QTextEdit* text_edit);
	~StreamOutputController();

protected:
	int_type overflow(int_type v) override;

	std::streamsize xsputn(const char* p, std::streamsize n) override;

private:
	std::ostream& m_stream;
	std::streambuf* m_old_buf;
	std::string m_string;

	QTextEdit* m_text_edit;
};