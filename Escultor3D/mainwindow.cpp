#include <QString>
#include <QProcess>
#include <QtDebug>
#include <QMessageBox>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sculptor.h"
#include "plotter.h"
#include "dialogsize.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->horizontalSliderX->setMaximum(ui->widgetPlotter->scpSizeX-1);
    ui->horizontalSliderY->setMaximum(ui->widgetPlotter->scpSizeY-1);
    ui->horizontalSliderZ->setMaximum(ui->widgetPlotter->scpSizeZ-1);
    ui->horizontalSliderRD->setMaximum(ui->widgetPlotter->scpSizeX/2 -1);
    ui->horizontalSliderRX->setMaximum(ui->widgetPlotter->scpSizeX/2 -1);
    ui->horizontalSliderRY->setMaximum(ui->widgetPlotter->scpSizeY/2 -1);
    ui->horizontalSliderRZ->setMaximum(ui->widgetPlotter->scpSizeZ/2 -1);

    ui->horizontalSliderRed->setMaximum(255);
    ui->horizontalSliderGreen->setMaximum(255);
    ui->horizontalSliderBlue->setMaximum(255);
    ui->horizontalSliderAlpha->setMaximum(255);
    ui->horizontalSliderSlice->setMaximum(ui->widgetPlotter->scpSizeZ -1);

    //////////////////////////////////
    connect(ui->pushButtonPV,
            SIGNAL(clicked(bool)),
            this,
            SLOT(changeShape1()));

    connect(ui->pushButtonCV,
            SIGNAL(clicked(bool)),
            this,
            SLOT(changeShape2()));

    connect(ui->pushButtonPB,
            SIGNAL(clicked(bool)),
            this,
            SLOT(changeShape3()));

    connect(ui->pushButtonCB,
            SIGNAL(clicked(bool)),
            this,
            SLOT(changeShape4()));

    connect(ui->pushButtonPS,
            SIGNAL(clicked(bool)),
            this,
            SLOT(changeShape5()));

    connect(ui->pushButtonCS,
            SIGNAL(clicked(bool)),
            this,
            SLOT(changeShape6()));

    connect(ui->pushButtonPE,
            SIGNAL(clicked(bool)),
            this,
            SLOT(changeShape7()));

    connect(ui->pushButtonCE,
            SIGNAL(clicked(bool)),
            this,
            SLOT(changeShape8()));

    connect(ui->pushButtonXY,
            SIGNAL(clicked(bool)),
            this,
            SLOT(changePlane1()));

    connect(ui->pushButtonXZ,
            SIGNAL(clicked(bool)),
            this,
            SLOT(changePlane2()));

    connect(ui->pushButtonYZ,
            SIGNAL(clicked(bool)),
            this,
            SLOT(changePlane3()));

    ///////////////////////////////////////////

    connect(ui->horizontalSliderX,
            SIGNAL(valueChanged(int)),
            ui->widgetPlotter,
            SLOT(changeSizeX(int)));

    connect(ui->horizontalSliderY,
            SIGNAL(valueChanged(int)),
            ui->widgetPlotter,
            SLOT(changeSizeY(int)));

    connect(ui->horizontalSliderZ,
            SIGNAL(valueChanged(int)),
            ui->widgetPlotter,
            SLOT(changeSizeZ(int)));

    connect(ui->horizontalSliderRD,
            SIGNAL(valueChanged(int)),
            ui->widgetPlotter,
            SLOT(changeRadius(int)));

    connect(ui->horizontalSliderRX,
            SIGNAL(valueChanged(int)),
            ui->widgetPlotter,
            SLOT(changeRadiusX(int)));

    connect(ui->horizontalSliderRY,
            SIGNAL(valueChanged(int)),
            ui->widgetPlotter,
            SLOT(changeRadiusY(int)));

    connect(ui->horizontalSliderRZ,
            SIGNAL(valueChanged(int)),
            ui->widgetPlotter,
            SLOT(changeRadiusZ(int)));

    connect(ui->horizontalSliderRed,
            SIGNAL(valueChanged(int)),
            ui->widgetPlotter,
            SLOT(changeRed(int)));

    connect(ui->horizontalSliderGreen,
            SIGNAL(valueChanged(int)),
            ui->widgetPlotter,
            SLOT(changeGreen(int)));

    connect(ui->horizontalSliderBlue,
            SIGNAL(valueChanged(int)),
            ui->widgetPlotter,
            SLOT(changeBlue(int)));

    connect(ui->horizontalSliderAlpha,
            SIGNAL(valueChanged(int)),
            ui->widgetPlotter,
            SLOT(changeAlpha(int)));

    connect(ui->horizontalSliderSlice,
            SIGNAL(valueChanged(int)),
            ui->widgetPlotter,
            SLOT(changeSlice(int)));

   /////////////////////////////////////////////

    connect(ui->widgetPlotter,
            SIGNAL(clickX(int)),
            ui->lcdNumberX,
            SLOT(display(int)));

    connect(ui->widgetPlotter,
            SIGNAL(clickY(int)),
            ui->lcdNumberY,
            SLOT(display(int)));

    connect(ui->widgetPlotter,
            SIGNAL(mouseLinha(int)),
            ui->lcdNumberLinha,
            SLOT(display(int)));

    connect(ui->widgetPlotter,
            SIGNAL(mouseColuna(int)),
            ui->lcdNumberColuna,
            SLOT(display(int)));
