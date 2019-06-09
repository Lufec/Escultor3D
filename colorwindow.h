#ifndef COLORWINDOW_H
#define COLORWINDOW_H

#include <QWidget>
#include <QColor>

class ColorWindow : public QWidget
{
    Q_OBJECT
public:
    explicit ColorWindow(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    int colorRed,colorGreen,colorBlue,alpha;

private:
signals:

public slots:
    void changeRed2(int red);
    void changeGreen2(int green);
    void changeBlue2(int blue);
    void changeAlpha2(int alpha);
};

#endif // COLORWINDOW_H
