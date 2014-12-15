#pragma once

#include <QMainWindow>

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
    void on_scientistSearch_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    void displayScientists();
    void displayComputers();
};
