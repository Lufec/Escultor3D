#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QMouseEvent>
#include <QtDebug>
#include <QMessageBox>
#include <QDialog>
#include <QString>
#include <QProcess>
#include <vector>
#include <iostream>
#include "dialogsize.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "plotter.h"
#include "sculptor.h"

Plotter::Plotter(QWidget *parent) : QWidget(parent)
{
    scpSizeX = 50; scpSizeY = 50; scpSizeZ=50;    //Será setado por dialogBox
    cube = new Sculptor(scpSizeX,scpSizeY,scpSizeZ);

    slice=0; plane=1;   //setado por slider e botoes

    sizeX=0; sizeY=0; sizeZ=0; radius=0;radiusX=0;radiusY=0;radiusZ=0;

    colorRed = 1; colorGreen=1; colorBlue=1; transparency = 255;

    shape=1;

    shapeState = "PutVoxel";

    boxSize = "50 x 50 x 50";

}

void Plotter::paintEvent(QPaintEvent *event)
{
    QPainter pa(this);
    QPen pen;
    QBrush brush;
    pen.setColor(QColor(0,0,0));
    pen.setWidth(2);
      // entregando a caneta ao pintor
    pa.setPen(pen);
    brush.setColor(QColor(255,255,255));
    brush.setStyle(Qt::SolidPattern);
      // entregando o pincel ao pintor
    pa.setBrush(brush);
    m.clear();
    m = cube ->readMx(slice,plane);

    int dim1 = width()/m[0].size();
    int dim2 = height()/m.size();

    if(dim1>dim2){
        sizeSquare=dim2;
    }
    else if(dim2>=dim1) {
        sizeSquare=dim1;
    }


    for(unsigned int i =0; i<m.size(); i++){
        for(unsigned int j =0; j<m[0].size(); j++){
            pa.drawRect(i*sizeSquare,j*sizeSquare,sizeSquare, sizeSquare);
        }
    }

    for(unsigned int i=0; i<m.size();i++){    //trabalhar com iterators pra desenhar voxels ligados
       for(unsigned int j=0; j<m[0].size();j++){
            if(m[i][j].isOn){
                    brush.setColor(QColor(m[i][j].r,m[i][j].g,m[i][j].b,m[i][j].a));   //Cor setada por sliders
                    brush.setStyle(Qt::SolidPattern);
                    pa.setBrush(brush);
                    int xcenter =i*sizeSquare;
                    int ycenter =j*sizeSquare;
                    pa.drawEllipse(xcenter,ycenter,sizeSquare,sizeSquare);
            }
       }
    }

}

