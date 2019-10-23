#pragma once

#include<QtCore/QFile>
#include <unordered_map>

#include "constants.hpp"

enum class StyleSheetType
{
	dark
};

class StyleSheetManager
{
public:
	static QString get_stylesheet(StyleSheetType type);
private:
	static std::unordered_map<StyleSheetType, QString> m_registry;
};

inline QString StyleSheetManager::get_stylesheet(const StyleSheetType type)
{
	QFile style_file(m_registry[type]);
	style_file.open(QFile::ReadOnly);
	
	return QString(style_file.readAll());
}

std::unordered_map<StyleSheetType, QString> StyleSheetManager::m_registry =
{
	{StyleSheetType::dark, k_stylesheet_dark}
};
