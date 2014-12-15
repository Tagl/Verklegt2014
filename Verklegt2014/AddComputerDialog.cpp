#include "AddComputerDialog.h"
#include "ui_AddComputerDialog.h"

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