void Plotter::mouseMoveEvent(QMouseEvent *event){
    emit moveX(event->x());
    emit moveY(event->y());

    mouseX = (event->x())/sizeSquare;
    mouseY = (event->y())/sizeSquare;

    switch(plane){
    case 1:
        posX=mouseX;
        posY=mouseY;
        posZ=slice;
    break;
    case 2:
        posX=mouseY;
        posY=slice;
        posZ=mouseX;
    break;
    case 3:
        posX=slice;
        posY=mouseX;
        posZ=mouseY;
    break;
    case 4:
        posX=mouseY;
        posY=scpSizeY-1-mouseX;
        posZ=slice;
    break;
    case 5:
        posX=scpSizeX-1-mouseX;
        posY=slice;
        posZ=mouseY;
    break;
    case 6:
        posX=slice;
        posY=mouseY;
        posZ=scpSizeZ-1-mouseX;
    break;
    case 7:
        posX=scpSizeX-1-mouseX;
        posY=scpSizeY-1-mouseY;
        posZ=slice;
    break;
    case 8:
        posX=scpSizeX-1-mouseY;
        posY=slice;
        posZ=scpSizeZ-1-mouseX;
    break;
    case 9:
        posX=slice;
        posY=scpSizeY-1-mouseX;
        posZ=scpSizeZ-1-mouseY;
    break;
    case 10:
        posX=scpSizeX-1-mouseY;
        posY=mouseX;
        posZ=slice;
    break;
    case 11:
        posX=mouseX;
        posY=slice;
        posZ=scpSizeZ-1-mouseY;
    break;
    case 12:
        posX=slice;
        posY=scpSizeY-1-mouseY;
        posZ=mouseX;
    break;
    case 13:
        posX=mouseY;
        posY=mouseX;
        posZ=slice;
    break;
    case 14:
        posX=mouseX;
        posY=slice;
        posZ=mouseY;
    break;
    case 15:
        posX=slice;
        posY=mouseY;
        posZ=mouseX;
    break;
    case 16:
        posX=mouseX;
        posY=scpSizeX-1-mouseY;
        posZ=slice;
    break;
    case 17:
        posX=mouseX;
        posY=slice;
        posZ=mouseY;
    break;
    case 18:
        posX=slice;
        posY=mouseY;
        posZ=mouseX;
    break;
    case 19:
        posX=scpSizeX-mouseX;
        posY=scpSizeY-mouseY;
        posZ=slice;
    break;
    case 20:
        posX=mouseY;
        posY=slice;
        posZ=mouseX;
    break;
    case 21:
        posX=slice;
        posY=mouseX;
        posZ=mouseY;
    break;
    case 22:
        posX=mouseY;
        posY=mouseX;
        posZ=slice;
    break;
    case 23:
        posX=mouseX;
        posY=slice;
        posZ=mouseY;
    break;
    case 24:
        posX=slice;
        posY=mouseY;
        posZ=mouseX;
    break;
    }
    emit mouseLinha(posX+1);
    emit mouseColuna(posY+1);

    Plotter::drawShape(shape,mousePressed);


}

void Plotter::mousePressEvent(QMouseEvent *event){
  if(event->button() == Qt::LeftButton){
    emit clickX(event->x());
    emit clickY(event->y());
    mousePressed = true;
    mouseX = (event->x())/sizeSquare;
    mouseY = (event->y())/sizeSquare;

    switch(plane){
    case 1:
        posX=mouseX;
        posY=mouseY;
        posZ=slice;
    break;
    case 2:
        posX=mouseY;
        posY=slice;
        posZ=mouseX;
    break;
    case 3:
        posX=slice;
        posY=mouseX;
        posZ=mouseY;
    break;
    case 4:
        posX=mouseY;
        posY=scpSizeY-1-mouseX;
        posZ=slice;
    break;
    case 5:
        posX=scpSizeX-1-mouseX;
        posY=slice;
        posZ=mouseY;
    break;
    case 6:
        posX=slice;
        posY=mouseY;
        posZ=scpSizeZ-1-mouseX;
    break;
    case 7:
        posX=scpSizeX-1-mouseX;
        posY=scpSizeY-1-mouseY;
        posZ=slice;
    break;
    case 8:
        posX=scpSizeX-1-mouseY;
        posY=slice;
        posZ=scpSizeZ-1-mouseX;
    break;
    case 9:
        posX=slice;
        posY=scpSizeY-1-mouseX;
        posZ=scpSizeZ-1-mouseY;
    break;
    case 10:
        posX=scpSizeX-1-mouseY;
        posY=mouseX;
        posZ=slice;
    break;
    case 11:
        posX=mouseX;
        posY=slice;
        posZ=scpSizeZ-1-mouseY;
    break;
    case 12:
        posX=slice;
        posY=scpSizeY-1-mouseY;
        posZ=mouseX;
    break;
    case 13:
        posX=mouseY;
        posY=mouseX;
        posZ=slice;
    break;
    case 14:
        posX=mouseX;
        posY=slice;
        posZ=mouseY;
    break;
    case 15:
        posX=slice;
        posY=mouseY;
        posZ=mouseX;
    break;
    case 16:
        posX=mouseX;
        posY=scpSizeX-1-mouseY;
        posZ=slice;
    break;
    case 17:
        posX=scpSizeX-1-mouseY;
        posY=slice;
        posZ=mouseX;
    break;
    case 18:
        posX=slice;
        posY=mouseX;
        posZ=scpSizeZ-1-mouseY;
    break;
    case 19:
        posX=mouseX;
        posY=mouseY;
        posZ=slice;
    break;
    case 20:
        posX=mouseY;
        posY=slice;
        posZ=mouseX;
    break;
    case 21:
        posX=slice;
        posY=mouseX;
        posZ=mouseY;
    break;
    case 22:
        posX=mouseY;
        posY=mouseX;
        posZ=slice;
    break;
    case 23:
        posX=mouseX;
        posY=slice;
        posZ=mouseY;
    break;
    case 24:
        posX=slice;
        posY=mouseY;
        posZ=mouseX;
    break;
    }
    emit mouseLinha(posX+1);
    emit mouseColuna(posY+1);

    Plotter::drawShape(shape,mousePressed);
  }
}

