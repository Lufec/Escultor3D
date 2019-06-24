#ifndef COLORWINDOW_H
#define COLORWINDOW_H

#include <QWidget>
#include <QColor>
///
/// \brief The ColorWindow class is responsible to show the color selected by the sliders on the main window
///
class ColorWindow : public QWidget
{
    Q_OBJECT

public:
    ///
    /// \brief ColorWindow is Constructor
    /// \param parent
    ///
    explicit ColorWindow(QWidget *parent = nullptr);
    ///
    /// \brief paintEvent is where the rectangle is painted according to the color selected
    /// \param event
    ///
    void paintEvent(QPaintEvent *event);

    void contextMenuEvent(QContextMenuEvent *event);
    ///
    /// \brief colorRed is the red color
    ///
    ///
    int colorRed;
    ///
    /// \brief colorGreen is the green color
    ///
    int colorGreen;
    ///
    /// \brief colorBlue is the blue color
    ///
    int colorBlue;
    ///
    /// \brief alpha is the transparency
    ///
    int alpha;

    QAction *actionMudaCor;

private:
signals:

public slots:
    ///
    /// \brief changeRed2 receives the value int of red slider
    /// \param red is the value of red slider
    ///
    void changeRed2(int red);
    ///
    /// \brief changeGreen2 receives the value int of green slider
    /// \param green is the value of green slider
    ///
    void changeGreen2(int green);
    ///
    /// \brief changeBlue2 receives the value int of blue slider
    /// \param blue is the value of blue slider
    ///
    void changeBlue2(int blue);
    ///
    /// \brief changeAlpha2 receives the value int of transparency slider
    /// \param alpha is the value of transparency slider
    ///
    void changeAlpha2(int alpha);

    void mudaCor();
};

#endif // COLORWINDOW_H
