#pragma once

#include <QMainWindow>
#include "PersonService.h"
#include "ComputerService.h"
#include "Database.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


    PersonService personService;
    ComputerService computerService;

private slots:
    void on_searchScientist_textChanged(const QString &arg1);

    void on_tabWidget_currentChanged(int index);

    void on_addScientist_clicked();

    void on_removeScientist_clicked();

    void on_AddComputer_clicked();

    void on_RemoveComputer_clicked();

    void on_scientistTable_clicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    Database db;
    int selectedScientist, selectedComputer;
    void displayScientists();
    void displayComputers();
    void displayConnectedComputers();
    void displayDisconnectedComputers();
};
