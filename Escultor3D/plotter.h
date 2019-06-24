#ifndef PLOTTER_H
#define PLOTTER_H

#include <QWidget>
#include <QAction>
#include <QColor>
#include <QTimerEvent>
#include <vector>
#include "sculptor.h"
///
/// \brief The Plotter class is responsible for the construction and modification of a Sculptor, using a graphical interface. It contains the graphical interface and numerous funcitons that create a 3D sculpture
///
class Plotter : public QWidget
{
    Q_OBJECT
public:
    ///
    /// \brief Plotter constructor sets an initial value to a set of variables. Variables set: SCP Sizes, slice, box Sizes, radius (both sphere and ellipsoid), colors, shape and Sculptor's Cube.
    /// \param parent
    ///
    explicit Plotter(QWidget *parent = nullptr);
    ///
    /// \brief paintEvent is the graphical interface. It calls a Matrix of a cube given a slice, analyse it's contents, draw a grid and draws an ellipsoid where there is an active Voxel on the Matrix, with it's respective color and alpha.
    /// \param event
    ///
    void paintEvent(QPaintEvent *event);
    ///
    /// \brief mouseMoveEvent retrieves the value of X and Y position of a mouse on Plotter. Then, given a certain plane value, it sets a value of X,Y and Z to create a geometric figure, if necessary.
    /// \param event in this case, is a mouse movement.
    ///
    void mouseMoveEvent(QMouseEvent *event);
    ///
    /// \brief mousePressEvent retrieves the value of X and Y of a mouse on Plotter after a press action. Then, it sets a X, Y and Z value to draw a geometric figure.
    /// \param event in this case, is a mouse pressed.
    ///
    void mousePressEvent(QMouseEvent *event);
    ///
    /// \brief mouseReleaseEvent stops a draw action initiated at mousePressEvent.
    /// \param event in this case, is a mouse released.
    ///
    void mouseReleaseEvent(QMouseEvent *event);
    ///
    /// \brief drawShape is where the mouse events relate to a Sculptor: after retrieving the X,Y,Z positions on mouse events, they draw a geometric figure given a chosen figure, state of mouse clicked and slider's values.
    /// \param shape signifies which shape will be drawn: PutVoxel, CutVoxel, PutBox, CutBox, PutSphere, CutSphere, PutEllipsoid, CutEllipsoid.
    /// \param mousePressed is a bool that activates the draw action.
    ///
    void drawShape(int shape, bool mousePressed);

    ///
    /// \brief scpSizeX is the X-size of Cube
    ///
    int scpSizeX;
    ///
    /// \brief scpSizeY is the Y-size of Cube
    ///
    int scpSizeY;
    ///
    /// \brief scpSizeZ is the Z-size of Cube
    ///
    int scpSizeZ;

    ///
    /// \brief sizeX is the X-size used in PutBox and CutBox
    ///
    int sizeX;
    ///
    /// \brief sizeY is the Y-size used in PutBox and CutBox
    ///
    int sizeY;
    ///
    /// \brief sizeZ is the Z-size used in PutBox and CutBox
    ///
    int sizeZ;
    ///
    /// \brief radius is the radius size used in PutSphere and CutSphere
    ///
    int radius;
    ///
    /// \brief radiusX is the X-radius size used in PutEllipsoid and CutEllipsoid
    ///
    int radiusX;
    ///
    /// \brief radiusY is the Y-radius size used in PutEllipsoid and CutEllipsoid
    ///
    int radiusY;
    ///
    /// \brief radiusZ is the Z-radius size used in PutEllipsoid and CutEllipsoid
    ///
    int radiusZ;
    ///
    /// \brief radiusMax is used to set a max value of the radius Slider. Value follows half of the biggest size of the Cube
    ///
    int radiusMax;
    ///
    /// \brief slice is the part of cube that the user sees in the graphical interface. It can be the X,Y or Z dimension, dependind on which plane is set.
    ///
    int slice;

