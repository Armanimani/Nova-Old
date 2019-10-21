#pragma once

#include "ui_Editor.h"

class Editor : public QMainWindow
{
	Q_OBJECT

public:
	Editor(QWidget *parent = Q_NULLPTR);
private:
	Ui::EditorClass ui;

	void connect_signal_and_slots() const;
};