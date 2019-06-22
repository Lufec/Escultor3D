#include "dialogsize.h"
#include "ui_dialogsize.h"

DialogSize::DialogSize(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogSize)
{
    ui->setupUi(this);
    ui->horizontalSliderSX->setTickInterval(2);
    ui->horizontalSliderSY->setTickInterval(2);
    ui->horizontalSliderSZ->setTickInterval(2);

    ui->horizontalSliderSX->setMinimum(2);
    ui->horizontalSliderSY->setMinimum(2);
    ui->horizontalSliderSZ->setMinimum(2);

    ui->horizontalSliderSX->setMaximum(100);
    ui->horizontalSliderSY->setMaximum(100);
    ui->horizontalSliderSZ->setMaximum(100);
}

DialogSize::~DialogSize()
{
    delete ui;
}

int DialogSize::getSizeX()
{
  return ui->horizontalSliderSX->value();
}

int DialogSize::getSizeY()
{
  return ui->horizontalSliderSY->value();
}

int DialogSize::getSizeZ()
{
  return ui->horizontalSliderSZ->value();
}
