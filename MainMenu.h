#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainMenu.h"
#include "text_editor_UI_test.h"

class MainMenu : public QMainWindow
{
	Q_OBJECT

public:
	MainMenu(QWidget *parent = Q_NULLPTR);
	~MainMenu();

private slots:
	void on_pushButton_8_clicked();
	void on_pushButton_9_clicked();

private:
	Ui::MainMenu *m_ui;
	text_editor_UI_test* text{};
};
