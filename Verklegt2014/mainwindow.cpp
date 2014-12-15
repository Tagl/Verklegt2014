#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "PersonService.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_scientistSearch_textChanged(const QString &arg1)
{

}

void MainWindow::displayComputers()
{

}

void MainWindow::displayScientists()
{
    PersonService serv;
    ui->scientistTable->clear();
    std::vector<Person> people = serv.getPeople();
    ui->scientistTable->setRowCount(people.size());
    for(int i = 0; i < people.size(); i++)
    {
        Person p = people.at(i);
        QString scientistFirst = QString::fromStdString(p.firstname);
        QString scientistSurname = QString::fromStdString(p.surname);
        QString scientistGender = p.gender == MALE ? "Male" : "Female";
    }
}
