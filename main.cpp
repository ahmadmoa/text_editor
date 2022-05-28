#include "MainMenu.h"
#include <QtWidgets/QApplication>

int main(int argc, char* argv[]) {

	QApplication a(argc, argv);

	MainMenu m;
	m.show();
	return a.exec();
}

