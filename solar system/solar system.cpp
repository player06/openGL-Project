#include <iostream>
#include <windows.h>
#include <gl/gl.h>
#include <gl/glut.h>
#include <ctime>
#include <cstdio>
using namespace std;
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")
#pragma comment(lib, "glut32.lib")

// Global Variables ***/
UINT prevFrameTime = -1;
float sunAngle = 0;
float earthAngle = 0;
float moonAngle = 0;

//Creates the main window, registers event handlers, and
//initializes OpenGL stuff.
void InitGraphics(int argc, char* argv[]);


//Sets the logical coordinate system we will use to specify
//our drawings.
void SetTransformations() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100, 100, -100, 100);
}

void Update()
{
	UINT currTime = GetTickCount64();
	//the first update?
	if (prevFrameTime == -1) {
		prevFrameTime = currTime;
		return;
	}
	float dt = (currTime - prevFrameTime) / 1000.0;
	sunAngle += 45 * dt;
	moonAngle += 255 * dt;
	earthAngle -= 90 * dt;
	prevFrameTime = currTime;

}

void OnDisplay() {
	//set the background color to Black
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	SetTransformations();

	//The Sun (Yellow)

	glTranslatef(10,10,0);
	glRotatef(sunAngle, 0, 0, 1);
	glBegin(GL_QUADS);
	glColor3f(1, 1, 0);
	glVertex3f(10, 10, 0);
	glVertex3f(-10, 10, 0);
	glVertex3f(-10, -10, 0);
	glVertex3f(10, -10, 0);
	glEnd();

	//The Earth (Blue)
	glRotatef(earthAngle, 0, 0, 1);
	glTranslatef(35, 35, 0);
	
	glBegin(GL_QUADS);
	glColor3f(0, 0, 1);
	glVertex3f(5, 5, 0);
	glVertex3f(-5, 5, 0);
	glVertex3f(-5, -5, 0);
	glVertex3f(5, -5, 0);
	glEnd();

	//The Moon (white)
	glRotatef(moonAngle, 0, 0, 1);
	glTranslatef(14, 14, 0);
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex3f(2.5, 2.5, 0);
	glVertex3f(-2.5, 2.5, 0);
	glVertex3f(-2.5, -2.5, 0);
	glVertex3f(2.5, -2.5, 0);
	glEnd();

	glutSwapBuffers();
	Update();
	glutPostRedisplay();
}


int main(int argc, char* argv[]) {
	InitGraphics(argc, argv);
	return 0;
}
void InitGraphics(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Solar System");
	glutDisplayFunc(OnDisplay);

	glutMainLoop();
}
