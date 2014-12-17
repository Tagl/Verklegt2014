#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "AddScientistDialog.h"
#include "AddComputerDialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->scientistTable->sortByColumn(0, Qt::AscendingOrder);
    ui->computerTable->sortByColumn(0, Qt::AscendingOrder);

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
    if(index == 0)
    {
        displayScientists();
        displayConnectedComputers();
        displayDisconnectedComputers();
    }
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
    std::vector<int> rows;
    for(int i = 0; i < list.size(); i++)
    {
        QTableWidgetItem* item = list.at(i);
        int row = item->row();
        if(std::find(rows.begin(), rows.end(), row) != rows.end()) continue;
        else rows.push_back(row);
        QTableWidgetItem* id = ui->scientistTable->item(row,0);
        personService.remove(id->text().toInt());
    }
    displayScientists();
}

void MainWindow::on_AddComputer_clicked()
{
    AddComputerDialog a(this);
    a.setModal(true);
    a.exec();
    displayComputers();
}

void MainWindow::on_RemoveComputer_clicked()
{
    auto list = ui->computerTable->selectedItems();
    std::vector<int> rows;
    for(int i = 0; i < list.size(); i++)
    {
        QTableWidgetItem* item = list.at(i);
        int row = item->row();
        if(std::find(rows.begin(), rows.end(), row) != rows.end()) continue; // remove each ID only once to reduce sql queries
        else rows.push_back(row);
        QTableWidgetItem* id = ui->computerTable->item(row,0);
        computerService.remove(id->text().toInt());
    }
    displayComputers();
}

void MainWindow::on_scientistTable_clicked(const QModelIndex &index)
{
    auto list = ui->scientistTable->selectedItems();
    if(list.size() == 0) // nothing selected
    {
        selectedScientist = -1;
    }
    else // we use only the first item
    {
        auto item = ui->scientistTable->item(list.at(0)->row(),0);
        selectedScientist = item->text().toInt();
    }
    displayConnectedComputers();
    displayDisconnectedComputers();
}

void MainWindow::displayConnectedComputers()
{
    ui->connectedComputers->setRowCount(0);
    if(selectedScientist == -1) return;

    ui->connectedComputers->setSortingEnabled(false);
    std::vector<Computer> comp = computerService.getConnected(selectedScientist);

    ui->connectedComputers->setRowCount(comp.size());
    auto order = ui->connectedComputers->horizontalHeader()->sortIndicatorOrder();
    auto column = ui->connectedComputers->horizontalHeader()->sortIndicatorOrder();
    for(size_t i = 0; i < comp.size(); i++)
    {
        Computer c = comp.at(i);
        QString cId = QString::number(c.id);
        QString cName = QString::fromStdString(c.name);

        ui->connectedComputers->setItem(i,0,new QTableWidgetItem(cId));
        ui->connectedComputers->setItem(i,1,new QTableWidgetItem(cName));
    }

    ui->connectedComputers->setSortingEnabled(true);
    ui->connectedComputers->sortByColumn(order, column);
}

void MainWindow::displayDisconnectedComputers()
{
    ui->disconnectedComputers->setRowCount(0);
    if(selectedScientist == -1) return;

    ui->disconnectedComputers->setSortingEnabled(false);
    std::vector<Computer> comp = computerService.getDisconnected(selectedScientist);

    ui->disconnectedComputers->setRowCount(comp.size());
    auto order = ui->disconnectedComputers->horizontalHeader()->sortIndicatorOrder();
    auto column = ui->disconnectedComputers->horizontalHeader()->sortIndicatorOrder();
    for(size_t i = 0; i < comp.size(); i++)
    {
        Computer c = comp.at(i);
        QString cId = QString::number(c.id);
        QString cName = QString::fromStdString(c.name);
        ui->disconnectedComputers->setItem(i,0,new QTableWidgetItem(cId));
        ui->disconnectedComputers->setItem(i,1,new QTableWidgetItem(cName));
    }

    ui->disconnectedComputers->setSortingEnabled(true);
    ui->disconnectedComputers->sortByColumn(order, column);
}


void MainWindow::displayConnectedScientists()
{
    ui->connectedScientists->setRowCount(0);
    if(selectedComputer == -1) return;

    ui->connectedScientists->setSortingEnabled(false);
    std::vector<Person> people = personService.getConnected(selectedComputer);

    ui->connectedScientists->setRowCount(people.size());
    auto order = ui->connectedScientists->horizontalHeader()->sortIndicatorOrder();
    auto column = ui->connectedScientists->horizontalHeader()->sortIndicatorOrder();
    for(size_t i = 0; i < people.size(); i++)
    {
        Person p = people.at(i);
        QString pId = QString::number(p.id);
        QString pFName = QString::fromStdString(p.firstname);
        QString pSName = QString::fromStdString(p.surname);

        ui->connectedScientists->setItem(i,0,new QTableWidgetItem(pId));
        ui->connectedScientists->setItem(i,1,new QTableWidgetItem(pFName));
        ui->connectedScientists->setItem(i,2,new QTableWidgetItem(pSName));
    }

    ui->connectedScientists->setSortingEnabled(true);
    ui->connectedScientists->sortByColumn(order, column);
}

