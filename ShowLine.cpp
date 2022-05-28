#include "ShowLine.h"
#include "text_editor_UI_test.h"
#include <iostream>

ShowLine::ShowLine(QWidget* parent, const QString& tempFileName) : QMainWindow(parent),
m_ui(new Ui::Form), m_tempFileName(tempFileName) {
	m_ui->setupUi(this);
}

ShowLine::~ShowLine() {
	delete m_ui;
}

void ShowLine::closeEvent(QCloseEvent* event) {
	QMessageBox::StandardButton resBtn = QMessageBox::question(this, this->accessibleName(),
		tr("Are you sure?\n"),
		QMessageBox::Cancel | QMessageBox::No | QMessageBox::Yes,
		QMessageBox::Yes);

	if (resBtn != QMessageBox::Yes) event->ignore();

	else {
		QFile file(m_tempFileName);

		if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
			QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
			return;
		}

		file.remove();
		event->accept();
	}
}

void ShowLine::on_Show_clicked() {
	QString LineNumber = m_ui->textEdit->toPlainText();
	int num = LineNumber.toInt();

	QFile file(m_tempFileName);
	if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
		QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
		return;
	}

	QTextStream in(&file);
	QString line;

	if (LineNumber.isEmpty()) return;

	for (int i = 0; i < num; i++) {
		if (i == num - 1) {
			line = in.readLine();
			if (line.isEmpty()) {
				m_ui->textBrowser->setTextColor("red");
				m_ui->textBrowser->setText("INDEX OUT OF RANGE");
			}
			else {
				m_ui->textBrowser->setTextColor("black");
				m_ui->textBrowser->setText(line);
			}
			file.close();
		}
		else in.readLine();
	}
}
