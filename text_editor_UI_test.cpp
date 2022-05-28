#include "text_editor_UI_test.h"

text_editor_UI_test::text_editor_UI_test(QWidget* parent)
	: QMainWindow(parent), m_ui(new Ui::MiniTexteditor)
{
	m_ui->setupUi(this);

	std::stringstream ss;
	ss << time(NULL);
	std::string fileName = ss.str();

	sltempFileName = QString::fromStdString("./tmp_files/" + fileName + "_sl.txt");
	srtempFileName = QString::fromStdString("./tmp_files/" + fileName + "_sr.txt");

	timer = new QTimer();
	timer->setInterval(100);
	connect(timer, &QTimer::timeout, this, [=]() {
		QApplication::processEvents(); // To Accept Any Event For the app
		m_ui->textBrowser->clear(); // Clear the currnt contaiend text
		m_ui->lineCount->clear(); // Clear the currnt contaiend text


		for (auto& line: qList) m_ui->textBrowser->append(line); // Append Eveyline in qList to the text browser 
		for (int i = 0; i < qList.size(); i++) m_ui->lineCount->append(QString::fromStdString(std::to_string(i + 1)));
		});

	timer->start();
}

text_editor_UI_test::~text_editor_UI_test() {
	delete m_ui;
	delete Show_Line1;
	delete ReplaceWord1;
	delete search1;
	delete timer;
}

void text_editor_UI_test::on_Add_clicked() {
    if (m_ui->plainTextEdit->toPlainText().isEmpty()) return;

	is_sorted = false;

	QList<QString> tmp_List;
	
	QString data = m_ui->plainTextEdit->toPlainText() + ' ';

	QString LineNumber = m_ui->textEdit->toPlainText();
	int num = LineNumber.toInt() - 1;

	//if there is many inserted lines once
	if (data.contains('\n')) {
		tmp_List = data.split("\n");
		qList_b4_app.append(tmp_List.length());
	}

	//appending lines
	if (LineNumber.isEmpty()) {
		//many lines
		if (data.contains('\n')) {
			qList.append(tmp_List);
			operations.push("appmany");
		}
		//one line
		else {
			qList.append(data);
			operations.push("appline");
		}

		m_ui->plainTextEdit->clear();
		m_ui->textEdit->clear();
		redo.clear();
		return;
	}

	//index out of range
	if (num > qList.length()) return;
	else if (num < 0) return;
	
	//inserting
	else if (num <= qList.length()) {
		//many lines
		if (data.contains('\n')) {
			int j = 0;

			for (int i = num; i < (num + tmp_List.length()); i++) {
				qList.insert(i, tmp_List[j]);
				j++;
			}
			operations.push(QString::number(num) + " MX");
		}
		//one line
		else {
			qList.insert(num, data);
			operations.push(QString::number(num) + " X");
		}
	}

	m_ui->plainTextEdit->clear();
	m_ui->textEdit->clear();
	redo.clear();
}

void text_editor_UI_test::on_Delete_clicked() {
	QString LineNumber = m_ui->textEdit->toPlainText();
	int num = LineNumber.toInt() - 1;
	// index out of range
	if (num >= qList.length() || num < 0) return;

	operations.push(QString::number(num) + " del");
	unexisted_values.push(qList.at(num));

	qList.removeAt(num);
	m_ui->plainTextEdit->clear();
	m_ui->textEdit->clear();
	redo.clear();
}

void text_editor_UI_test::on_Update_clicked() {
	QString data = m_ui->plainTextEdit->toPlainText();
	QString LineNumber = m_ui->textEdit->toPlainText();
	int num = LineNumber.toInt() - 1;
	//index out of range
	if (num >= qList.length() || num < 0) return;

	operations.push(QString::number(num) + " update");
	unexisted_values.push(qList.at(num));

	qList[num] = data;
	m_ui->plainTextEdit->clear();
	m_ui->textEdit->clear();
	redo.clear();
}
//EDIT THIS SHIT
void text_editor_UI_test::on_actionNew_project_triggered() {
	currentFile.clear();
	m_ui->plainTextEdit->setPlainText(QString());
	m_ui->textBrowser->setText(QString());
}

void text_editor_UI_test::on_actionOpen_project_triggered() {
	QString fileName = QFileDialog::getOpenFileName(this, "Open the file");
	QFile file(fileName);
	currentFile = fileName;

	if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
		QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
		return;
	}

	setWindowTitle(fileName);
	QString line;
	QTextStream in(&file);
	qList.clear();
	while (!in.atEnd()) {
		line = in.readLine();
		qList.append(line);
	}

	file.close();
}

void text_editor_UI_test::on_actionExit_triggered() {
	QApplication::quit();
}

void text_editor_UI_test::on_actionSave_as_triggered() {
	QString fileName = QFileDialog::getSaveFileName(this, "Save");
	QFile file(fileName);
	if (!file.open(QFile::WriteOnly | QFile::Text)) {
		QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
		return;
	}
	currentFile = fileName;
	setWindowTitle(fileName);
	QTextStream out(&file);
	QString text = m_ui->textBrowser->toPlainText();
	out << text;
	file.close();
}

void text_editor_UI_test::on_actionCopy_triggered() {
	m_ui->plainTextEdit->copy();
}

void text_editor_UI_test::on_actionCut_triggered() {
	m_ui->plainTextEdit->cut();
}

void text_editor_UI_test::on_actionPaste_triggered() {
	m_ui->plainTextEdit->paste();
}

