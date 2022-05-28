#include "ReplaceWord.h"

ReplaceWord::ReplaceWord(QWidget* parent, QList<QString>& qList, QStack<QString>& operations, QStack<QList<QString>>& qList_b4_Replace) : QMainWindow(parent),
m_ui(new Ui::ReplaceWord), list(qList), ReplaceOperation(operations), UnupdatedList(qList_b4_Replace){
	m_ui->setupUi(this);
}

ReplaceWord::~ReplaceWord() {
	delete m_ui;
}

void ReplaceWord::on_Replace_clicked() {
	QString from = m_ui->FromText->toPlainText();
	QString to = m_ui->ToText->toPlainText();

	bool found = false;
	UnupdatedList.push(list);

	for (auto& line : list) {
		if (line.contains(from)) {
			line.replace(from, to);
			found = true;
		}
	}
	m_ui->textBrowser->setTextColor("white");
	if (!found) {
		m_ui->textBrowser->setText(from + " doesn't exist :(");
		return;
	}
	m_ui->textBrowser->setText("DONE :)");

	ReplaceOperation.push("Replace");
}