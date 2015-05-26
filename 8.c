//CAMERA MOVEMENT
#include<GL/glut.h>

float v[8][3]={{-1,-1,1},{-1,1,1},{1,1,1},{1,-1,1},
				{-1,-1,-1},{-1,1,-1},{1,1,-1},{1,-1,-1}};

float color[8][3]={{-1,-1,1},{-1,1,1},{1,1,1},{1,-1,1},
				{-1,-1,-1},{-1,1,-1},{1,1,-1},{1,-1,-1}};

int cur_axis=2;
void display();
int viewer[3]={0,0,2};
void mykey(unsigned char key,int x,int y)
{
	if(key=='x')viewer[0]--;
	if(key=='X')viewer[0]++;
	if(key=='y')viewer[1]--;
	if(key=='Y')viewer[1]++;
	if(key=='z')viewer[2]--;
	if(key=='Z')viewer[2]++;
	display();
}

void reshape(int w,int h)
{
	glMatrixMode(GL_PROJECTION);
	glFrustum(-2,2,-2,2,2,20);
	glMatrixMode(GL_MODELVIEW);
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
	drawpoly(0,1,2,3);
	drawpoly(0,1,5,4);
	drawpoly(1,5,6,2);
	drawpoly(4,5,6,7);
	drawpoly(3,2,6,7);
	drawpoly(0,4,7,3);
}
void display()
{
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glLoadIdentity();
	gluLookAt(viewer[0],viewer[1],viewer[2],0,0,0,0,1,0);
	colorcube();
	glFlush();
}
void main(int argc,char **argv)
{
        glutInit(&argc,argv);
		glutInitDisplayMode(GLUT_DEPTH);
		glutInitWindowPosition(100,100);
		glutInitWindowSize(500,500);
		glutCreateWindow("cube with camera movement");
		glutDisplayFunc(display);
		glutKeyboardFunc(mykey);
		glutReshapeFunc(reshape);
		glutMainLoop();
}