void text_editor_UI_test::on_actionSpell_check_triggered() {
	Trie user_input;
	for (int i = 0; i < qList.length(); i++) {
		QString s = "";
		for (int j = 0; j < qList[i].length(); j++) {
			QChar c = qList[i][j];

			if (c == ' ' || c == '\n') {
				if (!user_input.searchWord(s)) {
					QString index = QString::number(i + 1);
					m_ui->textBrowser_2->append(" '" + s + "' at line : " + index);
				}
				s = "";
			}
			else s += c;
		}
	}
}

void text_editor_UI_test::on_actionShow_line_triggered() {

	QFile file(sltempFileName);

	if (!file.open(QIODevice::WriteOnly | QFile::Text)) {
		QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
		return;
	}
	QTextStream out(&file);
	for (int i = 0; i < qList.length(); i++) {
		out << qList[i] << '\n';
	}
	file.close();

	Show_Line1 = new ShowLine(this, sltempFileName);
	Show_Line1->show();
}

void text_editor_UI_test::on_actionSearch_triggered() {

	QFile file(srtempFileName);

	if (!file.open(QIODevice::WriteOnly | QFile::Text)) {
		QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
		return;
	}
	QTextStream out(&file);
	for (int i = 0; i < qList.length(); i++) {
		out << qList[i] << '\n';
	}
	file.close();

	search1 = new Search(this, srtempFileName);
	search1->show();
}

void text_editor_UI_test::on_actionFind_and_replace_triggered() {
	ReplaceWord1 = new ReplaceWord(this, qList, operations, qList_b4_Replace);
	ReplaceWord1->show();
}

void text_editor_UI_test::on_clear_clicked() {
	operations.push("clear");
	qList_b4_clear = qList;
	qList = { NULL };
	redo.clear();
}

void text_editor_UI_test::on_actionSort_line_triggered() {
	if (is_sorted) return;

	qList_b4_sort = qList;
	qList.sort();
	is_sorted = true;
	operations.append("sort");
	redo.clear();
}

void text_editor_UI_test::on_Undo_clicked() {
	if (operations.isEmpty()) return;

	m_ui->textBrowser_2->clear();

	if (operations.top() == "appline") {
		redo_values.push(qList.last());
		qList.removeLast();
	}

	else if (operations.top().contains(" X")) {//   9 X
		int num = operations.top().split(" ")[0].toInt();
		redo_values.push(qList.at(num));
		qList.removeAt(num);
	}

	else if (operations.top() == "appmany") {
		for (int i = 0; i < qList_b4_app.top(); i++) {
			redo_values.push(qList.last());
			qList.removeLast();
		}
		
		redo_qList_b4_app.push(qList_b4_app.pop());
	}

	else if (operations.top().contains(" MX")) {// 9 MX
		int num = operations.top().split(" ")[0].toInt();
		for (int i = 0; i < qList_b4_app.top(); i++) {
			redo_values.push(qList.at(num));
			qList.removeAt(num);
		}

		redo_qList_b4_app.push(qList_b4_app.pop());
	}

	else if (operations.top().contains(" del")) {// 9 del
		int num = operations.top().split(" ")[0].toInt();
		redo_values.push(unexisted_values.top());
		qList.insert(num, unexisted_values.pop());
	}

	else if (operations.top().contains(" update")) {
		int num = operations.top().split(" ")[0].toInt();
		redo_values.push(qList[num]);
		qList[num] = unexisted_values.pop();
	}

	else if (operations.top() == "clear") {
		qList = qList_b4_clear;
	}

	else if (operations.top() == "sort") {
		redo_qList_b4_sort = qList;
		qList = qList_b4_sort;
		is_sorted = false;
	}

	else if (operations.top() == "Replace") {
		redo_qList_b4_Replace.push(qList);

		qList = qList_b4_Replace.pop();
	}
	redo.push(operations.pop());
}

void text_editor_UI_test::on_Redo_clicked() {
	if (redo.isEmpty()) return;
	m_ui->textBrowser_2->clear();

	if (redo.top() == "appline") {
		qList.append(redo_values.pop());
	}

	else if (redo.top().contains(" X")) {
		int num = redo.top().split(" ")[0].toInt();
		qList.insert(num, redo_values.pop());
	}

	else if (redo.top() == "appmany") {
		for (int i = 0; i < redo_qList_b4_app.top(); i++) qList.append(redo_values.pop());

		qList_b4_app.push(redo_qList_b4_app.pop());
	}

	else if (redo.top().contains(" MX")) {
		int num = redo.top().split(" ")[0].toInt();

		for (int i = 0; i < redo_qList_b4_app.top(); i++) qList.insert(num, redo_values.pop());		

		qList_b4_app.push(redo_qList_b4_app.pop());
	}

	else if (redo.top().contains(" del")) {
		int num = redo.top().split(" ")[0].toInt();

		unexisted_values.push(redo_values.pop());
		qList.removeAt(num);
	}

	else if (redo.top().contains(" update")) {
		int num = redo.top().split(" ")[0].toInt();

		unexisted_values.push(qList[num]);
		qList[num] = redo_values.pop();
	}

	else if (redo.top() == "clear") {
		qList = { NULL };
	}

	else if (redo.top() == "sort") {
		qList = redo_qList_b4_sort;
		is_sorted = true;
	}

	else if (redo.top() == "Replace") {
		qList_b4_Replace.push(qList);
		qList = redo_qList_b4_Replace.pop();
	}
	operations.push(redo.pop());
}
