#include "Editor.hpp"

#include "StyleSheet/StyleSheetManager.hpp"

Editor::Editor(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	
	this->setStyleSheet(StyleSheetManager::get_stylesheet(StyleSheetType::dark));
	this->setWindowIcon(QIcon(":/Editor/Resources/icons/nova_logo_black_32.png"));

	connect_signal_and_slots();
}

void Editor::connect_signal_and_slots() const
{
	connect(ui.action_Exit, &QAction::triggered, this, &QMainWindow::close);
}
