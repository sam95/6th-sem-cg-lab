//HOUSE
#include<stdlib.h>
#include<GL/glut.h>
#include<math.h>
#include<stdio.h>
float house[3][9]={
{100,100,175,250,250,150,150,200,200},
{100,300,400,300,100,100,150,150,100},
{1,1,1,1,1,1,1,1,1} // to depict all are points
};

float rot_mat[3][3];
float newhouse[3][9];
float h=100;
float k=100;
float theta=0.0;
void multiply()
{
	int i,j,k;

	for(i=0;i<3;i++)
	{
		for(j=0;j<9;j++)
		{
			newhouse[i][j]=0;
			for(k=0;k<3;k++)
			{
				newhouse[i][j]=newhouse[i][j]+rot_mat[i][k]*house[k][j];
			}
		}
	}
}
void prep_rotate_mat()
{
	float m,n;
	m=-h*(cos(theta)-1)+k*(sin(theta));
	n=-k*(cos(theta)-1)-h*(sin(theta));

	rot_mat[0][0]=cos(theta);
	rot_mat[0][1]=-sin(theta);
	rot_mat[0][2]=m;

	rot_mat[1][0]=sin(theta);
	rot_mat[1][1]=cos(theta);
	rot_mat[1][2]=n;

	rot_mat[2][0]=0;
	rot_mat[2][1]=0;
	rot_mat[2][2]=1;
}


void drawhouse()
{
	glColor3f(1,0,0);
	glBegin(GL_LINE_LOOP);
		glVertex2f(house[0][0],house[1][0]);
		glVertex2f(house[0][1],house[1][1]);
		glVertex2f(house[0][3],house[1][3]);
		glVertex2f(house[0][4],house[1][4]);
	glEnd();

	glBegin(GL_LINE_LOOP);
		glVertex2f(house[0][5],house[1][5]);
		glVertex2f(house[0][6],house[1][6]);
		glVertex2f(house[0][7],house[1][7]);
		glVertex2f(house[0][8],house[1][8]);
	glEnd();

	glBegin(GL_LINE_LOOP);
		glVertex2f(house[0][1],house[1][1]);
		glVertex2f(house[0][2],house[1][2]);
		glVertex2f(house[0][3],house[1][3]);

	glEnd();
}
void drawrotatedhouse()
{
	glColor3f(0,1,0);
	glBegin(GL_LINE_LOOP);
		glVertex2f(newhouse[0][0],newhouse[1][0]);
		glVertex2f(newhouse[0][1],newhouse[1][1]);
		glVertex2f(newhouse[0][3],newhouse[1][3]);
		glVertex2f(newhouse[0][4],newhouse[1][4]);
	glEnd();

	glBegin(GL_LINE_LOOP);
		glVertex2f(newhouse[0][5],newhouse[1][5]);
		glVertex2f(newhouse[0][6],newhouse[1][6]);
		glVertex2f(newhouse[0][7],newhouse[1][7]);
		glVertex2f(newhouse[0][8],newhouse[1][8]);
	glEnd();

	glBegin(GL_LINE_LOOP);
		glVertex2f(newhouse[0][1],newhouse[1][1]);
		glVertex2f(newhouse[0][2],newhouse[1][2]);
		glVertex2f(newhouse[0][3],newhouse[1][3]);

	glEnd();
}

void display()
{
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);

	drawhouse();
	prep_rotate_mat();
	multiply();
	drawrotatedhouse();
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
	printf("Enter the rotation angle\n");
	scanf("%f",&theta);
	theta=theta*3.141/180.0;
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("House Rotation1");
	myinit();
	glutDisplayFunc(display);
	glutMainLoop();
}
