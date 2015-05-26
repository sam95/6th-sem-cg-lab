//SCAN FILL
#include <GL/glut.h>

int x1=200,y1=200;
int x2=100,y2=300;
int x3=200,y3=400;
int x4=300,y4=300;
int le[500],re[500];

void edgedetect(int x1,int y1,int x2,int y2)
{
	float m,x,temp;
	int i;

	if(y2-y1<0)
	{
		temp=y1;y1=y2;y2=temp;
		temp=x1;x1=x2;x2=temp;
	}
	if(y2-y1!=0)
	{
		m=(x2-x1)/(y2-y1);
	}
	else
	{
		m=x2-x1;
	}
	x=x1;
	for(i=y1;i<=y2;i++)
	{
		if(x<le[i]) le[i]=x;
		if(x>re[i]) re[i]=x;
		x=x+m;
	}
}

void draw_pixel(int m,int n)
{
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_POINTS);
		glVertex2i(m,n);
	glEnd();
}

void scanfill()
{
	int x,y;
	int i;
	for(i=0;i<500;i++)
	{
		le[i]=500;
		re[i]=0;
	}
	edgedetect(x1,y1,x2,y2);
	edgedetect(x2,y2,x3,y3);
	edgedetect(x3,y3,x4,y4);
	edgedetect(x4,y4,x1,y1);
	for(y=0;y<500;y++)
	{
		for(x=le[y];x<=re[y];x++)
		{
			draw_pixel(x,y);
			//sleep(1);
		}
	}
}

void display()
{
	 glClearColor(1,1,1,1);
     glClear(GL_COLOR_BUFFER_BIT);
	 glColor3f(0,0,1);
	 glBegin(GL_LINE_LOOP);
		glVertex2f(x1,y1);
		glVertex2f(x2,y2);
		glVertex2f(x3,y3);
		glVertex2f(x4,y4);
	glEnd();

	scanfill();
	glFlush();
}

void myinit()
{
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,500,0,500);
}

void main(int argc,char **argv)
{
    glutInit(&argc,argv);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("SCAN LINE FILL");
	glutDisplayFunc(display);
	myinit();
	glutMainLoop();
}
