#include "dialogsize.h"
#include "ui_dialogsize.h"

DialogSize::DialogSize(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogSize)
{
    ui->setupUi(this);
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
