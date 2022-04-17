#include<windows.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<stdio.h>
#include <iostream>

void init(void){
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 300.0, 0.0, 300.0);
}

void setpixel(GLint xplot, GLint yplot){
	glBegin(GL_POINTS);
	glVertex2i(xplot, yplot);
	glEnd();
	glFlush();
}

void midpointcircle(GLint xc, GLint yc, GLint r){
	int x = 0, y = r, p = 1 - r;
	void circleplotpoints(int, int, int, int);

	while (x < y){
		x++;
		if (p < 0)
			p += 2 * (x + 1);
		else{
			y--;
			p += 2 * (x - y) + 1;
			circleplotpoints(xc, yc, x, y);
		}
	}
}
void draw(){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.2, 3.4);
	glPointSize(10);
	GLint xc = 90;
	GLint yc = 70;
	GLint r = 20;
	midpointcircle(xc, yc, r);
}
void circleplotpoints(GLint xc, GLint yc, GLint x, GLint y){
	setpixel(xc + x, yc + y);
	setpixel(xc - x, yc + y);
	setpixel(xc + x, yc - y);
	setpixel(xc - x, yc - y);
	setpixel(xc + y, yc + x);
	setpixel(xc - y, yc - x);
	setpixel(xc + y, yc - x);
	setpixel(xc - y, yc + x);
}

void main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(500, 500);
	glutCreateWindow("circle");

	init();
	glutDisplayFunc(draw);
	glutMainLoop();
}