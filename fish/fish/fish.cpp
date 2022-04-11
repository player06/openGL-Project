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


	glBegin(GL_LINES);
	glColor3f(0, 1, 0);
	// X-axis
	glVertex3f(-100, 0, 0);
	glVertex3f(100, 0, 0);
	//Y-axis
	glVertex3f(0, -100, 0);
	glVertex3f(0, 100, 0);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1,1,0);
	glVertex2i(-80,0);
	glVertex2i(-20,90);
	glVertex2i(-20,-30);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1,0,0);
	glVertex2i(-60,15);
	glVertex2i(-50,15);
	glVertex2i(-50,0);
	glVertex2i(-60,0);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0, 0, 1);
	glVertex2i(-20,90);
	glVertex2i(10,90);
	glVertex2i(10,100);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0, 0, 1);
	glVertex2i(-20,-30);
	glVertex2i(10,-40);
	glVertex2i(10,0);
	glEnd();
	

	glBegin(GL_POLYGON);
	glColor3f(1,0,0);
	glVertex2i(-20, 90);
	glVertex2i(-20, -30);
	glVertex2i(10, 0);
	glVertex2i(29, 26);
	glVertex2i(29, 70);
	glVertex2i(10, 90);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0,0,1);
	glVertex2i(29,26);
	glVertex2i(40,15);
	glVertex2i(40,80);
	glVertex2i(29,70);
	glEnd();

	glFlush();

}

