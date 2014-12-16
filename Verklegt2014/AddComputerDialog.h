#pragma once

#include <QDialog>

namespace Ui {
class AddComputerDialog;
}

class AddComputerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddComputerDialog(QWidget *parent = 0);
    ~AddComputerDialog();

private slots:
    void on_Name_textChanged(const QString &arg1);

    void on_ComputerType_textChanged(const QString &arg1);

    void on_Description_textChanged(const QString &arg1);

    void on_buttonBox_accepted();

private:
    Ui::AddComputerDialog *ui;
};
