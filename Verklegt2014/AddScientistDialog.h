#pragma once

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class AddScientistDialog;
}

class AddScientistDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddScientistDialog(QWidget *parent = 0);
    ~AddScientistDialog();

    void on_buttonBox_accepted();

    void on_isAlive_stateChanged(int arg1);

private:
    Ui::AddScientistDialog *ui;
};