void Plotter::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
       mousePressed = false;
    }
}

void Plotter::drawShape(int shape, bool mousePressed){

  if(mousePressed){
    if(shape == 1) //PutVoxel
    {
       cube->setColor(colorRed,colorGreen,colorBlue,transparency);   //setada por sliders
       cube->putVoxel(posX,posY,posZ);        //setada onde clickado
    }
    if(shape == 2) //CutVoxel
    {
       cube->cutVoxel(posX,posY,posZ);
    }
    if(shape == 3) //PutBox
    {
        cube->setColor(colorRed,colorGreen,colorBlue,transparency);
        cube->putBox(posX,(posX+sizeX),posY,(posY+sizeY),posZ,(posZ+sizeZ));

    }
    if(shape == 4) //CutBox
    {
       cube->cutBox(posX,(posX+sizeX),posY,(posY+sizeY),posZ,(posZ+sizeZ));
    }
    if(shape == 5) //PutSphere
    {
        cube->setColor(colorRed,colorGreen,colorBlue,transparency);
        cube->putSphere(posX,posY,posZ,radius);

    }
    if(shape == 6) //CutSphere
    {
       cube->cutSphere(posX,posY,posZ,radius);;
    }
    if(shape == 7) //PutEllipsoid
    {
        cube->setColor(colorRed,colorGreen,colorBlue,transparency);
        cube->putEllipsoid(posX,posY,posZ,radiusX,radiusY,radiusZ);

    }
    if(shape == 8) //Cut
    {
       cube->cutEllipsoid(posX,posY,posZ,radiusX,radiusY,radiusZ);
    }
    repaint();
    }
}

void Plotter::changeRed(int red)
{
    colorRed = red;
}
void Plotter::changeGreen(int green)
{
    colorGreen = green;
}
void Plotter::changeBlue(int blue)
{
    colorBlue = blue;
}
void Plotter::changeAlpha(int alpha)
{
    transparency = alpha;
}

void Plotter::changeSizeX(int size)
{
    sizeX=size;
}
void Plotter::changeSizeY(int size)
{
    sizeY=size;
}
void Plotter::changeSizeZ(int size)
{
    sizeZ=size;
}
void Plotter::changeRadius(int rd)
{
    radius=rd;
}
void Plotter::changeRadiusX(int rx)
{
    radiusX=rx;
}
void Plotter::changeRadiusY(int ry)
{
    radiusY=ry;
}
void Plotter::changeRadiusZ(int rz)
{
    radiusZ=rz;
}
void Plotter::changeSlice(int pln)
{
    slice = pln;
    repaint();
}

void Plotter::changePlane1() //XY
{
    plane = 1;
    slice = 0;
    planeChosen = "XY1";
    repaint();

}
void Plotter::changePlane2() //XZ
{
    plane = 2;
    slice = 0;
    planeChosen = "ZX1";

    repaint();
}
void Plotter::changePlane3() //YZ
{
    plane = 3;
    slice = 0;
    planeChosen = "YZ1";

    repaint();
}


