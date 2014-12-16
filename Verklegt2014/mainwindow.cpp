#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    displayScientists();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_searchScientist_textChanged(const QString &arg1)
{
    pserv.setQuery(arg1.toStdString());
    displayScientists();
}

void MainWindow::displayComputers()
{

}

void MainWindow::displayScientists()
{
    std::vector<Person> people = pserv.getPeople();

    ui->scientistTable->setRowCount(people.size());

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
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    if(index == 0) displayScientists();
    else if (index == -1) displayComputers();
}
