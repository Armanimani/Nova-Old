#include "Editor.hpp"

#include <iostream>

#include <QtWidgets/QScrollBar>

#include "constants.hpp"
#include "StyleSheet/StyleSheetManager.hpp"

Editor::Editor(QWidget *parent)
	: QMainWindow(parent)
{
	this->setStyleSheet(StyleSheetManager::get_stylesheet(StyleSheetType::dark));
	
	ui.setupUi(this);
	
	this->setWindowIcon(QIcon(k_icon_nova_logo_black_32));

	redirect_stream_output();
	connect_signal_and_slots();
}

void Editor::showEvent(QShowEvent* event)
{
	initialize_engine();
}

void Editor::closeEvent(QCloseEvent* event)
{
	// Ensure the std::cout is piped back to console	
	m_engine_controller->get_engine()->stop();
}

void Editor::on_text_edit_output_text_changed() const
{
	auto vertical_scroll_bar = static_cast<QScrollBar*>(ui.textEdit_output->verticalScrollBar());
	vertical_scroll_bar->setValue(vertical_scroll_bar->maximum());
}

void Editor::connect_signal_and_slots() const
{
	QObject::connect(ui.action_Exit, &QAction::triggered, this, &QMainWindow::close);
	QObject::connect(ui.textEdit_output, &QTextEdit::textChanged, this, &Editor::on_text_edit_output_text_changed);
}

void Editor::redirect_stream_output()
{
	m_output_controller = std::make_unique<StreamOutputController>(std::cout, ui.textEdit_output);
}

void Editor::initialize_engine()
{
	m_engine_controller = std::make_unique<EngineController>(0);
}
