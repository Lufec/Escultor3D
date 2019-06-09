#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sculptor.h"
#include "plotter.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->horizontalSliderX->setMaximum(ui->widgetPlotter->scpSizeX);
    ui->horizontalSliderY->setMaximum(ui->widgetPlotter->scpSizeY);
    ui->horizontalSliderZ->setMaximum(ui->widgetPlotter->scpSizeZ);
    ui->horizontalSliderRD->setMaximum(ui->widgetPlotter->scpSizeX/2);
    ui->horizontalSliderRX->setMaximum(ui->widgetPlotter->scpSizeX/2);
    ui->horizontalSliderRY->setMaximum(ui->widgetPlotter->scpSizeY/2);
    ui->horizontalSliderRZ->setMaximum(ui->widgetPlotter->scpSizeZ/2);
    ui->horizontalSliderRed->setMaximum(255);
    ui->horizontalSliderGreen->setMaximum(255);
    ui->horizontalSliderBlue->setMaximum(255);
    ui->horizontalSliderAlpha->setMaximum(255);
    ui->horizontalSliderSlice->setMaximum(ui->widgetPlotter->scpSizeZ);

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


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changePlane1() //XY
{
    ui->widgetPlotter->plane = 1;
    emit ui->widgetPlotter->planeChosen(1);
}
void MainWindow::changePlane2() //XZ
{
    ui->widgetPlotter->plane = 2;
    emit ui->widgetPlotter->planeChosen(2);
}
void MainWindow::changePlane3() //YZ
{
    ui->widgetPlotter->plane = 3;
    emit ui->widgetPlotter->planeChosen(3);
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


void MainWindow::saveVECT()
{
    ui->widgetPlotter->cube->writeVECT("/home/lufec/Escultor3D/file.vect");
}
void MainWindow::saveOFF()
{
    ui->widgetPlotter->cube->writeOFF("/home/lufec/Escultor3D/file.off");
}
void MainWindow::saveAll()
{
    ui->widgetPlotter->cube->writeVECT("/home/lufec/Escultor3D/file.vect");
    ui->widgetPlotter->cube->writeOFF("/home/lufec/Escultor3D/file.off");
}
