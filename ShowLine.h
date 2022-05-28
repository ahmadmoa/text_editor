#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_Show_Line.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <qlist.h>
#include <QCloseEvent>
#include <time.h>
#include <string>
#include <sstream>

class ShowLine : public QMainWindow {
	Q_OBJECT

public:
	ShowLine(QWidget*, const QString&);
	~ShowLine();
	void closeEvent(QCloseEvent*);

private slots:
	void on_Show_clicked();

private:
	Ui::Form* m_ui;
	const QString& m_tempFileName;
};
