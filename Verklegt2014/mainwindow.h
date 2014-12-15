#pragma once

#include <QMainWindow>
#include "PersonService.h"
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



private slots:

private:
    Ui::MainWindow *ui;
    Database db;
    PersonService pserv;

    void displayScientists();
    void displayComputers();
};
