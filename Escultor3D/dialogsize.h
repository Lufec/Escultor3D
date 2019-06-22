#ifndef DIALOGSIZE_H
#define DIALOGSIZE_H

#include <QDialog>

namespace Ui {
class DialogSize;
}
///
/// \brief The DialogSize class is responsible for changing the sculptor's cube parameters X,Y,Z.
///
class DialogSize : public QDialog
{
    Q_OBJECT

public:
    explicit DialogSize(QWidget *parent = nullptr);
    ~DialogSize();
    ///
    /// \brief getSizeX takes the value set by the slider X
    /// \return value of slider X
    ///
    int getSizeX();
    ///
    /// \brief getSizeY takes the value set by the slider Y
    /// \return value of slider Y
    ///
    int getSizeY();
    ///
    /// \brief getSizeZ takes the value set by the slider Z
    /// \return value of slider Z
    ///
    int getSizeZ();


private:
    Ui::DialogSize *ui;
};

#endif // DIALOGSIZE_H
