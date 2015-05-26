//RECTANGULAR MESH//
#include <stdlib.h>
#include <GL/glut.h>
int maxx=20;
int maxy =25;
int dx=15;
int dy=10;
int x[20];
int y[25];
int x0=50,y0=50;
int i,j;

void myinit()
{
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,500,0,500);
}

void mesh()
{
     glClearColor(1,1,1,1);
     glClear(GL_COLOR_BUFFER_BIT);

	for(i=0;i<maxx;i++)
	{
	         x[i] = x0 + i*dx;
	}
	for(j=0;j<maxy;j++)
	{
        	 y[j] = y0 + j*dy;
	}
        for(i=0;i<maxx-1;i++)
	{
		for(j=0;j<maxy-1;j++)
		{
				glColor3f(0.0, 0.0, 1.0);
				glBegin(GL_LINE_LOOP);
					glVertex2i(x[i],y[j]);
					glVertex2i(x[i],y[j+1]);
					glVertex2i(x[i+1],y[j+1]);
					glVertex2i(x[i+1],y[j]);
				glEnd();
				glFlush();
		}
	 }
}

void main(int argc,char **argv)
{
    glutInit(&argc,argv);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Rectangular Mesh");
	glutDisplayFunc(mesh);
	myinit();
	glutMainLoop();
}

