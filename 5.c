//COHEN SUTHERLAND LINE CLIPPING ALGORITHM//
#include<stdio.h>
#include<GL/glut.h>
#define false 0
#define true 1

int top=0x4,bottom=0x1,left=0x2,right=0x8;
float xmin=50,xmax=100,ymin=50,ymax=100;
float xvmin=250,xvmax=300,yvmin=250,yvmax=300;

void myinit()
{
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0,500,0,500);
}

int computecode(float x,float y)
{
	int  code=0000;
	
	if(x<xmin)code=code|left;
	if(x>xmax)code=code|right;
	if(y<ymin)code=code|bottom;
	if(y>ymax)code=code|top;
	return code;
}

void cohensutherland(float x1,float y1,float x2,float y2)
{
	int accept=false,done=false;
	int x,y;
	int p1,p2,outsidepoint;
	p1=computecode(x1,y1);
	p2=computecode(x2,y2);
	float m=(y2-y1)/(x2-x1);
	do{
		if((p1|p2)==0000)
		{
			accept=true;
			done=true;
		}
		else if((p1|p2)!=0000 && (p1&p2)!=0000)
		{
			accept=false;
			done=true;
		}
		else 
		{
			if(p1!=0000)
			{
				outsidepoint=p1;
			}
			else
			{
				outsidepoint=p2;			
			}
			if(outsidepoint&bottom)
			{
				y=ymin;
				x=x1+(ymin-y1)/m;
			}
			if(outsidepoint&top)
			{
				y=ymax;
				x=x1+(ymax-y1)/m;
			}
			if(outsidepoint&right)
			{
				x=xmax;
				y=y1+(xmax-x1)*m;
			}
			if(outsidepoint&left)
			{
				x=xmin;
				y=y1+(xmin-x1)*m;
			}
			if(outsidepoint==p1)
			{
				x1=x;
				y1=y;
				p1=computecode(x1,y1);
			}
			if(outsidepoint==p2)
			{
				x2=x;
				y2=y;
				p2=computecode(x2,y2);
			}
		}
	}while(done==false);
	glColor3f(0,1,0);
	glBegin(GL_LINE_LOOP);
		glVertex2f(xvmin,yvmin);
		glVertex2f(xvmax,yvmin);
		glVertex2f(xvmax,yvmax);
		glVertex2f(xvmin,yvmax);
	glEnd();			
	float vx1=x1+200;
	float vy1=y1+200;
	float vx2=x2+200;
	float vy2=y2+200;
	glColor3f(0,0,0);
	glBegin(GL_LINES);
		glVertex2f(vx1,vy1);
		glVertex2f(vx2,vy2);
	glEnd();
}

void display()
{
	float x1,y1,x2,y2;
	printf("\nEnter the first point x1,y1\n");
	scanf("%f%f",&x1,&y1);
	printf("\nEnter the second point x2,y2\n");
	scanf("%f%f",&x2,&y2);
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,0,0);
	glBegin(GL_LINE_LOOP);
		glVertex2f(xmin,ymin);
		glVertex2f(xmax,ymin);
		glVertex2f(xmax,ymax);
		glVertex2f(xmin,ymax);
	glEnd();			
	glColor3f(0,0,0);
	glBegin(GL_LINES);
		glVertex2f(x1,y1);
		glVertex2f(x2,y2);
	glEnd();
	cohensutherland(x1,y1,x2,y2);
	glFlush();
}

void main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(500,500);
	glutCreateWindow("CLIPPING ALGORITHM");
	myinit();
	glutDisplayFunc(display);
	glutMainLoop();
}
