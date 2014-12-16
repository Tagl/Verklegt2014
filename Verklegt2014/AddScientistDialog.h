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
    explicit AddScientistDialog(MainWindow *parent = 0);
    ~AddScientistDialog();

    void on_isAlive_stateChanged(int arg1);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::AddScientistDialog *ui;
    MainWindow* main;
};
