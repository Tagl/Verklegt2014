#pragma once

#include <QDialog>
#include "Mainwindow.h"

namespace Ui {
class AddComputerDialog;
}

class AddComputerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddComputerDialog(MainWindow *parent = 0);
    ~AddComputerDialog();

private slots:
    void on_buttonBox_accepted();

    void on_wasMade_stateChanged(int arg1);

private:
    Ui::AddComputerDialog *ui;
    MainWindow* main;
};
