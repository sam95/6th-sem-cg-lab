//MY CUBE ROTATION
#include<GL/glut.h>

float v[8][3]={{-1,-1,1},{-1,1,1},{1,1,1},{1,-1,1},
				{-1,-1,-1},{-1,1,-1},{1,1,-1},{1,-1,-1}};

float color[8][3]={{-1,-1,1},{-1,1,1},{1,1,1},{1,-1,1},
				{-1,-1,-1},{-1,1,-1},{1,1,-1},{1,-1,-1}};

float theta[3]={0,0,0};
int cur_axis=0;
void display();

void myinit()
{
	glMatrixMode(GL_PROJECTION);
	glOrtho(-2,2,-2,2,-2,2);
	glMatrixMode(GL_MODELVIEW);
}

void idlefunc()
{
	theta[cur_axis]=theta[cur_axis]+0.1;
	if(theta[cur_axis]>360)theta[cur_axis]=0;
	display();
}
void mousefunc(int button,int status,int x,int y)
{
	if(button==GLUT_LEFT_BUTTON&&status==GLUT_DOWN)
		cur_axis=2;
	if(button==GLUT_MIDDLE_BUTTON&&status==GLUT_DOWN)
		cur_axis=1;
	if(button==GLUT_RIGHT_BUTTON&&status==GLUT_DOWN)
		cur_axis=0;

}
void drawpoly(int a,int b,int c,int d)
{
	glBegin(GL_POLYGON);
		glColor3fv(color[a]);
		glVertex3fv(v[a]);
		glColor3fv(color[b]);
		glVertex3fv(v[b]);
		glColor3fv(color[c]);
		glVertex3fv(v[c]);
		glColor3fv(color[d]);
		glVertex3fv(v[d]);
	glEnd();
}
void colorcube()
{
	drawpoly(0,3,2,1);
	drawpoly(1,2,6,5);
	drawpoly(0,4,7,3);
	drawpoly(2,3,7,6);
	drawpoly(0,1,5,4);
	drawpoly(4,5,6,7);
}
void display()
{
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT );
	glEnable(GL_DEPTH_TEST);
	glLoadIdentity();
	glRotatef(theta[0],1,0,0);
	glRotatef(theta[1],0,1,0);
	glRotatef(theta[2],0,0,1);
	colorcube();
	glFlush();

}
void main()
{
		glutInitDisplayMode(GLUT_DEPTH);
		glutInitWindowPosition(100,100);
		glutInitWindowSize(500,500);
		glutCreateWindow("cube rotation");
		myinit();
		glutDisplayFunc(display);
		glutMouseFunc(mousefunc);
		glutIdleFunc(idlefunc);
		glutMainLoop();
}