/////////////////////////////////////////

    connect(ui->pushButtonOFF,
            SIGNAL(clicked(bool)),
            this,
            SLOT(saveOFF()));

    connect(ui->pushButtonVECT,
            SIGNAL(clicked(bool)),
            this,
            SLOT(saveVECT()));

    connect(ui->pushButtonSV,
            SIGNAL(clicked(bool)),
            this,
            SLOT(saveAll()));

    ///////////////////////////////////

    connect(ui->horizontalSliderRed,
            SIGNAL(valueChanged(int)),
            ui->widgetColor,
            SLOT(changeRed2(int)));

    connect(ui->horizontalSliderGreen,
            SIGNAL(valueChanged(int)),
            ui->widgetColor,
            SLOT(changeGreen2(int)));

    connect(ui->horizontalSliderBlue,
            SIGNAL(valueChanged(int)),
            ui->widgetColor,
            SLOT(changeBlue2(int)));

    connect(ui->horizontalSliderAlpha,
            SIGNAL(valueChanged(int)),
            ui->widgetColor,
            SLOT(changeAlpha2(int)));
///////////////////////////////////////

    connect(ui->pushButtonRotClk,
            SIGNAL(clicked(bool)),
            this,
            SLOT(rotClockWise()));

    connect(ui->pushButtonRotCClk,
            SIGNAL(clicked(bool)),
            this,
            SLOT(rotCClockWise()));

    connect(ui->pushButtonInv,
            SIGNAL(clicked(bool)),
            this,
            SLOT(inverter()));

    connect(ui->pushButtonNewSz,
            SIGNAL(clicked(bool)),
            this,
            SLOT(newSize()));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changePlane1() //XY
{
    ui->widgetPlotter->plane = 1;
    emit ui->widgetPlotter->planeChosen(1);
    ui->widgetPlotter->slice = ui->widgetPlotter->scpSizeZ/2;
    ui->horizontalSliderSlice->setMaximum(ui->widgetPlotter->scpSizeZ -1);
    ui->widgetPlotter->repaint();

}
void MainWindow::changePlane2() //XZ
{
    ui->widgetPlotter->plane = 2;
    emit ui->widgetPlotter->planeChosen(2);
    ui->horizontalSliderSlice->setMaximum(ui->widgetPlotter->scpSizeY -1);
    ui->widgetPlotter->slice = ui->widgetPlotter->scpSizeY/2;
    ui->widgetPlotter->repaint();
}
void MainWindow::changePlane3() //YZ
{
    ui->widgetPlotter->plane = 3;
    emit ui->widgetPlotter->planeChosen(3);    
    ui->horizontalSliderSlice->setMaximum(ui->widgetPlotter->scpSizeX -1);
    ui->widgetPlotter->slice = ui->widgetPlotter->scpSizeX/2;
    ui->widgetPlotter->repaint();
}

void MainWindow::changeShape1() //PV
{
    ui->widgetPlotter->shape = 1;
}
void MainWindow::changeShape2() //CV
{
    ui->widgetPlotter->shape = 2;
}
void MainWindow::changeShape3() //PB
{
    ui->widgetPlotter->shape = 3;
}
void MainWindow::changeShape4() //CB
{
    ui->widgetPlotter->shape = 4;
}
void MainWindow::changeShape5() //PS
{
    ui->widgetPlotter->shape = 5;
}
void MainWindow::changeShape6() //CS
{
    ui->widgetPlotter->shape = 6;
}
void MainWindow::changeShape7() //PE
{
    ui->widgetPlotter->shape = 7;
}
void MainWindow::changeShape8() //PS
{
    ui->widgetPlotter->shape = 8;
}

