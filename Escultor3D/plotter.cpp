#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QMouseEvent>
#include <vector>
#include "plotter.h"
#include "sculptor.h"

Plotter::Plotter(QWidget *parent) : QWidget(parent)
{
    scpSizeX = 18; scpSizeY = 18; scpSizeZ=18;    //Será setado por dialogBox
    cube = new Sculptor(scpSizeX,scpSizeY,scpSizeZ);

    slice=5; plane=1;   //setado por slider e botoes
    m = cube->readMx(slice,plane);

    sizeX=0; sizeY=0; sizeZ=0; radius=0;radiusX=0;radiusY=0;radiusZ=0;

    colorRed = 255; colorGreen=255; colorBlue=255; transparency = 255;

    shape=1;
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

    int dim1 = width()/m[0].size();
    int dim2 = height()/m.size();
    int dim;

    sizeSquareX = dim1;
    sizeSquareY = dim2;


    if(dim1>dim2){
        dim=dim2;
    }
    else {
        dim=dim1;
    }


    pa.drawRect(0,0,width(),height());
    for(int i =0; i<height(); i=i+dim1){
        for(int j =0; j<width(); j=j+dim2){
            pa.drawRect(i,j,dim1, dim2);
        }
    }


    brush.setColor(QColor(colorRed,colorGreen,colorBlue,transparency));   //Cor setada por sliders
    brush.setStyle(Qt::SolidPattern);
    pa.setBrush(brush);


    for(int i=0; i<m.size();i++){    //trabalhar com iterators pra desenhar voxels ligados
       for(int j=0; j<m[0].size();j++){
            if(m[i][j].isOn){
                    int xcenter =i*dim1;
                    int ycenter =j*dim2;
                    pa.drawEllipse(xcenter,ycenter,dim1,dim2);
            }
       }
    }

}

void Plotter::mouseMoveEvent(QMouseEvent *event){
  emit moveX(event->x());
  emit moveY(event->y());
  // qDebug() << event->x() << "x" << event->y();
}

void Plotter::mousePressEvent(QMouseEvent *event){
  if(event->button() == Qt::LeftButton){
    emit clickX(event->x());
    emit clickY(event->y());
    mousePressed = true;
    mouseX = (event->x())/sizeSquareX;
    mouseY = (event->y())/sizeSquareY;

    emit mouseLinha(mouseX);
    emit mouseColuna(mouseY);

    if(plane == 1) //XY
    {
        posX=mouseX;
        posY=mouseY;
        posZ=slice;
    }

    else if(plane == 2) //XZ
    {
        posX=mouseX;
        posY=slice;
        posZ=mouseY;
    }

    else if(plane == 3) //YZ
    {
        posX=slice;
        posY=mouseX;
        posZ=mouseY;
    }
    Plotter::drawShape(shape);
  }
}

void Plotter::mouseReleaseEvent(QMouseEvent *event)
{
    if(!(event->button() == Qt::LeftButton)){
    mousePressed = false;
    }
}

void Plotter::drawShape(int shape){

    //if pra cada plane...
    if(shape == 1) //PutVoxel
    {
       cube->setColor(colorRed,colorGreen,colorGreen,transparency);   //setada por sliders
       cube->putVoxel(posX,posY,posZ);        //setada onde clickado
    }
    if(shape == 2) //CutVoxel
    {
       cube->cutVoxel(posX,posY,posZ);
    }
    if(shape == 3) //PutBox
    {
        cube->setColor(colorRed,colorGreen,colorGreen,transparency);
        cube->putBox(posX,(posX+sizeX),posY,(posY+sizeY),posZ,(posZ+sizeZ));

    }
    if(shape == 4) //CutBox
    {
       cube->cutBox(posX,(posX+sizeX),posY,(posY+sizeY),posZ,(posZ+sizeZ));
    }
    if(shape == 5) //PutSphere
    {
        cube->setColor(colorRed,colorGreen,colorGreen,transparency);
        cube->putSphere(posX,posY,posZ,radius);

    }
    if(shape == 6) //CutSphere
    {
       cube->cutSphere(posX,posY,posZ,radius);;
    }
    if(shape == 7) //PutEllipsoid
    {
        cube->setColor(colorRed,colorGreen,colorGreen,transparency);
        cube->putEllipsoid(posX,posY,posZ,radiusX,radiusY,radiusZ);

    }
    if(shape == 8) //Cut
    {
       cube->cutEllipsoid(posX,posY,posZ,radiusX,radiusY,radiusZ);
    }
    m=cube->readMx(slice,plane);
    repaint();
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
    m = cube ->readMx(slice,plane);
    repaint();
}

