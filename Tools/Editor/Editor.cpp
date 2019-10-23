#include "Editor.hpp"

#include "StyleSheet/StyleSheetManager.hpp"
#include "constants.hpp"

Editor::Editor(QWidget *parent)
	: QMainWindow(parent)
{
	this->setStyleSheet(StyleSheetManager::get_stylesheet(StyleSheetType::dark));
	
	ui.setupUi(this);
	
	this->setWindowIcon(QIcon(k_icon_nova_logo_black_32));

	connect_signal_and_slots();
}

void Editor::connect_signal_and_slots() const
{
	QObject::connect(ui.action_Exit, &QAction::triggered, this, &QMainWindow::close);
}
