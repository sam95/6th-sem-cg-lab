//sierpenski
#include<GL/glut.h>
#include<stdio.h>
int n;

void myinit()
{
	glMatrixMode(GL_PROJECTION); //GL_PROJECTION since the viewing is parallel
	glOrtho(-2,2,-2,2,-2,20); //Six parameters because the program is 3D
}

void triangle(float *a,float *b,float *c) //Displaying the triangle as it is
{
	glBegin(GL_POLYGON);//GL_LINELOOP+COLOURING = GL_POLYGON
		glVertex3fv(a);
		glVertex3fv(b);
		glVertex3fv(c);
	glEnd();
	glFlush();
}
void divide_triangle(float *a,float *b,float *c,int n) //Each side of the triangle has to be divided according to the number of divisions
{
		float v1[3],v2[3],v3[3];
		int j;
		if(n>0)
		{
			for(j=0;j<3;j++)
			{
				v1[j]=(a[j]+b[j])/2;
				v2[j]=(b[j]+c[j])/2;
				v3[j]=(a[j]+c[j])/2;
			}
			divide_triangle(a,v1,v3,n-1);
			divide_triangle(v1,b,v2,n-1);
			divide_triangle(v3,v2,c,n-1);
		}
		else
			triangle(a,b,c); //If the no. of divisions is 0 then display the triangle
}
void tetrahedron()
{
		float tetra[4][3]={{0,1,0},{1,-1,0},{-1,-1,0},{0,0,1}}; //Co-ordinates of the tetrahedron

		glClearColor(1,1,1,1); //Setting the background colour to white
		glClear(GL_COLOR_BUFFER_BIT); //Clearing all the buffer bits
		//Since a tetrahedron is a mixture of 4 triangles the divide triangle is called 4 times
		divide_triangle(tetra[0],tetra[1],tetra[2],n);
		glColor3f(0,1,0);
		divide_triangle(tetra[3],tetra[2],tetra[0],n);
		glColor3f(0,0,1);
		divide_triangle(tetra[3],tetra[0],tetra[1],n);
		glColor3f(1,0,1);
		divide_triangle(tetra[3],tetra[1],tetra[2],n);

}
int main(int argc,char **argv)
{
		printf("Enter the number of divisions\n");
		scanf("%d",&n);
		glutInit(&argc,argv);
        	glutInitWindowSize(500,500);
		glutInitWindowPosition(100,100);
		glutCreateWindow("SIERPINSKI");
		myinit();
		glutDisplayFunc(tetrahedron);
		glutMainLoop();

}
