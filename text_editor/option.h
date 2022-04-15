#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_option.h"

class option : public QMainWindow
{
    Q_OBJECT

public:
    option(QWidget* parent = Q_NULLPTR);

private:
    Ui::Form ui;
};