void Plotter::changeShape1() //PV
{
    shape = 1;
    shapeState = "Put Voxel";

}
void Plotter::changeShape2() //CV
{
    shape = 2;
    shapeState = "Cut Voxel";
}
void Plotter::changeShape3() //PB
{
    shape = 3;
    shapeState = "Put Box";
}
void Plotter::changeShape4() //CB
{
    shape = 4;
    shapeState = "Cut Box";
}
void Plotter::changeShape5() //PS
{
    shape = 5;
    shapeState = "Put Sphere";
}
void Plotter::changeShape6() //CS
{
    shape = 6;
    shapeState = "Cut Sphere";
}
void Plotter::changeShape7() //PE
{
    shape = 7;
    shapeState = "Put Ellipsoid";
}
void Plotter::changeShape8() //PS
{
    shape = 8;
    shapeState = "Cut Ellipsoid";
}

void Plotter::rotClockWise()
{
    switch(plane){
    case 1: //XY1
        plane = 4;
        planeChosen="XY2";
    break;
    case 2: //ZX1
        plane = 5;
        planeChosen="ZX2";
    break;
    case 3: //YZ1
        plane = 6;
        planeChosen="YZ2";
    break;
    case 4: //XY2
        plane = 7;
        planeChosen="XY3";
    break;
    case 5: //ZX2
        plane = 8;
        planeChosen="ZX3";
    break;
    case 6: //YZ2
        plane = 9;
        planeChosen="YZ3";
    break;
    case 7:
        plane = 10;
        planeChosen="XY4";
    break;
    case 8:
        plane = 11;
        planeChosen="ZX4";
    break;
    case 9:
        plane = 12;
        planeChosen="YZ4";
    break;
    case 10:
        plane = 1;
        planeChosen="XY1";
    break;
    case 11:
        plane = 2;
        planeChosen="ZX1";
    break;
    case 12:
        plane = 3;
        planeChosen="YZ1";
    break;


    case 13:
        plane = 16;
        planeChosen="YX2";
    break;
    case 14:
        plane = 17;
        planeChosen="XZ2";
    break;
    case 15:
        plane = 18;
        planeChosen="ZY2";
    break;
    case 16:
        plane = 19;
        planeChosen="YX3";
    break;
    case 17:
        plane = 20;
        planeChosen="XZ3";
    break;
    case 18:
        plane = 21;
        planeChosen="ZY3";
    break;
    case 19:
        plane = 22;
        planeChosen="YX4";
    break;
    case 20:
        plane = 23;
        planeChosen="XZ4";
    break;
    case 21:
        plane = 24;
        planeChosen="ZY4";
    break;
    case 22:
        plane = 13;
        planeChosen="YX1";
    break;
    case 23:
        plane = 14;
        planeChosen="XZ1";
    break;
    case 24:
        plane = 15;
        planeChosen="ZY1";
    break;
    }
    repaint();
}
void Plotter::rotCClockWise()
{
    switch(plane){
    case 1: //XY1
        plane = 10;
        planeChosen="XY4";
    break;
    case 2: //ZX1
        plane = 11;
        planeChosen="ZX4";
    break;
    case 3: //YZ1
        plane = 12;
        planeChosen="YZ4";
    break;
    case 4: //XY2
        plane = 1;
        planeChosen="XY1";
    break;
    case 5: //ZX2
        plane = 2;
        planeChosen="ZX1";
    break;
    case 6: //YZ2
        plane = 3;
        planeChosen="YZ1";
    break;
    case 7:
        plane = 4;
        planeChosen="XY2";
    break;
    case 8:
        plane = 5;
        planeChosen="ZX2";
    break;
    case 9:
        plane = 6;
        planeChosen="YZ2";
    break;
    case 10:
        plane = 7;
        planeChosen="XY3";
    break;
    case 11:
        plane = 8;
        planeChosen="ZX3";
    break;
    case 12:
        plane = 9;
        planeChosen="YZ3";
    break;


    case 13:
        plane = 22;
        planeChosen="YX4";
    break;
    case 14:
        plane = 23;
        planeChosen="XZ4";
    break;
    case 15:
        plane = 24;
        planeChosen="ZY4";
    break;
    case 16:
        plane = 13;
        planeChosen="YX1";
    break;
    case 17:
        plane = 14;
        planeChosen="XZ1";
    break;
    case 18:
        plane = 15;
        planeChosen="ZY1";
    break;
    case 19:
        plane = 16;
        planeChosen="YX2";
    break;
    case 20:
        plane = 17;
        planeChosen="XZ2";
    break;
    case 21:
        plane = 18;
        planeChosen="ZY2";
    break;
    case 22:
        plane = 19;
        planeChosen="YX3";
    break;
    case 23:
        plane = 20;
        planeChosen="XZ3";
    break;
    case 24:
        plane = 21;
        planeChosen="ZY3";
    break;
    }

    repaint();
}
void Plotter::inverter()
{
    switch(plane){
    case 1: //XY1
        plane = 13;
        planeChosen="YX1";
    break;
    case 2: //ZX1
        plane = 14;
        planeChosen="XZ1";
    break;
    case 3: //YZ1
        plane = 15;
        planeChosen="ZY1";
    break;
    case 4: //XY2
        plane = 16;
        planeChosen="YX2";
    break;
    case 5: //ZX2
        plane = 17;
        planeChosen="XZ2";
    break;
    case 6: //YZ2
        plane = 18;
        planeChosen="ZY2";
    break;
    case 7:
        plane = 19;
        planeChosen="YX3";
    break;
    case 8:
        plane = 20;
        planeChosen="XZ3";
    break;
    case 9:
        plane = 21;
        planeChosen="ZY3";
    break;
    case 10:
        plane = 22;
        planeChosen="YX4";
    break;
    case 11:
        plane = 23;
        planeChosen="XZ4";
    break;
    case 12:
        plane = 24;
        planeChosen="ZY4";
    break;


    case 13:
        plane = 1;
        planeChosen="XY1";
    break;
    case 14:
        plane = 2;
        planeChosen="ZX1";
    break;
    case 15:
        plane = 3;
        planeChosen="YZ1";
    break;
    case 16:
        plane = 4;
        planeChosen="XY2";
    break;
    case 17:
        plane = 5;
        planeChosen="ZX2";
    break;
    case 18:
        plane = 6;
        planeChosen="YZ2";
    break;
    case 19:
        plane = 7;
        planeChosen="XY3";
    break;
    case 20:
        plane = 8;
        planeChosen="ZX3";
    break;
    case 21:
        plane = 9;
        planeChosen="YZ3";
    break;
    case 22:
        plane = 10;
        planeChosen="XY4";
    break;
    case 23:
        plane = 11;
        planeChosen="ZX4";
    break;
    case 24:
        plane = 12;
        planeChosen="YZ4";
    break;
    }

    repaint();
}

