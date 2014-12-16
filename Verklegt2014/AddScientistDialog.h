#pragma once

#include <QDialog>

namespace Ui {
class AddScientistDialog;
}

class AddScientistDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddScientistDialog(QWidget *parent = 0);
    ~AddScientistDialog();

private slots:
    void on_FirstName_textChanged(const QString &arg1);

    void on_SurName_textChanged(const QString &arg1);

    void on_Description_textChanged(const QString &arg1);

private:
    Ui::AddScientistDialog *ui;
};
