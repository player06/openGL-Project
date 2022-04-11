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
	//set the background color to white
	glClearColor(1, 1, 1, 5);
	//fill the whole color buffer with the clear color
	glClear(GL_COLOR_BUFFER_BIT);

	SetTransformations();

	// body
	glBegin(GL_POLYGON);
	
	glColor3f(1, 0, 0);
	glVertex2i(-60,40);
	glVertex2i(60,40);
	glVertex2i(60,-40);
	glVertex2i(-60,-40);
	glEnd();

	// yallow rect
	glBegin(GL_POLYGON);

	glColor3f(1, 1, 0);
	glVertex2i(50, 40);
	glVertex2i(50, 30);
	glVertex2i(60, 30);
	glVertex2i(60, 40);
	glEnd();

	// another yallow rect
	glBegin(GL_POLYGON);

	glColor3f(1, 1, 0);
	glVertex2i(50, -40);
	glVertex2i(50, -30);
	glVertex2i(60, -30);
	glVertex2i(60, -40);
	glEnd();

	// the mid
	glBegin(GL_POLYGON);
	glVertex2i(55, 30);
	glColor3f(0, 1, 1);
	glVertex2i(55, -30);
	glVertex2i(60, -30);
	glColor3f(1, 0, 1);
	glVertex2i(60, 30);
	glEnd();

	// outline  rect
	glLineWidth(3);
	glBegin(GL_LINE_STRIP);
	glColor3f(0, 0, 0);
	glVertex2i(50, 40);
	glVertex2i(50, 30);
	glVertex2i(60, 30);
	glEnd();
	// outline another rect
	glBegin(GL_LINE_STRIP);
	glColor3f(0, 0, 0);
	glVertex2i(50, -40);
	glVertex2i(50, -30);
	glVertex2i(60, -30);
	glEnd();

	// outline mid
	glBegin(GL_LINE_STRIP);
	glColor3f(0, 0, 0);
	glVertex2i(55, 30);
	glVertex2i(55, -30);
	glEnd();

	// the wheels 
	glLineWidth(90);
	glBegin(GL_LINE_STRIP);
	glColor3f(0, 0, 0);
	glVertex2i(35,41);
	glVertex2i(15,41);
	glEnd();

	glLineWidth(90);
	glBegin(GL_LINE_STRIP);
	glColor3f(0, 0, 0);
	glVertex2i(-40, 41);
	glVertex2i(-20, 41);
	glEnd();

	glLineWidth(90);
	glBegin(GL_LINE_STRIP);
	glColor3f(0, 0, 0);
	glVertex2i(35, -41);
	glVertex2i(15, -41);
	glEnd();

	glLineWidth(90);
	glBegin(GL_LINE_STRIP);
	glColor3f(0, 0, 0);
	glVertex2i(-40, -41);
	glVertex2i(-20, -41);
	glEnd();

	// back mid 
	glBegin(GL_POLYGON);
	glColor3f(0, 1, 1);
	glVertex2i(-55, 40);
	glVertex2i(-55, -40);
	glColor3f(1, 0, 1);
	glVertex2i(-60, -40);
	glVertex2i(-60, 40);
	glEnd();

	// mirrors
	glColor3f(1, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2i(-5,40);
	glVertex2i(-5,45);
	glVertex2i(-1,46);
	glVertex2i(2,40);
	glEnd();

	glLineWidth(3);
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_STRIP);
	glVertex2i(-5, 40);
	glVertex2i(-5, 45);
	glVertex2i(-1, 46);
	glVertex2i(2, 40);
	glEnd();

	glColor3f(1, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2i(-5, -40);
	glVertex2i(-5, -45);
	glVertex2i(-1, -46);
	glVertex2i(2, -40);
	glEnd();


	glLineWidth(3);
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_STRIP);
	glVertex2i(-5, -40);
	glVertex2i(-5, -45);
	glVertex2i(-1, -46);
	glVertex2i(2, -40);
	glEnd();

	glColor3f(0, 0, 0);
	glLineWidth(3);
	glBegin(GL_LINE_STRIP);
	glVertex2i(46,30);
	glVertex2i(20,25);
	glEnd();

	glColor3f(0, 0, 0);
	glBegin(GL_LINE_STRIP);
	glVertex2i(46, -30);
	glVertex2i(20, -25);
	glEnd();

	glColor3f(0, 0, 1);
	glBegin(GL_POLYGON);
	glVertex2i(0,20);
	glVertex2i(0,-20);
	glVertex2i(16,-27);
	glVertex2i(16,27);
	glEnd();

	
	glLineWidth(3);
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_STRIP);
	glVertex2i(0, 20);
	glVertex2i(0, -20);
	glVertex2i(16, -27);
	glVertex2i(16, 27);
	glVertex2i(0, 20);
	glEnd();


	glColor3f(0, 0, 0);
	glBegin(GL_LINE_STRIP);
	glVertex2i(-2, 20);
	glVertex2i(-20, 20);
	glVertex2i(-20, -20);
	glVertex2i(-2, -20);
	glEnd();

	glColor3f(0, 0, 1);
	glBegin(GL_POLYGON);
	glVertex2i(-2, 21);
	glVertex2i(-20, 21);
	glVertex2i(-23, 30);
	glVertex2i(3, 30);
	glEnd();

	glColor3f(0, 0, 0);
	glBegin(GL_LINE_STRIP);
	glVertex2i(-2, 21);
	glVertex2i(-20, 21);
	glVertex2i(-23, 30);
	glVertex2i(3, 30);
	glVertex2i(-2, 21);
	glEnd();

	glColor3f(0, 0, 1);
	glBegin(GL_POLYGON);
	glVertex2i(-2, -21);
	glVertex2i(-20,-21);
	glVertex2i(-23,-30);
	glVertex2i(3, -30);
	glEnd();


	glColor3f(0, 0, 0);
	glBegin(GL_LINE_STRIP);
	glVertex2i(-2, -21);
	glVertex2i(-20, -21);
	glVertex2i(-23, -30);
	glVertex2i(3, -30);
	glVertex2i(-2, -21);
	glEnd();

	glColor3f(0, 0, 0);
	glBegin(GL_LINE_STRIP);
	glVertex2i(-21, 20);
	glVertex2i(-26, 36);
	glEnd();

	glColor3f(0, 0, 0);
	glBegin(GL_LINE_STRIP);
	glVertex2i(-21, -20);
	glVertex2i(-26, -36);
	glEnd();

	glColor3f(0, 0, 1);
	glBegin(GL_POLYGON);
	glVertex2i(-21, 20);
	glVertex2i(-33, 20);
	glVertex2i(-33, -20);
	glVertex2i(-21, -20);
	glEnd();

	glColor3f(0, 0, 0);
	glBegin(GL_LINE_STRIP);
	glVertex2i(-21, 20);
	glVertex2i(-33, 20);
	glVertex2i(-33, -20);
	glVertex2i(-21, -20);
	glVertex2i(-21, 20);
	glEnd();

	glColor3f(0, 0, 0);
	glBegin(GL_LINE_STRIP);
	glVertex2i(-34, 20);
	glVertex2i(-50, 34);
	glEnd();

	glColor3f(0, 0, 0);
	glBegin(GL_LINE_STRIP);
	glVertex2i(-34, -20);
	glVertex2i(-50, -34);
	glEnd();

	// outline
	glLineWidth(5);
	glBegin(GL_LINE_LOOP);

	glColor3f(0, 0, 0);
	glVertex2i(-60, 40);
	glVertex2i(60, 40);
	glVertex2i(60, -40);
	glVertex2i(-60, -40);
	glEnd();


	glFlush();

}