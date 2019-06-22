#ifndef SCULPTOR_H
#define SCULPTOR_H
#include <string>
#include <vector>

///
/// \brief The Voxel struct
///
struct Voxel {
    ///
    /// \brief r
    ///
  int r;
  ///
  /// \brief g
  ///
  int g;
  ///
  /// \brief b
  ///
  int b;
  ///
  /// \brief a
  ///
  int a;

  ///
  /// \brief isOn
  ///
  bool isOn;
};

class Sculptor {
protected:
    ///
    /// \brief v
    ///
  Voxel ***v;
  ///
  /// \brief nx
  ///
  int nx;
  ///
  /// \brief ny
  ///
  int ny;
  ///
  /// \brief nz
  ///
  int nz;
  ///
  /// \brief r
  ///
  int r;
  ///
  /// \brief g
  ///
  int g;
  ///
  /// \brief b
  ///
  int b;
  ///
  /// \brief a
  ///
  int a; // Current drawing color
public:
  ///
  /// \brief Sculptor
  /// \param tx
  /// \param ty
  /// \param tz
  ///
  Sculptor(int tx,int ty,int tz);
  ///
  /// \brief setColor
  /// \param _r
  /// \param _g
  /// \param _b
  /// \param alpha
  ///
  void setColor(int _r, int _g, int _b, int alpha);
  ///
  /// \brief putVoxel
  /// \param x
  /// \param y
  /// \param z
  ///
  void putVoxel(int x, int y, int z);
  ///
  /// \brief cutVoxel
  /// \param x
  /// \param y
  /// \param z
  ///
  void cutVoxel(int x, int y, int z);
  ///
  /// \brief putBox
  /// \param x0
  /// \param x1
  /// \param y0
  /// \param y1
  /// \param z0
  /// \param z1
  ///
  void putBox(int x0, int x1, int y0, int y1, int z0, int z1);
  ///
  /// \brief cutBox
  /// \param x0
  /// \param x1
  /// \param y0
  /// \param y1
  /// \param z0
  /// \param z1
  ///
  void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
  ///
  /// \brief putSphere
  /// \param xcenter
  /// \param ycenter
  /// \param zcenter
  /// \param radius
  ///
  void putSphere(int xcenter, int ycenter, int zcenter, int radius);
  ///
  /// \brief cutSphere
  /// \param xcenter
  /// \param ycenter
  /// \param zcenter
  /// \param radius
  ///
  void cutSphere(int xcenter, int ycenter, int zcenter, int radius);
  ///
  /// \brief putEllipsoid
  /// \param xcenter
  /// \param ycenter
  /// \param zcenter
  /// \param rx
  /// \param ry
  /// \param rz
  ///
  void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
  ///
  /// \brief cutEllipsoid
  /// \param xcenter
  /// \param ycenter
  /// \param zcenter
  /// \param rx
  /// \param ry
  /// \param rz
  ///
  void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
  ///
  /// \brief readMx
  /// \param dim
  /// \param plane
  /// \return
  ///
  std::vector<std::vector<Voxel>> readMx (int dim, int plane);
  ///
  /// \brief writeOFF
  /// \param filename
  ///
  void writeOFF(const std::string filename);
  ///
  /// \brief writeVECT
  /// \param filename
  ///
  void writeVECT(const std::string filename);

  ~Sculptor();
};
#endif // SCULPTOR_H
