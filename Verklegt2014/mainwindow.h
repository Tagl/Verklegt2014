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

private:
    Ui::MainWindow *ui;
    Database db;

    void displayScientists();
    void displayComputers();
};
