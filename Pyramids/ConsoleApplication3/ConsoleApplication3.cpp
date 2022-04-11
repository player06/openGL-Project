#include <windows.h>
#include <gl/gl.h>
#include <gl/glut.h>
#include<math.h>

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
}

void SetTransformations() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100, 100, -100, 100);
}

void OnDisplay() {

	glClearColor(1, 1, 1, 5);
	glClear(GL_COLOR_BUFFER_BIT);

	SetTransformations();

	glLineWidth(9);
	glBegin(GL_LINE_LOOP);
	glColor3f(0,0,0);
	glVertex2i(-30,0);
	glVertex2i(-20,60);
	glVertex2i(-10,0);
	glEnd();
	
	glBegin(GL_TRIANGLES);
	glColor3f(1,0,0);
	glVertex2i(-30, 0);
	glVertex2i(-20, 60);
	glVertex2i(-10, 0);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0, 1, 0);
	glVertex2i(-13, 0);
	glVertex2i(-2, 40);
	glVertex2i(9, 0);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0, 0, 12);
	glVertex2i(3, 0);
	glVertex2i(18, 20);
	glVertex2i(30, 0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 1, 1);

	glVertex2i(50, 0);
	glVertex2i(-50, 0);
	glVertex2i(-50, -30);
	glVertex2i(50, -30);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 1, 0);

	glVertex2i(50, 50);
	glVertex2i(70, 50);
	glVertex2i(70, 70);
	glVertex2i(50, 70);
	glEnd();

	glFlush();

}

