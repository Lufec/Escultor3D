#include "colorwindow.h"
#include <QPainter>
#include <QColor>
#include <QPen>
#include <QBrush>

ColorWindow::ColorWindow(QWidget *parent) : QWidget(parent)
{
    colorRed=255;colorGreen=255;colorBlue=255;alpha=255;
}

void ColorWindow::paintEvent(QPaintEvent *event)
{
    QPainter pa(this);
    QPen pen;
    QBrush brush;
    pen.setColor(QColor(0,0,0));
    pen.setWidth(2);
      // entregando a caneta ao pintor
    pa.setPen(pen);
    brush.setColor(QColor(0,0,0,255));
    brush.setStyle(Qt::SolidPattern);


    pa.drawRect(0,0,width(),height());

}

void ColorWindow::changeRed2(int red)
{
    colorRed = red;
    repaint();
}
void ColorWindow::changeGreen2(int green)
{
    colorGreen = green;
    repaint();
}
void ColorWindow::changeBlue2(int blue)
{
    colorBlue = blue;
    repaint();
}
void ColorWindow::changeAlpha2(int _alpha)
{
    alpha = _alpha;
    repaint();
}


