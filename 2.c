//LIANG BARSKY
#include<stdio.h>
#include<GL/glut.h>

float xmin=50,ymin=50,xmax=100,ymax=100;
float xvmin=250,yvmin=250,xvmax=300,yvmax=300;
float tl=1,te=0;
float x0,y0,x1,y1;

int cliptest(float p,float q)
{
	float t;
	t=q/p;
	if(p<0)
	{
		if(t>te)te=t;
		if(t>tl)return false;
	}
	if(p>0)
	{
		if(t<tl)tl=t;
		if(t<te)return false;
	}
	if(p==0)
	{
		if(q<0)	return false;
	}
	return true;
}

void liangbarsky()
{
	float dx=x1-x0;
	float dy=y1-y0;
	if(cliptest(-dx,x0-xmin))
		if(cliptest(dx,xmax-x0))
			if(cliptest(-dy,y0-ymin))
				if(cliptest(dy,ymax-y0))
				{
					if(tl<1)
					{
						x1=x0+tl*dx;
						y1=y0+tl*dy;
					}
					if(te>0)
					{
						x0=x0+te*dx;
						y0=y0+te*dy;
					}
				}
	glColor3f(0,1,0);
	glBegin(GL_LINE_LOOP);
		glVertex2f(xvmin,yvmin);
		glVertex2f(xvmax,yvmin);
		glVertex2f(xvmax,yvmax);
		glVertex2f(xvmin,yvmax);
	glEnd();
	float vx0=x0+200;
	float vy0=y0+200;
	float vx1=x1+200;
	float vy1=y1+200;
	glColor3f(0,1,1);
	glBegin(GL_LINES);
		glVertex2f(vx0,vy0);
		glVertex2f(vx1,vy1);
	glEnd();
}

void myinit()
{
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0,500,0,500);
}

void display()
{

	printf("\nEnter the first point x1,y1\n");
	scanf("%f%f",&x0,&y0);
	printf("\nEnter the second point x2,y2\n");
	scanf("%f%f",&x1,&y1);
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,0,0);
	glBegin(GL_LINE_LOOP);
		glVertex2f(xmin,ymin);
		glVertex2f(xmax,ymin);
		glVertex2f(xmax,ymax);
		glVertex2f(xmin,ymax);
	glEnd();
	glColor3f(0,1,1);
	glBegin(GL_LINES);
		glVertex2f(x0,y0);
		glVertex2f(x1,y1);
	glEnd();
	liangbarsky();
	glFlush();
}

int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(500,500);
	glutCreateWindow("LIANG BARSKY CLIPPING");
	myinit();
	glutDisplayFunc(display);
	glutMainLoop();
}

