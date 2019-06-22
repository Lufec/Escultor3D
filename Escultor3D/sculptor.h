#ifndef SCULPTOR_H
#define SCULPTOR_H
#include <string>
#include <vector>

///
/// \brief The Voxel struct is a representation of a cube with colors and transparency
///
struct Voxel {
    ///
    /// \brief r is the red color of Voxel
    ///
  int r;
  ///
  /// \brief g is the green color of Voxel
  ///
  int g;
  ///
  /// \brief b is the blue color of Voxel
  ///
  int b;
  ///
  /// \brief a is the transparency of Voxel
  ///
  int a;

  ///
  /// \brief isOn determines if the Voxel will be drawn or not
  ///
  bool isOn;
};
///
/// \brief The Sculptor class is used at creating 3D sculptures using Voxels
///
class Sculptor {
protected:
    ///
    /// \brief v is a 3D matrix of Voxels
    ///
  Voxel ***v;
  ///
  /// \brief nx is the X-size of the 3D matrix
  ///
  int nx;
  ///
  /// \brief ny is the Y-size of the 3D matrix
  ///
  int ny;
  ///
  /// \brief nz is the Z-size of the 3D matrix
  ///
  int nz;
  ///
  /// \brief r is the red parameter that will set the red color of a Voxel when it will be called
  ///
  int r;
  ///
  /// \brief g is the green parameter that will set the green color of a Voxel when it will be called
  ///
  int g;
  ///
  /// \brief b is the blue parameter that will set the blue color of a Voxel when it will be called
  ///
  int b;
  ///
  /// \brief a is the alpha parameter that will set the transparency of a Voxel when it will be called
  ///
  int a; // Current drawing color
public:
  ///
  /// \brief Sculptor Constructor creates the 3D matrix, given it's sizes. Dinamycaly allocate memory for this and sets it's initial values of r,g,b,a and IsOn in 0
  /// \param tx is X-size of Sculptor
  /// \param ty is Y-size of Sculptor
  /// \param tz is Z-size of Sculptor
  ///
  Sculptor(int tx,int ty,int tz);
  ///
  /// \brief setColor sets the new r,g,b,a parameters to Sculptor
  /// \param _r red component
  /// \param _g green component
  /// \param _b blue component
  /// \param alpha transparency component
  ///
  void setColor(int _r, int _g, int _b, int alpha);
  ///
  /// \brief putVoxel inserts a single voxel with r,g,b,a defined at setColor. Makes IsOn at given position be true
  /// \param x position X of Voxel
  /// \param y position Y of Voxel
  /// \param z position Z of Voxel
  ///
  void putVoxel(int x, int y, int z);
  ///
  /// \brief cutVoxel removes a single voxel at defined position. Makes IsOn become false
  /// \param x position X of Voxel
  /// \param y position Y of Voxel
  /// \param z position Z of Voxel
  ///
  void cutVoxel(int x, int y, int z);
  ///
  /// \brief putBox inserts a group of voxels at defined parameters. Starts at i0 and goes to i1. Calls function putVoxel
  /// \param x0 beginning of X-size of Box
  /// \param x1 end of X-size of Box
  /// \param y0 beginning of Y-size of Box
  /// \param y1 end of Y-size of Box
  /// \param z0 beginning of Z-size of Box
  /// \param z1 end of Z-size of Box
  ///
  void putBox(int x0, int x1, int y0, int y1, int z0, int z1);
  ///
  /// \brief cutBox removes a group of voxels at defined parameters. Starts at i0 and goes to i1. Calls function cutVoxel
  /// \param x0 beginning of X-size of Box
  /// \param x1 end of X-size of Box
  /// \param y0 beginning of Y-size of Box
  /// \param y1 end of Y-size of Box
  /// \param z0 beginning of Z-size of Box
  /// \param z1 end of Z-size of Box
  ///
  void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
  ///
  /// \brief putSphere inserts a Sphere of voxels at given center and radius. Calls putVoxel
  /// \param xcenter is the x-center of Sphere
  /// \param ycenter is the Y-center of Sphere
  /// \param zcenter is the Z-center of Sphere
  /// \param radius is the radius of Sphere
  ///
  void putSphere(int xcenter, int ycenter, int zcenter, int radius);
  ///
  /// \brief cutSphere removes a Sphere of voxels at given center and radius. Calls cutVoxel
  /// \param xcenter is the x-center of Sphere
  /// \param ycenter is the Y-center of Sphere
  /// \param zcenter is the Z-center of Sphere
  /// \param radius is the radius of Sphere
  ///
  void cutSphere(int xcenter, int ycenter, int zcenter, int radius);
  ///
  /// \brief putEllipsoid inserts an Ellipsoid of voxels at given center and radii. Calls PutVoxel
  /// \param xcenter is the X-center of Ellipsoid
  /// \param ycenter is the Y-center of Ellipsoid
  /// \param zcenter is the Z-center of Ellipsoid
  /// \param rx is the x-radius of Ellipsoid
  /// \param ry is the y-radius of Ellipsoid
  /// \param rz is the z-radius of Ellipsoid
  ///
  void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
  ///
  /// \brief cutEllipsoid removes an Ellipsoid of voxels at given center and radii. Calls cutVoxel
  /// \param xcenter is the X-center of Ellipsoid
  /// \param ycenter is the Y-center of Ellipsoid
  /// \param zcenter is the Z-center of Ellipsoid
  /// \param rx is the x-radius of Ellipsoid
  /// \param ry is the y-radius of Ellipsoid
  /// \param rz is the z-radius of Ellipsoid
  ///
  void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
  ///
  /// \brief readMx creates a 2D matrix of a certain plane of the sculpture.
  /// \param dim indicates which view of the sculpture the user wants to see
  /// \param plane selects which slice of the sculpture the user wants to see, given its dimension
  /// \return 2D matrix at given dimension and plane
  ///
  std::vector<std::vector<Voxel>> readMx (int dim, int plane);
  ///
  /// \brief writeOFF creates an archive with .off format for the user to see it's creation
  /// \param filename is the filepath of archive .off
  ///
  void writeOFF(const std::string filename);
  ///
  /// \brief writeVECT creates an archive with .vect format for the user to see it's creation
  /// \param filename is the filepath of archive .vect
  ///
  void writeVECT(const std::string filename);

  ~Sculptor();
};
#endif // SCULPTOR_H
