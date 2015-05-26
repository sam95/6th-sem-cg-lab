//CYLINDER  AND PARALLELOPIPED
#include <GL/glut.h>

void glow_pixel(int m,int n)
{
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_POINTS);
		glVertex2i(m,n);
	glEnd();
	glFlush();
}

void symmetry(int h,int k,int x,int y)
{
	glow_pixel(x+h,y+k);
	glow_pixel(-x+h,y+k);
	glow_pixel(x+h,-y+k);
	glow_pixel(-x+h,-y+k);
	glow_pixel(y+h,x+k);
	glow_pixel(-y+h,x+k);
	glow_pixel(y+h,-x+k);
	glow_pixel(-y+h,-x+k);
}

void circle(int h,int k,int r)
{
	int x=0;
	int y=r;
	int d=1-r;
	symmetry(h,k,x,y);
	while(y>x)
	{
		if(d<0)
		{ 
			x=x+1;
			y=y;
			symmetry(h,k,x,y);
			d=d+2*x+3;
		}
		else
		{
			x=x+1;
			y=y-1;
			symmetry(h,k,x,y);
			d=d+2*(x-y)+5;
		}
	}
}

void cylinder()
{
	int h=100;
	int k=100;
	int r=50;
	int i;
	for(i=1;i<=50;i++)
	{
		circle(h+i,k+i,r);
	}

}

void rectangle(int x1,int y1,int x2,int y2)
{
	glColor3f(0,0,1);
	glBegin(GL_LINE_LOOP);
		glVertex2i(x1,y1);
		glVertex2i(x2,y1);
		glVertex2i(x2,y2);
		glVertex2i(x1,y2);
	glEnd();
	glFlush();
}

void parellopiped()
{
	int x1=300;
	int y1=200;
	int x2=400;
	int y2=300;
	int i;
	for(i=1;i<=50;i=i+3)
	{
		rectangle(x1+i,y1,x2+i,y2);
	}
}

void myinit()
{
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,1000,0,1000);
}

void cyl_parl()
{
	glClearColor(1,1,1,1);
        glClear(GL_COLOR_BUFFER_BIT); 
	cylinder();
	parellopiped();
}

void main()
{
	glutInitWindowSize(300, 300); 
	glutInitWindowPosition(100,100); 
	glutCreateWindow("Cylinder and parellopiped"); 
	glutDisplayFunc(cyl_parl); 
	myinit();
	glutMainLoop(); 
}
