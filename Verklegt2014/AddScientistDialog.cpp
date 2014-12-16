#include "AddScientistDialog.h"
#include "ui_AddScientistDialog.h"

AddScientistDialog::AddScientistDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddScientistDialog)
{
    ui->setupUi(this);
}

AddScientistDialog::~AddScientistDialog()
{

    delete ui;
}

void AddScientistDialog::on_FirstName_textChanged(const QString &arg1)
{
    //qDebug() << ui->FirstName->text();

}

void AddScientistDialog::on_SurName_textChanged(const QString &arg1)
{
    //qDebug() << ui->SurName->text();

}

void AddScientistDialog::on_Description_textChanged(const QString &arg1)
{
    //qDebug() << ui->Description->text();

}
