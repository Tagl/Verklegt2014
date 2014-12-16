#include "AddScientistDialog.h"
#include "ui_AddScientistDialog.h"
#include "mainwindow.h"
#include <qDebug>

AddScientistDialog::AddScientistDialog(MainWindow *parent) :
    QDialog(parent),
    main(parent),
    ui(new Ui::AddScientistDialog)
{
    ui->setupUi(this);
    ui->DoB->setMinimumDate(QDate(100,1,1));
    ui->DoD->setMinimumDate(QDate(100,1,1));
}

AddScientistDialog::~AddScientistDialog()
{
    delete ui;
}

void AddScientistDialog::on_isAlive_stateChanged(int arg1)
{
    ui->DoD->setEnabled(!arg1);
}

void AddScientistDialog::on_buttonBox_accepted()
{
    Person p;
    p.firstname = ui->FirstName->text().toStdString();
    p.surname = ui->SurName->text().toStdString();
    p.gender = ui->Gender->currentText() == "Male" ? MALE : FEMALE;
    p.dob = Date(ui->DoB->date());
    p.dod = ui->isAlive->checkState() == Qt::Checked ? Date() : Date(ui->DoD->date());
    p.description = ui->Description->toPlainText().toStdString();
    main->personService.add(p);
}
