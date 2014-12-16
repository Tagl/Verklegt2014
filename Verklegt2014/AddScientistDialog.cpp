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

void AddComputerDialog::on_buttonBox_accepted()
{
    Person p;
    p.firstname = ui->FirstName->text().toStdString();
    p.surname = ui->SurName->text().toStdString();
    p.gender = ui->Gender->currentText() == "Male" ? MALE : FEMALE;
    p.dob = Date(ui->DoB->date());
    p.dod = ui->isAlive->checkState() == Qt::Checked ? Date() : Date(ui->DoD->date());
    p.description = ui->Description->text().toStdString();
    main->personService.add(p);
}

void AddScientistDialog::on_isAlive_stateChanged(int arg1)
{
    ui->DoD->setEnabled(!arg1);
}
