#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "sculptor.h"
#include "vector"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

public slots:

void changePlane1(); //XY1
void changePlane2(); //ZX1
void changePlane3(); //YZ1
void changeShape1(); //PV
void changeShape2(); //CV
void changeShape3(); //PB
void changeShape4(); //CB
void changeShape5(); //PS
void changeShape6(); //CS
void changeShape7(); //PE
void changeShape8(); //PS
void rotClockWise();
void rotCClockWise();
void inverter();

void saveVECT();
void saveOFF();
void saveAll();

void newSize();

};

#endif // MAINWINDOW_H
