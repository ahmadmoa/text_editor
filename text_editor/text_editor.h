#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_text_editor.h"

class text_editor : public QMainWindow
{
    Q_OBJECT

public:
    text_editor(QWidget *parent = Q_NULLPTR);

private:
    Ui::text_editorClass ui;
};