    ///
    /// \brief plane is the orientation and side of the box that the user will see.
    ///
    unsigned int plane;
    ///
    /// \brief colorRed is the Red Color of a drawed matrix.
    ///
    int colorRed;
    ///
    /// \brief colorGreen is the Green color of a drawed matrix.
    ///
    int colorGreen;
    ///
    /// \brief colorBlue is the Blue color of a drawed matrix.
    ///
    int colorBlue;
    ///
    /// \brief transparency is the transparency of a drawed matrix.
    ///
    int transparency;
    ///
    /// \brief shapeState is the text that shows which shape is selected
    ///
    QString shapeState;
    ///
    /// \brief planeChosen is a text tha shows wich plane is selected
    ///
    QString planeChosen;
    ///
    /// \brief boxSize is a text tha shows the size of the sculptor's cube
    ///
    QString boxSize;

private:
    ///
    /// \brief cube is the main sculptor worked on.
    ///
    Sculptor *cube;
    ///
    /// \brief m is a Voxel's matrix based on a part of the cube.
    ///
    std::vector<std::vector<Voxel>> m;
    ///
    /// \brief mousePressed indicates if mouse is pressed ou not. Used in drawShape to confirm action.
    ///
    bool mousePressed;
    ///
    /// \brief mouseX is the X-position of Mouse
    ///
    int mouseX;
    ///
    /// \brief mouseY is the Y-position of Mouse
    ///
    int mouseY;
    ///
    /// \brief posX is an variable used to draw a geometric figure. Is set based on which plane is chosen and mouse position
    ///
    int posX;
    ///
    /// \brief posY is an variable used to draw a geometric figure. Is set based on which plane is chosen and mouse position
    ///
    int posY;
    ///
    /// \brief posZ is an variable used to draw a geometric figure. Is set based on which plane is chosen and mouse position
    ///
    int posZ;

