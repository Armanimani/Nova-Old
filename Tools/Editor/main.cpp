#include "Editor.hpp"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication application(argc, argv);
	Editor window;
	window.show();
	return application.exec();
}
