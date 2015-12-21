To install OpenGL on your computer, Follow the Below Instructions
For Ubuntu/Fedora/Any Unix Operating systems, type these below commands on the terminal

1. sudo apt-get install freeglut3 freeglut3-dev
2. sudo apt-get install binutils-gold
3. You're Done!

For Windows users, to set up OpenGL on Codeblocks, first Install codeblocks on your machine and follow the below steps

1. copy the glut32.dll to c:\windows\system
2. copy the glut32.lib to c:\\program files\mingw\lib
3. copy glut.h to c:\program files\mingw\include\GL
4. Add behaviour to linker settings in codeblocks!
5. You're done!

Advice : Use Unix operating systems to avoid complexity
to Run the file on codeblocks just click on Build and run

To run the file on the terminal(Unix) type

gcc -lGL -glut filename.c
./a.out


Design, develop, and implement the following programs in C / C++

1. Program to recursively subdivide a tetrahedron to from 3DSierpinski gasket. The number of recursive steps is to be specifiedby the user.

2. Program to implement Liang-Barsky line clipping algorithm.

3. Program to draw a color cube and spin it using OpenGLtransformation matrices.

4. Program to create a house like figure and rotate it about a givenfixed point using OpenGL functions.

5. Program to implement the Cohen-Sutherland line-clippingalgorithm. Make provision to specify the input line, window forclipping and view port for displaying the clipped image.

6. Program to create a cylinder and a parallelepiped by extruding acircle and quadrilateral respectively. Allow the user to specify thecircle and the quadrilateral.

7. Program, using OpenGL functions, to draw a simple shaded sceneconsisting of a tea pot on a table. Define suitably the position andproperties of the light source along with the properties of theproperties of the surfaces of the solid object used in the scene.

8. Program to draw a color cube and allow the user to move the camerasuitably to experiment with perspective viewing. Use OpenGLfunctions.

9. Program to fill any given polygon using scan-line area fillingalgorithm. (Use appropriate data structures.)

10. Program to display a set of values {fij} as a rectangular mesh.
