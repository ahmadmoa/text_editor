#pragma once

#include "trie.h"
#include <QtWidgets/QMainWindow>
#include "ui_text_editor_UI_test.h"
#include <QFileDialog>
#include <qlist.h>
#include <qstring.h>
#include <qstack.h>
#include "ShowLine.h"
#include "Search.h"
#include "ReplaceWord.h"
#include <QTime>
#include <iostream>
#include <qtimer.h>

class text_editor_UI_test : public QMainWindow
{
    Q_OBJECT
public:
    text_editor_UI_test(QWidget* parent = Q_NULLPTR);
    ~text_editor_UI_test();
    void setQList(QList<QString> qList_) { qList = qList_; }
private slots:

    void on_Add_clicked();
    void on_Undo_clicked();
    void on_Redo_clicked();
    void on_clear_clicked();
    void on_Delete_clicked();
    void on_Update_clicked();
    //file
    void on_actionNew_project_triggered();
    void on_actionOpen_project_triggered();
    void on_actionExit_triggered();
    void on_actionSave_as_triggered();
    //edit
    void on_actionCopy_triggered();
    void on_actionCut_triggered();
    void on_actionPaste_triggered();
    void on_actionSort_line_triggered();
    //view
    void on_actionSpell_check_triggered();
    void on_actionShow_line_triggered();
    void on_actionFind_and_replace_triggered();
    //Selection
    void on_actionSearch_triggered();

private:
    Ui::MiniTexteditor* m_ui;
    QString currentFile = "";
    QList<QString> qList;

    //undo
    QStack<QString> operations;

    QStack<int> qList_b4_app;
    QStack<QString> unexisted_values;
    QList<QString> qList_b4_sort;
    QList<QString> qList_b4_clear;
    QStack<QList<QString>> qList_b4_Replace;
    bool is_sorted = false;

    //redo
    QStack<QString> redo;
    QStack<QString> redo_values;
    QStack<int> redo_qList_b4_app;
    QList<QString> redo_qList_b4_sort;
    QStack<QList<QString>> redo_qList_b4_Replace;

    //navigation
    ShowLine* Show_Line1{};
    ReplaceWord* ReplaceWord1{};
    Search* search1{};
    // File Name
    QString sltempFileName{}, srtempFileName{};
    QTimer* timer;
};

//append line __ appline
// 
//insert at __ num X
// 
//appending many lines once __ appmany
// 
//inserting many lines once __ num MX
// 
//Deleting __ num del
// 
//Updating __ num update
// 
//Sorting __ sort
//
//Clearing __ clear
//
//Replacing __ Replace