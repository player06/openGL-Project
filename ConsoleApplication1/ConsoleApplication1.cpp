#include <windows.h>
#include <gl/gl.h>
#include <gl/glut.h>
#include <math.h>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
using namespace std;
float angel;

void InitGraphics(int argc, char* argv[]);
void SetTransformations();
void OnDisplay();

int main(int argc, char* argv[]) {
	InitGraphics(argc, argv);
	return 0;
}

void InitGraphics(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 600);
	glutCreateWindow("OpenGL Lab");
	glutDisplayFunc(OnDisplay);
	glutMainLoop();
	glutIdleFunc(OnDisplay);
	//glutKeyboardFunc(onKeyPress);
}

void SetTransformations() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100, 100, -100, 100);
}
/**/
void Draw(int value, float x, float y, float z) {
	glRasterPos3f(x, y, z);
	string s = to_string(value);
	for (int i = 0; i < s.length(); i++){
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, s.at(i));
	}
}
void OnDisplay() {

	glClearColor(1, 1, 1, 5);
	glClear(GL_COLOR_BUFFER_BIT);

	SetTransformations();

	glBegin(GL_POLYGON);
	glColor3f(1,0,0);
	glVertex2i(-80,80);
	glColor3f(0, 0, 1);
	glVertex2i(-80,-80);
	glColor3f(0, 1, 0);
	glVertex2i(80,-80);
	glColor3f(1, 0, 1);
	glVertex2i(80,80);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glVertex2i(40, 40);
	glColor3f(1, 0, 1);
	glVertex2i(25, 40);
	glVertex2i(25, 25);
	glVertex2i(40, 25);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glVertex2i(-40, 40);
	glColor3f(0, 1, 1);
	glVertex2i(-25, 40);
	glVertex2i(-25, 25);
	glVertex2i(-40, 25);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0, 1, 0);
	glVertex2i(0, 0);
	glVertex2i(-10, -40);
	glVertex2i(10, -40);
	glEnd();


	glBegin(GL_TRIANGLES);
	glColor3f(1, 0, 0);
	glVertex2i(-40, -60);
	glVertex2i(10, -80);
	glVertex2i(50, -60);
	glEnd();
	
	Draw(angel,20,0,0);
	glFlush();

}