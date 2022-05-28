#include "MainMenu.h"

MainMenu::MainMenu(QWidget *parent) : QMainWindow(parent), m_ui(new Ui::MainMenu) {
	m_ui->setupUi(this);
}

MainMenu::~MainMenu() {

}

void MainMenu::on_pushButton_8_clicked() {
	text = new text_editor_UI_test();
	text->show();
	this->close();
}

void MainMenu::on_pushButton_9_clicked() {
	QString fileName = QFileDialog::getOpenFileName(this, "Open the file");
	QFile file(fileName);

	if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
		QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
		return;
	}

	setWindowTitle(fileName);
	QString line;
	QTextStream in(&file);
	QList<QString>  qList;

	while (!in.atEnd()) qList.append(in.readLine());

	file.close();

	text = new text_editor_UI_test();
	text->setQList(qList);
	text->show();
	this->close();
}

