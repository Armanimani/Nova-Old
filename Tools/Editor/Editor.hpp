#pragma once

#include "ui_Editor.h"

#include <memory>

#include "Controllers/IO/StreamOutputController.hpp"
#include "Controllers/Engine/EngineController.hpp"


class Editor : public QMainWindow
{
	Q_OBJECT

public:
	Editor(QWidget *parent = Q_NULLPTR);
protected:
	void showEvent(QShowEvent* event) override;
	void closeEvent(QCloseEvent* event) override;
private slots:
	void on_text_edit_output_text_changed() const;
private:
	Ui::EditorClass ui;
	std::unique_ptr<StreamOutputController> m_output_controller{};
	std::unique_ptr<EngineController> m_engine_controller{};

	void connect_signal_and_slots() const;
	void redirect_stream_output();
	void initialize_engine();
};