void MainWindow::rotClockWise()
{
    switch(ui->widgetPlotter->plane){
    case 1: //XY1
        ui->widgetPlotter->plane = 4;
    break;
    case 2: //ZX1
        ui->widgetPlotter->plane = 5;
    break;
    case 3: //YZ1
        ui->widgetPlotter->plane = 6;
    break;
    case 4: //XY2
        ui->widgetPlotter->plane = 7;
    break;
    case 5: //ZX2
        ui->widgetPlotter->plane = 8;
    break;
    case 6: //YZ2
        ui->widgetPlotter->plane = 9;
    break;
    case 7:
        ui->widgetPlotter->plane = 10;
    break;
    case 8:
        ui->widgetPlotter->plane = 11;
    break;
    case 9:
        ui->widgetPlotter->plane = 12;
    break;
    case 10:
        ui->widgetPlotter->plane = 1;
    break;
    case 11:
        ui->widgetPlotter->plane = 2;
    break;
    case 12:
        ui->widgetPlotter->plane = 3;
    break;


    case 13:
        ui->widgetPlotter->plane = 16;
    break;
    case 14:
        ui->widgetPlotter->plane = 17;
    break;
    case 15:
        ui->widgetPlotter->plane = 18;
    break;
    case 16:
        ui->widgetPlotter->plane = 19;
    break;
    case 17:
        ui->widgetPlotter->plane = 20;
    break;
    case 18:
        ui->widgetPlotter->plane = 21;
    break;
    case 19:
        ui->widgetPlotter->plane = 22;
    break;
    case 20:
        ui->widgetPlotter->plane = 23;
    break;
    case 21:
        ui->widgetPlotter->plane = 24;
    break;
    case 22:
        ui->widgetPlotter->plane = 13;
    break;
    case 23:
        ui->widgetPlotter->plane = 14;
    break;
    case 24:
        ui->widgetPlotter->plane = 15;
    break;
    }
    ui->widgetPlotter->repaint();
}
void MainWindow::rotCClockWise()
{
    switch(ui->widgetPlotter->plane){
    case 1: //XY1
        ui->widgetPlotter->plane = 10;
    break;
    case 2: //ZX1
        ui->widgetPlotter->plane = 11;
    break;
    case 3: //YZ1
        ui->widgetPlotter->plane = 12;
    break;
    case 4: //XY2
        ui->widgetPlotter->plane = 1;
    break;
    case 5: //ZX2
        ui->widgetPlotter->plane = 2;
    break;
    case 6: //YZ2
        ui->widgetPlotter->plane = 3;
    break;
    case 7:
        ui->widgetPlotter->plane = 4;
    break;
    case 8:
        ui->widgetPlotter->plane = 5;
    break;
    case 9:
        ui->widgetPlotter->plane = 6;
    break;
    case 10:
        ui->widgetPlotter->plane = 7;
    break;
    case 11:
        ui->widgetPlotter->plane = 8;
    break;
    case 12:
        ui->widgetPlotter->plane = 9;
    break;


    case 13:
        ui->widgetPlotter->plane = 22;
    break;
    case 14:
        ui->widgetPlotter->plane = 23;
    break;
    case 15:
        ui->widgetPlotter->plane = 24;
    break;
    case 16:
        ui->widgetPlotter->plane = 13;
    break;
    case 17:
        ui->widgetPlotter->plane = 14;
    break;
    case 18:
        ui->widgetPlotter->plane = 15;
    break;
    case 19:
        ui->widgetPlotter->plane = 16;
    break;
    case 20:
        ui->widgetPlotter->plane = 17;
    break;
    case 21:
        ui->widgetPlotter->plane = 18;
    break;
    case 22:
        ui->widgetPlotter->plane = 19;
    break;
    case 23:
        ui->widgetPlotter->plane = 20;
    break;
    case 24:
        ui->widgetPlotter->plane = 21;
    break;
    }

    ui->widgetPlotter->repaint();
}
void MainWindow::inverter()
{
    switch(ui->widgetPlotter->plane){
    case 1: //XY1
        ui->widgetPlotter->plane = 13;
    break;
    case 2: //ZX1
        ui->widgetPlotter->plane = 14;
    break;
    case 3: //YZ1
        ui->widgetPlotter->plane = 15;
    break;
    case 4: //XY2
        ui->widgetPlotter->plane = 16;
    break;
    case 5: //ZX2
        ui->widgetPlotter->plane = 17;
    break;
    case 6: //YZ2
        ui->widgetPlotter->plane = 18;
    break;
    case 7:
        ui->widgetPlotter->plane = 19;
    break;
    case 8:
        ui->widgetPlotter->plane = 20;
    break;
    case 9:
        ui->widgetPlotter->plane = 21;
    break;
    case 10:
        ui->widgetPlotter->plane = 22;
    break;
    case 11:
        ui->widgetPlotter->plane = 23;
    break;
    case 12:
        ui->widgetPlotter->plane = 24;
    break;


    case 13:
        ui->widgetPlotter->plane = 1;
    break;
    case 14:
        ui->widgetPlotter->plane = 2;
    break;
    case 15:
        ui->widgetPlotter->plane = 3;
    break;
    case 16:
        ui->widgetPlotter->plane = 4;
    break;
    case 17:
        ui->widgetPlotter->plane = 5;
    break;
    case 18:
        ui->widgetPlotter->plane = 6;
    break;
    case 19:
        ui->widgetPlotter->plane = 7;
    break;
    case 20:
        ui->widgetPlotter->plane = 8;
    break;
    case 21:
        ui->widgetPlotter->plane = 9;
    break;
    case 22:
        ui->widgetPlotter->plane = 10;
    break;
    case 23:
        ui->widgetPlotter->plane = 11;
    break;
    case 24:
        ui->widgetPlotter->plane = 12;
    break;
    }

    ui->widgetPlotter->repaint();
}

