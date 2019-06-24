#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "sculptor.h"
#include "vector"

namespace Ui {
class MainWindow;
}
///
/// \brief The MainWindow class is the main application, where all the main widgets, buttons and sliders are located.
///
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    ///
    /// \brief MainWindow Constructor sets the connections between buttons and widgets, together with the form "mainWindow.ui"
    /// \param parent
    ///
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();    

private:

    Ui::MainWindow *ui;


public slots:
    ///
    /// \brief updateNewSliders is called when a new Scultor is made. All size-related sliders are updated to the new size chosen by the user.
    ///
    void updateNewSliders();
    ///
    /// \brief updateSliceSlider is called when a plane dimension is changed (XY to YZ for example). It will update all sliders according to the new size
    ///
    void updateSliceSlider();

    void updateShapeText();

};

#endif // MAINWINDOW_H
