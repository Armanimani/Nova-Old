#pragma once

#include "ui_Editor.h"

#include <memory>
#include <QtWidgets/QTextEdit>

#include "Utilities//IO/StreamOutputController.hpp"


class Editor : public QMainWindow
{
	Q_OBJECT

public:
	Editor(QWidget *parent = Q_NULLPTR);
private slots:
	void on_text_edit_output_text_changed();
private:
	Ui::EditorClass ui;
	std::unique_ptr<StreamOutputController> m_output_controller{ nullptr };

	void connect_signal_and_slots() const;
	void redirect_stream_output();
};
