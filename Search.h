#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_Search.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QCloseEvent>
#include <qlist.h>

class Search : public QMainWindow {
	Q_OBJECT

public:
	Search(QWidget*, const QString&);
	~Search();
	void closeEvent(QCloseEvent*);

private slots:
	void on_search_clicked();

private:
	Ui::SearchClass* m_ui;
	const QString& m_tempFileName;
};
