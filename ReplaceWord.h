#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ReplaceWord.h"
#include <QMessageBox>
#include <qlist.h>
#include <qstack.h>

class ReplaceWord : public QMainWindow {
	Q_OBJECT

public:
	ReplaceWord(QWidget*, QList<QString>&, QStack<QString>&, QStack<QList<QString>>&);
	~ReplaceWord();

private slots:
	void on_Replace_clicked();

private:
	Ui::ReplaceWord *m_ui;
	QList<QString>& list;
	QStack<QString>& ReplaceOperation;
	QStack<QList<QString>>& UnupdatedList;
};
