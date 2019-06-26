# 3D Sculptor

This project enables an user to create 3D sculptures made from 3D pixels, in this project called Voxels.
The user can choose between 4 types of geometric figures to put or cut in his sculpture. 
The final result can be saved in formats .off and .vect.
If the user wants to use in it's computer, he/she will need to just change the paths of the OFF and VECT files on the plotter.cpp part , in SLOTS Show OFF, Show VECT and SAVE ALL.

## Interface
 
 The user interface consists in 7 parts:
 
 <img src="https://user-images.githubusercontent.com/30414428/60138963-8e45ea00-9782-11e9-91d9-6b53603a4bca.png" width="500px;">
 
 1) The selected matrix (middle): it's the 2D representation part of a 3D cube. All modifications will occur at this part of a cube;
 2) Geometric Figures Toolbar: user can select which geometric figure he/she wants to add. Order (up to down): Put Voxel, Cut Voxel, Put Box, Cut Box, Put Sphere, Cut Sphere, Put Ellipsoid and Cut Ellipsoid.
 3) Visualization toolbar (top left): it can rotate the matrix/cube if the user feels the need, can invert the cube visualization and change which plane he/she wants to see. Order (Left to Right): Rotate Clock-wise, Rotate Counter Clock-wise, Invert, Change to plan XY, change to plan ZX, change to plan YZ;
 4) Execution and save toolbar (top right): this allows the user to visualize it's work, save what is made and create a new sculpture. Order (left to right) : Show off result, show vect result, save both and new box.
 5) Sizes and color selection (Left): this part let's the user change the parameters of any geometric figure he/she puts on the sculptor. Order (up to down): change box sizes (X,Y,Z), change Sphere Radius, change Ellipsoid Radii (X, Y, Z), change colors (Red, Green, Blue, Transparency).
 6) Slice selection (between matrix and size selectors): used to change which slice of a cube the user will work on.
 7) Details and current selected things (bottom): it's whre the user will see which square he clicked, shaped selected and the size of the current box.
 
## Types of Geometric Figures

There are a total of 4 figures with 2 actions each.

### Put Voxel


 To put a single Voxel, the user must choose the first box of GF (geometric figures) toolbar called "PutVoxel", select the color (he can see which color is chosen at the side of the sliders) and click on any part of the matrix. If the user click and hold the button, all the way that the cursor moves will be filled with Voxels.

 <img src="https://user-images.githubusercontent.com/30414428/60138959-8dad5380-9782-11e9-8a80-6bc42c4d74b1.png" width="500px;">
  
### Cut Voxel

Now, if you want to remove a voxel, just click the second box called "CutVoxel". No need to choose color nor dimensions. 

<img src="https://user-images.githubusercontent.com/30414428/60147529-243e3c80-97a4-11e9-9d70-460c54728e17.png" width="500px;">

### Put Box

If you want to put a box, you need to select the "PutBox" option (GF toolbar), set the sizes desired (shown below) and the color of the box (also shown below). All Boxes actions , when clicked on the matrix, will set that point as the top-left-front part of the cube.

 <img src="https://user-images.githubusercontent.com/30414428/60138956-8dad5380-9782-11e9-8ac3-41d06f0dcbca.png" width="500px;">
 
### Cut Box

To remove a Box, you just need to select CutBox, chose a size and click on the desired spot. 

 <img src="https://user-images.githubusercontent.com/30414428/60138948-871edc00-9782-11e9-91fa-1b52811c2089.png" width="500px;">
 
### Put Sphere

To put a Sphere, the user must select PutSphere, set the desired radius and choose the color. All spheres actions creates a sphere at it's center.

 <img src="https://user-images.githubusercontent.com/30414428/60138958-8dad5380-9782-11e9-9aaa-1963e54b6327.png" width="500px;">
 
### Cut Sphere

To cut a sphere, you just need to select CutSphere and set the radius.

 <img src="https://user-images.githubusercontent.com/30414428/60138950-871edc00-9782-11e9-989d-4807c0a2747b.png" width="500px;">
 
### Put Ellipsoid

For the ellipsoid you need to select PutEllipsoid, set it's x,y and z radii, and choose the color. All ellipses putted or cutted are made at the x,y and z center of where the user clicked.

 <img src="https://user-images.githubusercontent.com/30414428/60138957-8dad5380-9782-11e9-9c1f-708b930878dd.png" width="500px;">
 
### Cut Ellipsoid

To cut, you just need to select CutEllipsoid and its size.

 <img src="https://user-images.githubusercontent.com/30414428/60138949-871edc00-9782-11e9-9030-ebac49c52a17.png" width="500px;">
 
## Rotating Functions

If the user wants to rotate or change a visualization, he can perform various operations. 
On the image below, the rectangle is at it's original plane.

<img src="https://user-images.githubusercontent.com/30414428/60138964-8ede8080-9782-11e9-8f49-1e78997ee090.png" width="500px;">

### Rotate Clock Wise

If the user clicks this button, the figure will rotate Clock-wise.

 <img src="https://user-images.githubusercontent.com/30414428/60138961-8e45ea00-9782-11e9-8d3a-6dd19e116e09.png" width="500px;">
 
### Rotate Counter Clock Wise


If the user clicks this button, the figure will rotate counter Clock-wise.

 <img src="https://user-images.githubusercontent.com/30414428/60138960-8e45ea00-9782-11e9-99af-16b253159357.png" width="500px;">

### Plane Changes XY, ZX, YZ

The default plane when started is the XY, but if the user wants to work on another plane, he can click on one of these 3 options. All planes can be rotated and inverted as the user whishes.

## Functions 

There are 4 main functions: Showw off, show vect, save all and new Box.

### Show OFF 

On the top right, there is an icon written "Show OFF". This will execute a temporary file with the format OFF of the created Sculpture. Example of our created Sculpture Below.

 <img src="https://user-images.githubusercontent.com/30414428/60138951-871edc00-9782-11e9-90d8-fff7709b0a59.png" width="500px;">
 
 Show VECT follows the same principle, but it opens the vect file.

### Save

This will save the sculpture in both formats: vect and off. The saved files will be on the main code paste.


### New Box Sculptor

If the user wishes to work on a different box, he need to choose the  "NEW" option. A window will pop up with 3 sliders: X, Y and Z axis. When the user chooses his desired dimensions and check the "ok" box, the old sculptor is deleted and a new one is created.

 <img src="https://user-images.githubusercontent.com/30414428/60147530-243e3c80-97a4-11e9-90d6-805d978daadd.png" width="500px;">


