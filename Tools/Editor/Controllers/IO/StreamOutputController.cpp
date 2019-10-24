#include "StreamOutputController.hpp"

StreamOutputController::StreamOutputController(std::ostream& stream, QTextEdit* text_edit)
	: m_stream(stream)
{
	m_text_edit = text_edit;
	m_old_buf = stream.rdbuf();
	stream.rdbuf(this);
}

StreamOutputController::~StreamOutputController()
{
	if (!m_string.empty())
		m_text_edit->append(m_string.c_str());

	m_stream.rdbuf(m_old_buf);
}

std::basic_streambuf<char>::int_type StreamOutputController::overflow(int_type v)
{
	if (v == '\n')
	{
		m_text_edit->append(m_string.c_str());
		m_string.erase(m_string.begin(), m_string.end());
	}
	else
		m_string += v;

	return v;
}

std::streamsize StreamOutputController::xsputn(const char* p, std::streamsize n)
{
	m_string.append(p, p + n);

	int pos = 0;
	while (pos != std::string::npos)
	{
		pos = m_string.find('\n');
		if (pos != std::string::npos)
		{
			std::string tmp(m_string.begin(), m_string.begin() + pos);
			m_text_edit->append(tmp.c_str());
			m_string.erase(m_string.begin(), m_string.begin() + pos + 1);
		}
	}

	return n;
}