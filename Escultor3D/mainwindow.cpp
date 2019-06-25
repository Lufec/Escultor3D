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
    ui->horizontalSliderRed->setMinimum(1);
    ui->horizontalSliderGreen->setMinimum(1);
    ui->horizontalSliderBlue->setMinimum(1);
    ui->horizontalSliderAlpha->setMinimum(1);
    ui->horizontalSliderRed->setSliderPosition(1);
    ui->horizontalSliderGreen->setSliderPosition(1);
    ui->horizontalSliderBlue->setSliderPosition(1);
    ui->horizontalSliderAlpha->setSliderPosition(1);

    ui->horizontalSliderSlice->setMaximum(ui->widgetPlotter->scpSizeZ -1);

    //////////////////////////////////
    connect(ui->actionPutVoxel,
            SIGNAL(triggered(bool)),
            ui->widgetPlotter,
            SLOT(changeShape1()));

    connect(ui->actionCutVoxel,
            SIGNAL(triggered(bool)),
            ui->widgetPlotter,
            SLOT(changeShape2()));

    connect(ui->actionPutBox,
            SIGNAL(triggered(bool)),
            ui->widgetPlotter,
            SLOT(changeShape3()));

    connect(ui->actionCutBox,
            SIGNAL(triggered(bool)),
            ui->widgetPlotter,
            SLOT(changeShape4()));

    connect(ui->actionPutSphere,
            SIGNAL(triggered(bool)),
            ui->widgetPlotter,
            SLOT(changeShape5()));

    connect(ui->actionCutSphere,
            SIGNAL(triggered(bool)),
            ui->widgetPlotter,
            SLOT(changeShape6()));

    connect(ui->actionPutEllipsoid,
            SIGNAL(triggered(bool)),
            ui->widgetPlotter,
            SLOT(changeShape7()));

    connect(ui->actionCutEllipsoid,
            SIGNAL(triggered(bool)),
            ui->widgetPlotter,
            SLOT(changeShape8()));

    connect(ui->actionXY,
            SIGNAL(triggered(bool)),
            ui->widgetPlotter,
            SLOT(changePlane1()));

    connect(ui->actionZX,
            SIGNAL(triggered(bool)),
            ui->widgetPlotter,
            SLOT(changePlane2()));

    connect(ui->actionYZ,
            SIGNAL(triggered(bool)),
            ui->widgetPlotter,
            SLOT(changePlane3()));

    connect(ui->actionXY,
            SIGNAL(triggered(bool)),
            this,
            SLOT(updateSliceSlider()));

    connect(ui->actionZX,
            SIGNAL(triggered(bool)),
            this,
            SLOT(updateSliceSlider()));

    connect(ui->actionYZ,
            SIGNAL(triggered(bool)),
            this,
            SLOT(updateSliceSlider()));

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
            SIGNAL(mouseLinha(int)),
            ui->lcdNumberLinha,
            SLOT(display(int)));

    connect(ui->widgetPlotter,
            SIGNAL(mouseColuna(int)),
            ui->lcdNumberColuna,
            SLOT(display(int)));