void MainWindow::displayDisconnectedScientists()
{
    ui->disconnectedScientists->setRowCount(0);
    if(selectedComputer == -1) return;

    ui->disconnectedScientists->setSortingEnabled(false);
    std::vector<Person> people = personService.getDisconnected(selectedComputer);

    ui->disconnectedScientists->setRowCount(people.size());
    auto order = ui->disconnectedScientists->horizontalHeader()->sortIndicatorOrder();
    auto column = ui->disconnectedScientists->horizontalHeader()->sortIndicatorOrder();
    for(size_t i = 0; i < people.size(); i++)
    {
        Person p = people.at(i);
        QString pId = QString::number(p.id);
        QString pFName = QString::fromStdString(p.firstname);
        QString pSName = QString::fromStdString(p.surname);

        ui->disconnectedScientists->setItem(i,0,new QTableWidgetItem(pId));
        ui->disconnectedScientists->setItem(i,1,new QTableWidgetItem(pFName));
        ui->disconnectedScientists->setItem(i,2,new QTableWidgetItem(pSName));
    }

    ui->disconnectedScientists->setSortingEnabled(true);
    ui->disconnectedScientists->sortByColumn(order, column);
}

void MainWindow::on_connectToComputer_clicked()
{
    if(selectedScientist == -1) return;

    auto list = ui->disconnectedComputers->selectedItems();
    std::vector<int> rows;
    for(int i = 0; i < list.size(); i++)
    {
        QTableWidgetItem* item = list.at(i);
        int row = item->row();
        if(std::find(rows.begin(), rows.end(), row) != rows.end()) continue; // remove each ID only once to reduce sql queries
        else rows.push_back(row);
        QTableWidgetItem* id = ui->disconnectedComputers->item(row,0);
        relationService.add(selectedScientist,id->text().toInt());
    }

    displayConnectedComputers();
    displayDisconnectedComputers();
}

void MainWindow::on_disconnectComputer_clicked()
{
    if(selectedScientist == -1) return;

    auto list = ui->connectedComputers->selectedItems();
    std::vector<int> rows;
    for(int i = 0; i < list.size(); i++)
    {
        QTableWidgetItem* item = list.at(i);
        int row = item->row();
        if(std::find(rows.begin(), rows.end(), row) != rows.end()) continue; // remove each ID only once to reduce sql queries
        else rows.push_back(row);
        QTableWidgetItem* id = ui->connectedComputers->item(row,0);
        relationService.remove(selectedScientist,id->text().toInt());
    }

    displayConnectedComputers();
    displayDisconnectedComputers();
}

void MainWindow::on_computerTable_clicked(const QModelIndex &index)
{
    auto list = ui->computerTable->selectedItems();
    if(list.size() == 0) // nothing selected
    {
        selectedComputer = -1;
    }
    else // we use only the first item
    {
        auto item = ui->computerTable->item(list.at(0)->row(),0);
        selectedComputer = item->text().toInt();
    }
    displayConnectedScientists();
    displayDisconnectedScientists();
}

void MainWindow::on_connectScientist_clicked()
{
    if(selectedComputer == -1) return;

    auto list = ui->disconnectedScientists->selectedItems();
    std::vector<int> rows;
    for(int i = 0; i < list.size(); i++)
    {
        QTableWidgetItem* item = list.at(i);
        int row = item->row();
        if(std::find(rows.begin(), rows.end(), row) != rows.end()) continue; // remove each ID only once to reduce sql queries
        else rows.push_back(row);
        QTableWidgetItem* id = ui->disconnectedScientists->item(row,0);
        relationService.add(id->text().toInt(),selectedComputer);
    }

    displayConnectedScientists();
    displayDisconnectedScientists();
}

void MainWindow::on_disconnectScientist_clicked()
{
    if(selectedComputer == -1) return;

    auto list = ui->connectedScientists->selectedItems();
    std::vector<int> rows;
    for(int i = 0; i < list.size(); i++)
    {
        QTableWidgetItem* item = list.at(i);
        int row = item->row();
        if(std::find(rows.begin(), rows.end(), row) != rows.end()) continue; // remove each ID only once to reduce sql queries
        else rows.push_back(row);
        QTableWidgetItem* id = ui->connectedScientists->item(row,0);
        relationService.remove(id->text().toInt(),selectedComputer);
    }

    displayConnectedScientists();
    displayDisconnectedScientists();
}
