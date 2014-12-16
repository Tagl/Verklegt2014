#include "AddComputerDialog.h"
#include "ui_AddComputerDialog.h"
#include "mainwindow.h"
#include <qDebug>

AddComputerDialog::AddComputerDialog(MainWindow *parent) :
    QDialog(parent),
    main(parent),
    ui(new Ui::AddComputerDialog)
{
    ui->setupUi(this);
}

AddComputerDialog::~AddComputerDialog()
{
    delete ui;
}


void AddComputerDialog::on_buttonBox_accepted()
{
    Computer c;
    c.name = ui->Name->text().toStdString();
    c.computerType = ui->ComputerType->text().toStdString();
    c.wasMade = ui->wasMade->checkState() == Qt::Checked ? YES : NO;
    c.yearBuilt = ui->yearBuilt->value();
    c.description = ui->Description->toPlainText().toStdString();

    main->computerService.add(c);
}

void AddComputerDialog::on_wasMade_stateChanged(int arg1)
{
    ui->yearBuilt->setEnabled(arg1);
}