/////////////////////////////////////////

    connect(ui->actionShow_OFF,
            SIGNAL(triggered(bool)),
            ui->widgetPlotter,
            SLOT(saveOFF()));

    connect(ui->actionShow_VECT,
            SIGNAL(triggered(bool)),
            ui->widgetPlotter,
            SLOT(saveVECT()));

    connect(ui->actionSave,
            SIGNAL(triggered(bool)),
            ui->widgetPlotter,
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

    connect(ui->actionRotClk,
            SIGNAL(triggered(bool)),
            ui->widgetPlotter,
            SLOT(rotClockWise()));

    connect(ui->actionRotCClk,
            SIGNAL(triggered(bool)),
            ui->widgetPlotter,
            SLOT(rotCClockWise()));

    connect(ui->actionInvert,
            SIGNAL(triggered(bool)),
            ui->widgetPlotter,
            SLOT(inverter()));

    connect(ui->actionNewBox,
            SIGNAL(triggered(bool)),
            ui->widgetPlotter,
            SLOT(newSize()));

    connect(ui->actionNewBox,
            SIGNAL(triggered(bool)),
            this,
            SLOT(updateNewSliders()));


    ////////////////////////////

    connect(ui->actionPutVoxel,
            SIGNAL(triggered(bool)),
            this,
            SLOT(updateShapeText()));

    connect(ui->actionCutVoxel,
            SIGNAL(triggered(bool)),
            this,
            SLOT(updateShapeText()));

    connect(ui->actionPutBox,
            SIGNAL(triggered(bool)),
            this,
            SLOT(updateShapeText()));

    connect(ui->actionCutBox,
            SIGNAL(triggered(bool)),
            this,
            SLOT(updateShapeText()));

    connect(ui->actionPutSphere,
            SIGNAL(triggered(bool)),
            this,
            SLOT(updateShapeText()));

    connect(ui->actionCutSphere,
            SIGNAL(triggered(bool)),
            this,
            SLOT(updateShapeText()));

    connect(ui->actionPutEllipsoid,
            SIGNAL(triggered(bool)),
            this,
            SLOT(updateShapeText()));

    connect(ui->actionCutEllipsoid,
            SIGNAL(triggered(bool)),
            this,
            SLOT(updateShapeText()));

    connect(ui->horizontalSliderX,
            SIGNAL(valueChanged(int)),
            this,
            SLOT(updateSliceSlider()));

    connect(ui->horizontalSliderY,
            SIGNAL(valueChanged(int)),
            this,
            SLOT(updateSliceSlider()));

    connect(ui->horizontalSliderZ,
            SIGNAL(valueChanged(int)),
            this,
            SLOT(updateSliceSlider()));

    connect(ui->actionRotClk,
            SIGNAL(triggered(bool)),
            this,
            SLOT(updateSliceSlider()));

    connect(ui->actionRotCClk,
            SIGNAL(triggered(bool)),
            this,
            SLOT(updateSliceSlider()));

    connect(ui->actionInvert,
            SIGNAL(triggered(bool)),
            this,
            SLOT(updateSliceSlider()));

    connect(ui->widgetColor->actionMudaCor,
            SIGNAL(triggered(bool)),
            ui->widgetColor,
            SLOT(mudaCor()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateSliceSlider()
{
    int plane = ui->widgetPlotter->plane;
    if(plane==1||plane==4||plane==7||plane==10)  {
        ui->horizontalSliderSlice->setMaximum(ui->widgetPlotter->scpSizeZ -1);
        ui->labelDim->setText(ui->widgetPlotter->planeChosen);
    }
    else if(plane==2||plane==5||plane==8||plane==11){
        ui->horizontalSliderSlice->setMaximum(ui->widgetPlotter->scpSizeY -1);
        ui->labelDim->setText(ui->widgetPlotter->planeChosen);
    }
    else {
        ui->horizontalSliderSlice->setMaximum(ui->widgetPlotter->scpSizeX -1);
        ui->labelDim->setText(ui->widgetPlotter->planeChosen);
    }

}

void MainWindow::updateShapeText()
{
    ui->labelFG->setText(ui->widgetPlotter->shapeState);

}

void MainWindow::updateNewSliders(){

    ui->horizontalSliderX->setMaximum(ui->widgetPlotter->scpSizeX-1);
    ui->horizontalSliderY->setMaximum(ui->widgetPlotter->scpSizeY-1);
    ui->horizontalSliderZ->setMaximum(ui->widgetPlotter->scpSizeZ-1);
    ui->horizontalSliderRD->setMaximum(ui->widgetPlotter->scpSizeX/2 -1);
    ui->horizontalSliderRX->setMaximum(ui->widgetPlotter->scpSizeX/2 -1);
    ui->horizontalSliderRY->setMaximum(ui->widgetPlotter->scpSizeY/2 -1);
    ui->horizontalSliderRZ->setMaximum(ui->widgetPlotter->scpSizeZ/2 -1);
    ui->horizontalSliderSlice->setMaximum(ui->widgetPlotter->scpSizeZ -1);

    ui->labelSize->setText(ui->widgetPlotter->boxSize);
}