    ///
    /// \brief sizeSquare is used to make the grid of plotter. Gets the smallest size of a rectangle after dividing the widget and sets grid as squares.
    ///
    int sizeSquare;
    ///
    /// \brief shape is a variable that certain number represent a specific geometric figure. If a certain number is set and drawShape occurs, the specific shape is drawed.
    ///
    unsigned int shape;

signals:
  ///
  /// \brief moveX is the value of X-position of mouse on plotter at move Event.
  ///
  void moveX(int);
  ///
  /// \brief moveY is the value of Y-position of mouse on plotter at move Event.
  ///
  void moveY(int);
  ///
  /// \brief clickX is the value of X-position of mouse on plotter at click event.
  ///
  void clickX(int);
  ///
  /// \brief clickY is the value of X-position of mouse on plotter at click event.
  ///
  void clickY(int);
  ///
  /// \brief mouseLinha is the value of which square was clicked on Y dimension
  ///
  void mouseLinha(int);
  ///
  /// \brief mouseColuna is the value of which square was clicked on X dimension
  ///
  void mouseColuna(int);

public slots:
  ///
  /// \brief changeSizeX changes the value of the X-side of Size that can be used at PutBox and CutBox
  /// \param size is the value received by the respective slider
  ///
  void changeSizeX(int size);
  ///
  /// \brief changeSizeY changes the value of the Y-side of Size that can be used at PutBox and CutBox
  /// \param size is the value received by the respective slider
  ///
  void changeSizeY(int size);
  ///
  /// \brief changeSizeZ changes the value of the Z-side of Size that can be used at PutBox and CutBox
  /// \param size is the value received by the respective slider
  ///
  void changeSizeZ(int size);
  ///
  /// \brief changeRadius changes the value of radius that can be used at PutSphere and CutSphere
  /// \param rd is the value received by the respective slider
  ///
  void changeRadius(int rd);
  ///
  /// \brief changeRadiusX changes the value of X-radius that can be used at PutEllipsoid and CutEllipsoid
  /// \param rd is the value received by the respective slider
  ///
  void changeRadiusX(int rx);
  ///
  /// \brief changeRadiusY changes the value of Y-radius that can be used at PutEllipsoid and CutEllipsoid
  /// \param rd is the value received by the respective slider
  ///
  void changeRadiusY(int ry);
  ///
  /// \brief changeRadiusZ changes the value of Z-radius that can be used at PutEllipsoid and CutEllipsoid
  /// \param rd is the value received by the respective slider
  ///
  void changeRadiusZ(int rz);
  ///
  /// \brief changePlane1 changes the parameter plane to value "1" (XY)
  ///
  void changePlane1(); //XY1
  ///
  /// \brief changePlane2 changes the parameter plane to value "2" (ZX)
  ///
  void changePlane2(); //ZX1
  ///
  /// \brief changePlane3 changes the parameter plane to value "3" (YZ)
  ///
  void changePlane3(); //YZ1
  ///
  /// \brief changeShape1 changes the parameter shape to value "1" (PutVoxel)
  ///
  void changeShape1(); //PV
  ///
  /// \brief changeShape2 changes the parameter shape to value "2" (CutVoxel)
  ///
  void changeShape2(); //CV
  ///
  /// \brief changeShape3 changes the parameter shape to value "3" (PutBox)
  ///
  void changeShape3(); //PB
  ///
  /// \brief changeShape4 changes the parameter shape to value "4" (CutBox)
  ///
  void changeShape4(); //CB
  ///
  /// \brief changeShape5 changes the parameter shape to value "5" (PutSphere)
  ///
  void changeShape5(); //PS
  ///
  /// \brief changeShape6 changes the parameter shape to value "6" (CutSphere)
  ///
  void changeShape6(); //CS
  ///
  /// \brief changeShape7 changes the parameter shape to value "7" (PutEllipsoid)
  ///
  void changeShape7(); //PE
  ///
  /// \brief changeShape8 changes the parameter shape to value "8" (CutEllipsoid)
  ///
  void changeShape8(); //PS
  ///
  /// \brief rotClockWise changes the parameter plane to a value that is clock-wise to the current plane position
  ///
  void rotClockWise();
  ///
  /// \brief rotCClockWise changes the parameter plane to a value that is counter clock-wise to the current plane position
  ///
  void rotCClockWise();
  ///
  /// \brief inverter changes the parameter plane to a value that is the opposite side of current plane position
  ///
  void inverter();
  ///
  /// \brief saveVECT executes a viewing of current sculpture in vect format. Creates temporary vect file to show
  ///
  void saveVECT();
  ///
  /// \brief saveOFF executes a viewing of current sculpture in OFF format. Creates temporary off file to show
  ///
  void saveOFF();
  ///
  /// \brief saveAll save files OFF and VECT of constructed Sculptor
  ///
  void saveAll();
  ///
  /// \brief newSize opens a dialog box that changes the dimensions of a new sculpture. The old one is deleted and a new one is created.
  ///
  void newSize();
  ///
  /// \brief changeRed changes the parameter colorRed to the value setted on slider
  /// \param red is the value received by the slider
  ///
  void changeRed(int red);
  ///
  /// \brief changeGreen changes the parameter colorGreen to the value setted on slider
  /// \param green is the value received by the slider
  ///
  void changeGreen(int green);
  ///
  /// \brief changeBlue changes the parameter colorBlue to the value setted on slider
  /// \param blue is the value received by the slider
  ///
  void changeBlue(int blue);
  ///
  /// \brief changeAlpha changes the parameter transparency to the value setted on slider
  /// \param alpha is the value receive by the slider
  ///
  void changeAlpha(int alpha);
  ///
  /// \brief changeSlice changes the parameter slice to the value setted on slider
  /// \param pln is the value received by the slider
  ///
  void changeSlice(int pln);

};

#endif // PLOTTER_H
