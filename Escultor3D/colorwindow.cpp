#include "colorwindow.h"
#include <QPainter>
#include <QColor>
#include <QPen>
#include <QBrush>
#include <QAction>
#include <QMessageBox>
#include <QColorDialog>
#include <QMenu>
#include <QContextMenuEvent>
#include "plotter.h"

ColorWindow::ColorWindow(QWidget *parent) : QWidget(parent)
{
    colorRed=1;colorGreen=1;colorBlue=1;alpha=255;
    actionMudaCor = new QAction(this);
    actionMudaCor->setText("Muda Cor");


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
    brush.setColor(QColor(colorRed,colorGreen,colorBlue,alpha));
    brush.setStyle(Qt::SolidPattern);
    pa.setBrush(brush);


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

void ColorWindow::mudaCor(){
  int r, g, b;
  QColor cor;
  QMessageBox box;
  QString msg;
  QColorDialog d;
  d.exec();
  cor = d.selectedColor();
  colorRed = cor.red();
  colorGreen = cor.green();
  colorBlue = cor.blue();
  r = cor.red();
  g = cor.green();
  b = cor.blue();
  msg = "r = <b>"+QString::number(r)+"</b> <br>"+
      "g = <b>"+QString::number(g)+"</b> <br>"+
      "b = <b>"+QString::number(b)+"</b>";
  box.setText(msg);
  box.exec();
  repaint();
}

void ColorWindow::contextMenuEvent(QContextMenuEvent *event)
{
  QMenu menu(this);
  menu.addAction(actionMudaCor);
  menu.exec(event->globalPos());
}