void MainWindow::saveVECT()
{
    ui->widgetPlotter->cube->writeVECT("/tmp/file.vect");


    QProcess *process = new QProcess(this);
    QString program = "/usr/bin/geomview";
    QString path = "/tmp/file.vect";
    QStringList list;
    list << path;
    process->start(program, list);
    process->waitForFinished();
}
void MainWindow::saveOFF()
{
    ui->widgetPlotter->cube->writeOFF("/tmp/file.off");

    QProcess *process = new QProcess(this);
    QString program = "/usr/bin/geomview";
    QString path = "/tmp/file.off";
    QStringList list;
    list << path;
    process->start(program, list);
    process->waitForFinished();
}
void MainWindow::saveAll()
{
    ui->widgetPlotter->cube->writeVECT("/home/lufec/Escultor3D/file.vect");
    ui->widgetPlotter->cube->writeOFF("/home/lufec/Escultor3D/file.off");
}

void MainWindow::newSize()
{
     QMessageBox box;
     QString msg;
     DialogSize dialog;

     if(dialog.exec() == QDialog::Accepted){
       msg = "SizeX= <b>"+QString::number(dialog.getSizeX())+
           "</b> <br>"+
           "SizeY = <b>"+QString::number(dialog.getSizeY())+
           "</b> <br>"+
           "SizeZ = <b>"+QString::number(dialog.getSizeZ())+
           "</b>";
       box.setText(msg);
       box.exec();
     }

    ui->widgetPlotter->cube->~Sculptor();

    ui->widgetPlotter->scpSizeX = dialog.getSizeX();
    ui->widgetPlotter->scpSizeY = dialog.getSizeY();
    ui->widgetPlotter->scpSizeZ = dialog.getSizeZ();

    ui->widgetPlotter->cube = new Sculptor(dialog.getSizeX(),dialog.getSizeY(),dialog.getSizeZ());

    ui->horizontalSliderX->setMaximum(ui->widgetPlotter->scpSizeX-1);
    ui->horizontalSliderY->setMaximum(ui->widgetPlotter->scpSizeY-1);
    ui->horizontalSliderZ->setMaximum(ui->widgetPlotter->scpSizeZ-1);
    ui->horizontalSliderRD->setMaximum(ui->widgetPlotter->scpSizeX/2 -1);
    ui->horizontalSliderRX->setMaximum(ui->widgetPlotter->scpSizeX/2 -1);
    ui->horizontalSliderRY->setMaximum(ui->widgetPlotter->scpSizeY/2 -1);
    ui->horizontalSliderRZ->setMaximum(ui->widgetPlotter->scpSizeZ/2 -1);
    ui->horizontalSliderSlice->setMaximum(ui->widgetPlotter->scpSizeZ -1);
    ui->widgetPlotter->slice = 0;


    ui->widgetPlotter->repaint();

}
