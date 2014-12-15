#include "AddComputerDialog.h"
#include "ui_AddComputerDialog.h"
#include <qDebug>

AddComputerDialog::AddComputerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddComputerDialog)
{
    ui->setupUi(this);
}

AddComputerDialog::~AddComputerDialog()
{
    delete ui;
}

void AddComputerDialog::on_Name_textChanged(const QString &arg1)
{
    qDebug() << ui->Name->text();
    // test lala
}

void AddComputerDialog::on_ComputerType_textChanged(const QString &arg1)
{
    qDebug() << ui->ComputerType->text();
}

void AddComputerDialog::on_Description_textChanged(const QString &arg1)
{
    qDebug() << ui->Description->text();
}
