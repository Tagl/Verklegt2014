#pragma once

#include <QMainWindow>
#include "PersonService.h"
#include "ComputerService.h"
#include "RelationService.h"
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
    RelationService relationService;

private slots:
    void on_searchScientist_textChanged(const QString &arg1);

    void on_tabWidget_currentChanged(int index);

    void on_addScientist_clicked();

    void on_removeScientist_clicked();

    void on_AddComputer_clicked();

    void on_RemoveComputer_clicked();

    void on_scientistTable_clicked(const QModelIndex &index);

    void on_connectToComputer_clicked();

    void on_disconnectComputer_clicked();

    void on_computerTable_clicked(const QModelIndex &index);

    void on_connectScientist_clicked();

    void on_disconnectScientist_clicked();

    void on_scientistTable_cellChanged(int row, int column);

    void on_computerTable_cellChanged(int row, int column);

private:
    Ui::MainWindow *ui;
    Database db;
    int selectedScientist, selectedComputer;
    bool userEditing;
    void displayScientists();
    void displayComputers();
    void displayConnectedComputers();
    void displayDisconnectedComputers();
    void displayConnectedScientists();
    void displayDisconnectedScientists();
};
