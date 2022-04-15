/********************************************************************************
** Form generated from reading UI file 'text_editor.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEXT_EDITOR_H
#define UI_TEXT_EDITOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_text_editorClass
{
public:
    QAction *actionOpen_project;
    QAction *actionNew_project;
    QAction *actionSave_As;
    QAction *actionExit;
    QAction *actionUn_do;
    QAction *actionRedo;
    QAction *actionFonts;
    QAction *actionSplit_view;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionSave;
    QAction *actionPrint;
    QAction *actionNew_window;
    QAction *actionClose_window;
    QAction *actionThemes;
    QAction *action_7;
    QAction *actionHide_minimap;
    QAction *actionHide_slidebar;
    QAction *actionOptions;
    QAction *actioncreated_by_kings_ayman_ahmad;
    QAction *actionSelect_All_Ctrl_A;
    QAction *actionExpand_Selection_CTRL_SHIFT_A;
    QAction *actionFind_and_Replace_one_word_and_All;
    QAction *actionFind;
    QAction *actionAdd_next_line;
    QAction *actionAdd_previous_line;
    QAction *actionSort_line;
    QAction *actionUnique;
    QAction *actionReverse;
    QWidget *centralWidget;
    QPlainTextEdit *plainTextEdit;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuView;
    QMenu *menuHelp;
    QMenu *menuselection;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *text_editorClass)
    {
        if (text_editorClass->objectName().isEmpty())
            text_editorClass->setObjectName(QString::fromUtf8("text_editorClass"));
        text_editorClass->resize(932, 668);
        actionOpen_project = new QAction(text_editorClass);
        actionOpen_project->setObjectName(QString::fromUtf8("actionOpen_project"));
        actionNew_project = new QAction(text_editorClass);
        actionNew_project->setObjectName(QString::fromUtf8("actionNew_project"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../../Desktop/download.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew_project->setIcon(icon);
        actionSave_As = new QAction(text_editorClass);
        actionSave_As->setObjectName(QString::fromUtf8("actionSave_As"));
        actionExit = new QAction(text_editorClass);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionUn_do = new QAction(text_editorClass);
        actionUn_do->setObjectName(QString::fromUtf8("actionUn_do"));
        actionRedo = new QAction(text_editorClass);
        actionRedo->setObjectName(QString::fromUtf8("actionRedo"));
        actionFonts = new QAction(text_editorClass);
        actionFonts->setObjectName(QString::fromUtf8("actionFonts"));
        actionSplit_view = new QAction(text_editorClass);
        actionSplit_view->setObjectName(QString::fromUtf8("actionSplit_view"));
        actionCopy = new QAction(text_editorClass);
        actionCopy->setObjectName(QString::fromUtf8("actionCopy"));
        actionPaste = new QAction(text_editorClass);
        actionPaste->setObjectName(QString::fromUtf8("actionPaste"));
        actionSave = new QAction(text_editorClass);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionPrint = new QAction(text_editorClass);
        actionPrint->setObjectName(QString::fromUtf8("actionPrint"));
        actionNew_window = new QAction(text_editorClass);
        actionNew_window->setObjectName(QString::fromUtf8("actionNew_window"));
        actionClose_window = new QAction(text_editorClass);
        actionClose_window->setObjectName(QString::fromUtf8("actionClose_window"));
        actionThemes = new QAction(text_editorClass);
        actionThemes->setObjectName(QString::fromUtf8("actionThemes"));
        action_7 = new QAction(text_editorClass);
        action_7->setObjectName(QString::fromUtf8("action_7"));
        actionHide_minimap = new QAction(text_editorClass);
        actionHide_minimap->setObjectName(QString::fromUtf8("actionHide_minimap"));
        actionHide_slidebar = new QAction(text_editorClass);
        actionHide_slidebar->setObjectName(QString::fromUtf8("actionHide_slidebar"));
        actionOptions = new QAction(text_editorClass);
        actionOptions->setObjectName(QString::fromUtf8("actionOptions"));
        actioncreated_by_kings_ayman_ahmad = new QAction(text_editorClass);
        actioncreated_by_kings_ayman_ahmad->setObjectName(QString::fromUtf8("actioncreated_by_kings_ayman_ahmad"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../../../../Desktop/a1098195070343.Y3JvcCw0MDQsMzE2LDIzMiw0MzM.png"), QSize(), QIcon::Normal, QIcon::Off);
        actioncreated_by_kings_ayman_ahmad->setIcon(icon1);
        actionSelect_All_Ctrl_A = new QAction(text_editorClass);
        actionSelect_All_Ctrl_A->setObjectName(QString::fromUtf8("actionSelect_All_Ctrl_A"));
        actionExpand_Selection_CTRL_SHIFT_A = new QAction(text_editorClass);
        actionExpand_Selection_CTRL_SHIFT_A->setObjectName(QString::fromUtf8("actionExpand_Selection_CTRL_SHIFT_A"));
        actionFind_and_Replace_one_word_and_All = new QAction(text_editorClass);
        actionFind_and_Replace_one_word_and_All->setObjectName(QString::fromUtf8("actionFind_and_Replace_one_word_and_All"));
        actionFind = new QAction(text_editorClass);
        actionFind->setObjectName(QString::fromUtf8("actionFind"));
        actionAdd_next_line = new QAction(text_editorClass);
        actionAdd_next_line->setObjectName(QString::fromUtf8("actionAdd_next_line"));
        actionAdd_previous_line = new QAction(text_editorClass);
        actionAdd_previous_line->setObjectName(QString::fromUtf8("actionAdd_previous_line"));
        actionSort_line = new QAction(text_editorClass);
        actionSort_line->setObjectName(QString::fromUtf8("actionSort_line"));
        actionUnique = new QAction(text_editorClass);
        actionUnique->setObjectName(QString::fromUtf8("actionUnique"));
        actionReverse = new QAction(text_editorClass);
        actionReverse->setObjectName(QString::fromUtf8("actionReverse"));
        centralWidget = new QWidget(text_editorClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        plainTextEdit = new QPlainTextEdit(centralWidget);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(0, -10, 941, 631));
        text_editorClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(text_editorClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 932, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        menuselection = new QMenu(menuBar);
        menuselection->setObjectName(QString::fromUtf8("menuselection"));
        text_editorClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(text_editorClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        text_editorClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(text_editorClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        text_editorClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuBar->addAction(menuselection->menuAction());
        menuFile->addAction(actionNew_project);
        menuFile->addAction(actionOpen_project);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_As);
        menuFile->addAction(actionPrint);
        menuFile->addSeparator();
        menuFile->addAction(actionNew_window);
        menuFile->addAction(actionClose_window);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuFile->addSeparator();
        menuEdit->addAction(actionUn_do);
        menuEdit->addAction(actionRedo);
        menuEdit->addSeparator();
        menuEdit->addAction(actionCopy);
        menuEdit->addAction(actionPaste);
        menuEdit->addSeparator();
        menuEdit->addAction(actionSplit_view);
        menuEdit->addSeparator();
        menuEdit->addAction(actionSort_line);
        menuEdit->addAction(actionUnique);
        menuEdit->addAction(actionReverse);
        menuEdit->addSeparator();
        menuView->addSeparator();
        menuView->addAction(actionHide_minimap);
        menuView->addAction(actionHide_slidebar);
        menuView->addSeparator();
        menuView->addAction(actionOptions);
        menuHelp->addAction(actioncreated_by_kings_ayman_ahmad);
        menuselection->addAction(actionSelect_All_Ctrl_A);
        menuselection->addAction(actionExpand_Selection_CTRL_SHIFT_A);
        menuselection->addSeparator();
        menuselection->addAction(actionFind);
        menuselection->addAction(actionFind_and_Replace_one_word_and_All);
        menuselection->addSeparator();
        menuselection->addAction(actionAdd_next_line);
        menuselection->addAction(actionAdd_previous_line);

        retranslateUi(text_editorClass);

        QMetaObject::connectSlotsByName(text_editorClass);
    } // setupUi

    void retranslateUi(QMainWindow *text_editorClass)
    {
        text_editorClass->setWindowTitle(QCoreApplication::translate("text_editorClass", "text_editor", nullptr));
        actionOpen_project->setText(QCoreApplication::translate("text_editorClass", "Open project", nullptr));
        actionNew_project->setText(QCoreApplication::translate("text_editorClass", " New project", nullptr));
        actionSave_As->setText(QCoreApplication::translate("text_editorClass", "Save As", nullptr));
        actionExit->setText(QCoreApplication::translate("text_editorClass", "Exit", nullptr));
        actionUn_do->setText(QCoreApplication::translate("text_editorClass", "Undo ", nullptr));
        actionRedo->setText(QCoreApplication::translate("text_editorClass", "Redo", nullptr));
        actionFonts->setText(QCoreApplication::translate("text_editorClass", "Fonts", nullptr));
        actionSplit_view->setText(QCoreApplication::translate("text_editorClass", "Split view", nullptr));
        actionCopy->setText(QCoreApplication::translate("text_editorClass", "Copy        Ctrl+C", nullptr));
        actionPaste->setText(QCoreApplication::translate("text_editorClass", "Paste        Ctrl+V", nullptr));
        actionSave->setText(QCoreApplication::translate("text_editorClass", "Save", nullptr));
        actionPrint->setText(QCoreApplication::translate("text_editorClass", "Print", nullptr));
        actionNew_window->setText(QCoreApplication::translate("text_editorClass", "New window", nullptr));
        actionClose_window->setText(QCoreApplication::translate("text_editorClass", "Close window", nullptr));
        actionThemes->setText(QCoreApplication::translate("text_editorClass", "Themes", nullptr));
        action_7->setText(QCoreApplication::translate("text_editorClass", "Options", nullptr));
        actionHide_minimap->setText(QCoreApplication::translate("text_editorClass", "Hide minimap", nullptr));
        actionHide_slidebar->setText(QCoreApplication::translate("text_editorClass", "Hide slidebar", nullptr));
        actionOptions->setText(QCoreApplication::translate("text_editorClass", "Options", nullptr));
        actioncreated_by_kings_ayman_ahmad->setText(QCoreApplication::translate("text_editorClass", "created by kings : ayman/ahmad", nullptr));
        actionSelect_All_Ctrl_A->setText(QCoreApplication::translate("text_editorClass", "Select All                    Ctrl+A", nullptr));
        actionExpand_Selection_CTRL_SHIFT_A->setText(QCoreApplication::translate("text_editorClass", "Expand Selection      Ctrl+Shift+A", nullptr));
        actionFind_and_Replace_one_word_and_All->setText(QCoreApplication::translate("text_editorClass", "Find and Replace (one word and All)", nullptr));
        actionFind->setText(QCoreApplication::translate("text_editorClass", "Find", nullptr));
        actionAdd_next_line->setText(QCoreApplication::translate("text_editorClass", "Add next line               Ctrl+Alt+Up", nullptr));
        actionAdd_previous_line->setText(QCoreApplication::translate("text_editorClass", "Add previous line        Ctrl+Alt+Up", nullptr));
        actionSort_line->setText(QCoreApplication::translate("text_editorClass", "Sort line", nullptr));
        actionUnique->setText(QCoreApplication::translate("text_editorClass", "Unique", nullptr));
        actionReverse->setText(QCoreApplication::translate("text_editorClass", "Reverse", nullptr));
        menuFile->setTitle(QCoreApplication::translate("text_editorClass", "File", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("text_editorClass", "Edit", nullptr));
        menuView->setTitle(QCoreApplication::translate("text_editorClass", "View", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("text_editorClass", "Help", nullptr));
        menuselection->setTitle(QCoreApplication::translate("text_editorClass", "Selection", nullptr));
    } // retranslateUi

};

namespace Ui {
    class text_editorClass: public Ui_text_editorClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEXT_EDITOR_H
