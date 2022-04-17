#include<windows.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<stdio.h>
float x1 = 20, y1 = 10;
float x2 = 300, y2 = 180;
void init(void){
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 200.0, 0.0, 150.0);
}
void Draw(void){
	glPointSize(20);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POINTS);
	float dx, dy;
	dx = x2 - x1;
	dy = y2 - y1;
	float xk = x1;
	float yk = y1;
	float p0, pk1;
	p0 = (2 * dy) - dx;
	pk1 = p0;
	glVertex2i(xk, yk);
	for (x1 = 20; x1 <= x2; x1++){
		if (pk1 > 0){
			xk = xk + 1;
			yk = yk + 1;
			pk1 = pk1 + (2 * dy) - (2 * dx);
			glVertex2i(xk, yk);
		}
		else{
			xk = xk + 1;
			yk = yk;
			pk1 = pk1 + (2 * dy);
			glVertex2i(xk, yk);
		}
	}
	glEnd();
	glFlush();
}
void main(int argc, char** argv){

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50, 100);
	glutInitWindowSize(400, 300);
	glutCreateWindow("bresenhams line");
	init();
	glutDisplayFunc(Draw);
	glutMainLoop();
}