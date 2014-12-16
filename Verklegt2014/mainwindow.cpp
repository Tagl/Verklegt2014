#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "AddScientistDialog.h"
#include "AddComputerDialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    displayScientists();
    displayComputers();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_searchScientist_textChanged(const QString &arg1)
{
    personService.setQuery(arg1.toStdString());
    displayScientists();
}

void MainWindow::displayComputers()
{
    ui->computerTable->setSortingEnabled(false);
    std::vector<Computer> comp = computerService.getComputers();

    ui->computerTable->setRowCount(comp.size());
    auto order = ui->computerTable->horizontalHeader()->sortIndicatorOrder();
    auto column = ui->computerTable->horizontalHeader()->sortIndicatorOrder();
    for(size_t i = 0; i < comp.size(); i++)
    {
        Computer c = comp.at(i);
        QString cId = QString::number(c.id);
        QString cName = QString::fromStdString(c.name);
        QString cType = QString::fromStdString(c.computerType);
        QString cMade = c.wasMade == YES ? "Yes" : "No";
        QString cYear = c.wasMade == NO ? "Never" : QString::number(c.yearBuilt);
        QString cDesc = QString::fromStdString(c.description);

        ui->computerTable->setItem(i,0,new QTableWidgetItem(cId));
        ui->computerTable->setItem(i,1,new QTableWidgetItem(cName));
        ui->computerTable->setItem(i,2,new QTableWidgetItem(cType));
        ui->computerTable->setItem(i,3,new QTableWidgetItem(cMade));
        ui->computerTable->setItem(i,4,new QTableWidgetItem(cYear));
        ui->computerTable->setItem(i,5,new QTableWidgetItem(cDesc));
    }

    ui->computerTable->setSortingEnabled(true);
    ui->computerTable->sortByColumn(order, column);
}

void MainWindow::displayScientists()
{
    ui->scientistTable->setSortingEnabled(false);
    std::vector<Person> people = personService.getPeople();

    ui->scientistTable->setRowCount(people.size());
    auto order = ui->scientistTable->horizontalHeader()->sortIndicatorOrder();
    auto column = ui->scientistTable->horizontalHeader()->sortIndicatorOrder();
    for(size_t i = 0; i < people.size(); i++)
    {
        Person p = people.at(i);
        QString sId = QString::number(p.id);
        QString sFirstName = QString::fromStdString(p.firstname);
        QString sSurname = QString::fromStdString(p.surname);
        QString sGender = p.gender == MALE ? "Male" : "Female";
        QString sDoB = p.dob.toQDate().toString("dd/MM/yyyy");
        QString sDoD = p.dod == Date() ? "Alive" : p.dod.toQDate().toString("dd/MM/yyyy");
        QString sDesc = QString::fromStdString(p.description);

        ui->scientistTable->setItem(i,0,new QTableWidgetItem(sId));
        ui->scientistTable->setItem(i,1,new QTableWidgetItem(sFirstName));
        ui->scientistTable->setItem(i,2,new QTableWidgetItem(sSurname));
        ui->scientistTable->setItem(i,3,new QTableWidgetItem(sGender));
        ui->scientistTable->setItem(i,4,new QTableWidgetItem(sDoB));
        ui->scientistTable->setItem(i,5,new QTableWidgetItem(sDoD));
        ui->scientistTable->setItem(i,6,new QTableWidgetItem(sDesc));
    }

    ui->scientistTable->setSortingEnabled(true);
    ui->scientistTable->sortByColumn(order, column);
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    if(index == 0) displayScientists();
    else if (index == 1) displayComputers();
}

void MainWindow::on_addScientist_clicked()
{
    AddScientistDialog a(this);
    a.setModal(true);
    a.exec();
    displayScientists();
}

void MainWindow::on_removeScientist_clicked()
{
    auto list = ui->scientistTable->selectedItems();
    for(size_t i = 0; i < list.size(); i++)
    {
        QTableWidgetItem* item = list.at(i);
    }
}

void MainWindow::on_AddComputer_clicked()
{
    AddComputerDialog a(this);
    a.setModal(true);
    a.exec();
    displayComputers();
}
