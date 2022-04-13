#include <iostream>
#include <windows.h>
#include <gl/gl.h>
#include <gl/glut.h>
#include <ctime>
#include<wingdi.h>
#include <cstdio>   
#include<stdlib.h>
#include<math.h>
#include <iostream>

using namespace std;

inline int Round(const float a) { return int(a + 0.5); }
void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);

    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 300.0, 0.0, 300.0);
}
void setPixel(int xCoordinate, int yCoordinate){
    glBegin(GL_POINTS);
    glVertex2i(xCoordinate, yCoordinate);
    glEnd();
    glFlush();
}
void lineDDA(int x0, int y0, int xEnd, int yEnd)
{
    int dx = xEnd - x0;
    int dy = yEnd - y0;
    int steps, k;
    float xIncrement, yIncrement, x = x0, y = y0;
    if (fabs(dx) > fabs(dy))
        steps = fabs(dx);
    else
        steps = fabs(dy);
    xIncrement = float(dx) / float(steps);
    yIncrement = float(dy) / float(steps);
    setPixel(Round(x), Round(y));
    for (k = 0; k < steps; k++)
    {
        x += xIncrement;
        y += yIncrement;
        setPixel(Round(x), Round(y));
    }
}
void drawMyLine(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    glPointSize(4.0);
    int x;
    int y;
    int xEnd;
    int yEnd;
    cout << "starting vertix" << endl;
    cout << "x: " << endl;
    cin >> x;
    cout << "y0: " << endl;
    cin >> y;
    cout << "ending vertix" << endl;
    cout << "x: " << endl;
    cin >> xEnd;
    cout << "y: " << endl;
    cin >> yEnd;
    lineDDA(x, y, xEnd, yEnd);
}
void main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("(DDA) Algorithm");
    init();
    glutDisplayFunc(drawMyLine);
    glutMainLoop();
}