void Plotter::saveVECT()
{
    cube->writeVECT("/tmp/file.vect");


    QProcess *process = new QProcess(this);
    QString program = "/usr/bin/geomview";
    QString path = "/tmp/file.vect";
    QStringList list;
    list << path;
    process->start(program, list);
    process->waitForFinished();
}
void Plotter::saveOFF()
{
    cube->writeOFF("/tmp/file.off");

    QProcess *process = new QProcess(this);
    QString program = "/usr/bin/geomview";
    QString path = "/tmp/file.off";
    QStringList list;
    list << path;
    process->start(program, list);
    process->waitForFinished();
}
void Plotter::saveAll()
{
    cube->writeVECT("/home/lufec/Escultor3D/file.vect");
    cube->writeOFF("/home/lufec/Escultor3D/file.off");
}

void Plotter::newSize()
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

    cube->~Sculptor();

    scpSizeX = dialog.getSizeX();
    scpSizeY = dialog.getSizeY();
    scpSizeZ = dialog.getSizeZ();

    boxSize = QString::number(scpSizeX)+" x "+QString::number(scpSizeY)+" x "+QString::number(scpSizeZ);

    cube = new Sculptor(dialog.getSizeX(),dialog.getSizeY(),dialog.getSizeZ());

    slice = 0;


    repaint();

}
