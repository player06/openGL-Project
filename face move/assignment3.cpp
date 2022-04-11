#include <windows.h>
#include <gl/gl.h>
#include <gl/glut.h>
#include <ctime>
#include <cstdio>
#include<synchapi.h>
#include<iostream>
#include<sstream>
using namespace std;

void InitGraphics(int argc, char* argv[]);
void SetTransformations();
void OnDisplay();
float rz;
GLboolean flag;
int main(int argc, char* argv[]) {
    InitGraphics(argc, argv);
    return 0;
}

void InitGraphics(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(1020, 720);
    glutCreateWindow("OpenGL Lab");
    glutDisplayFunc(OnDisplay);
    glutMainLoop();
}

void SetTransformations() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-200, 500, -500, 500);
}

void OnDisplay() {

    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    SetTransformations();
    glTranslatef(rz, 0, 0);

    if (rz >= 450 || rz <= -170) {
        flag = !flag;
    }
 
    glBegin(GL_TRIANGLES);

    glColor3f(0, 0, 1);
    glVertex2i(10, 10);
    glColor3f(2, 0, 0);
    glVertex2i(20, 30);
    glColor3f(0, 1, 0);
    glVertex2i(30, 10);
    glEnd();

    //glTranslated(rz, 0, 1);

    glBegin(GL_TRIANGLES);

    glColor3f(1, 0, 1);
    glVertex2i(-10, 10);
    glColor3f(2, 0, 0);
    glVertex2i(-20, 30);
    glColor3f(1, 1, 0);
    glVertex2i(-30, 10);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0, 0, 1);
    glVertex2i(-20, -20);
    glColor3f(1, 0, 1);
    glVertex2i(20, -20);
    glColor3f(0, 1, 1);
    glVertex2i(20, -40);
    glColor3f(1, 0, 0);
    glVertex2i(-20, -40);
    glEnd();


    if (!flag) {
        rz -= 1;
    }
    else {
        rz += 1;
    }

    glFlush();

    glutSwapBuffers();
    glutPostRedisplay();
}