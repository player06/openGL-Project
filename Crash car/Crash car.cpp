<<<<<<< HEAD
#include <windows.h>
#include <gl/gl.h>
#include <gl/glut.h>
#include <ctime>
#include <cstdio>
#include<synchapi.h>
#include<iostream>
#include<sstream>
#include "cars.h"
#include "power_up.h"
using namespace std;
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")
#pragma comment(lib, "glut32.lib")


void InitGraphics(int argc, char* argv[]);
void SetTransformations();
void Display();
float tile1_movement = -140;
float tile2_movement = -40;
float tile3_movement = 80;
float speed_move = 10.8;
float speed_tiles = 2;
int score = 0;
//float invinc_x ,invinc_y;
float intpart;
float scoref = 0;
float power_up_timerf = 0;
int power_up_timer = 10;
boolean crashed = false;
boolean power_up_nottaken = true;
boolean untouchable = false;
boolean inmenu = true;
int power_up_time = 0;
boolean start = true;
cars good_car(0, -195, 1, 1, 1);
cars enemy_car1(0, 300, 1, 0.5, 0.9);
cars enemy_car2(40, 700, 1, 1, 0);
cars enemy_car3(-40, 600, 0.40, 0.20, 0.90);
power_up invincible(0, 400);
//power_up invincible= new invincible();

int main(int argc, char* argv[]) {
    InitGraphics(argc, argv);
    srand(time(NULL)); 
    return 0;
}

void timer(int value)
{
    const int desiredFPS = 125;
    glutTimerFunc(1000 / desiredFPS, timer, ++value);
    glutPostRedisplay();
}
void restart() {
    good_car.x = 0;
    good_car.y = -195;
    enemy_car1.x = 0;
    enemy_car1.y = 300;
    enemy_car2.x = 40;
    enemy_car2.y = 700;
    enemy_car3.x = -40;
    enemy_car3.y = 600;
    speed_tiles = 2;
    enemy_car1.speed = 2.3;
    enemy_car2.speed = 2.3;
    enemy_car3.speed = 2.3;
    invincible.speed = 1;
    invincible.y = 400;
    speed_move = 20.8;
    score = 0;
    crashed = false;
    invincible.draw = false;

    glutDisplayFunc(Display);

}

void OnKeyPress(unsigned char key, int x, int y) {
    switch (key) {
    case 'a'://		a key
    case 'A':
        if (!inmenu) {
            if (!crashed) {
                if (good_car.x - speed_move > -55) {
                    good_car.x -= speed_move;
                    //sndPlaySound(TEXT("Drifting Car.wav"), SND_ASYNC); // sound line
                    break;
                }

            }
        }
        break;
    case 'd'://		d key
    case 'D':
        if (!inmenu) {
            if (!crashed) {
                if (good_car.x + speed_move < 55) {
                    good_car.x += speed_move;
                    //sndPlaySound(TEXT("Drifting Car.wav"), SND_ASYNC); // sound line
                    break;
                }
            }
        }
        break;

    case 'w'://		d key
    case 'W':
        if (!inmenu) {
            if (!crashed) {
                if (good_car.y + speed_move < 200) {
                    good_car.y += speed_move;


                    break;
                }

            }
        }
        break;
    case 's':
    case 'S':
        if (!inmenu) {
            if (!crashed) {
                if (good_car.y - speed_move > -195) {
                    good_car.y -= speed_move;


                    break;
                }
            }
        }
        break;

    case 'r':
    case 'R':
        if (!inmenu) {
            if (crashed) {
                restart();
            }
        }
        break;


    case 13:
        inmenu = false;
        
        break;

    case 27: // Escape key
        glutDestroyWindow(1);
        exit(0);
        break;

    case 'm':
    case 'M':   
        inmenu = true;
        restart();
        break;

    }




}

void power_up_check() {
    if ((abs(good_car.x - invincible.x) < 40) & (abs(good_car.y - invincible.y) < 70)) {
        invincible.draw = false;
        power_up_nottaken = false;
        invincible.y = 400;
        power_up_time = score + 10;
        untouchable = true;

    }



    //cout << power_up_time << endl;


    else if (score >= power_up_time) {
        //cout << power_up_time << endl;
        untouchable = false;
        power_up_nottaken = true;
    }



}

void InitGraphics(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GL_DOUBLE);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(1020, 720);
    glutCreateWindow("Crash car");
    glutTimerFunc(0, timer, 0);
    glutDisplayFunc(Display);
    sndPlaySound(TEXT("Valorant.wav"), (SND_LOOP,SND_ASYNC)); 
    glutKeyboardFunc(OnKeyPress);
    SetTransformations();
    glutMainLoop();

}

void SetTransformations() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-200, 200, -200, 200);
}

void Drawscore(int score, float x, float y, float z)
{
    glColor3f(1, 1, 1);
    glRasterPos3f(x, y, z);

    string s = "score : " + to_string(score);


    for (int i = 0; i < s.length(); i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, s.at(i));
    }

}

void crash_check() {

    if (((abs(good_car.x - enemy_car1.x) < 23) & (abs(enemy_car1.y + 100) < 25) | //  main car 
        (abs(good_car.x - enemy_car2.x) < 23) & (abs(enemy_car2.y + 100) < 25) |
        (abs(good_car.x - enemy_car3.x) < 23) & (abs(enemy_car3.y + 100) < 25))) {// car 2



        speed_tiles = 0;
        enemy_car1.speed = 0;
        enemy_car2.speed = 0;
        enemy_car3.speed = 0;
        invincible.speed = 0;
        crashed = true;
        if (crashed) {
            glColor3f(0.3, 0.3, 0.3);
            glBegin(GL_QUADS);
            glVertex2f(-40, 30);
            glVertex2f(40, 30);
            glVertex2f(40, -30);
            glVertex2f(-40, -30);
            glEnd();

            glColor3f(1, 1, 1);
            glRasterPos3f(-28, 20, 0);
            string s = "You crashed";
            string s2 = "Esc to exit";
            string s3 = "R to restart";
            string s4 = "M for menu";

            for (int i = 0; i < s.length(); i++)
            {
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, s.at(i));
            }
            glRasterPos3f(-28, 0, 0);
            for (int i = 0; i < s2.length(); i++)
            {
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, s2.at(i));
            }

            glRasterPos3f(-28, -10, 0);
            for (int i = 0; i < s3.length(); i++)
            {
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, s3.at(i));
            }
            glRasterPos3f(-28, -20, 0);
            for (int i = 0; i < s4.length(); i++)
            {
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, s4.at(i));
            }
        }
    }

}

void draw_street() {
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.1, 0.60);
    glVertex2i(-75, 200);
    glVertex2i(75, 200);
    glVertex2i(75, -200);
    glVertex2i(-75, -200);
    glEnd();
}

void draw_tiles() {
    glPushMatrix();
    glTranslatef(0, tile1_movement, 0);
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2i(-25, -200);
    glVertex2i(-30, -200);
    glVertex2i(-30, -120);
    glVertex2i(-25, -120);

    glVertex2i(25, -200);
    glVertex2i(30, -200);
    glVertex2i(30, -120);
    glVertex2i(25, -120);
    glEnd();

    tile1_movement -= speed_tiles;
    if (tile1_movement <= -280) {
        glLoadIdentity();
        tile1_movement = 400;
        glTranslatef(0, tile1_movement, 0);
    }
    glPopMatrix();
    // --------------------------------------------------------------
    //first row tile 2
    //--------------------------------------------------------------
    glPushMatrix();
    glTranslatef(0, tile2_movement, 0);
    glBegin(GL_QUADS);

    glColor3f(1, 1, 1);//cyan
    glVertex2i(-25, -100);
    glVertex2i(-30, -100);
    glVertex2i(-30, -20);
    glVertex2i(-25, -20);

    glVertex2i(25, -100);
    glVertex2i(30, -100);
    glVertex2i(30, -20);
    glVertex2i(25, -20);

    glEnd();
    tile2_movement -= speed_tiles;
    if (tile2_movement <= -280) {
        glLoadIdentity();
        tile2_movement = 400;
        glTranslatef(0, tile2_movement, 0);
    }
    glPopMatrix();
    // --------------------------------------------------------------
    //first row tile 3
    //--------------------------------------------------------------
    glPushMatrix();
    glTranslatef(0, tile3_movement, 0);
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);//cyan
    glVertex2i(-25, 0);
    glVertex2i(-30, 0);
    glVertex2i(-30, 80);
    glVertex2i(-25, 80);

    glVertex2i(25, 0);
    glVertex2i(30, 0);
    glVertex2i(30, 80);
    glVertex2i(25, 80);
    glEnd();
    tile3_movement -= speed_tiles;
    if (tile3_movement <= -280) {
        glLoadIdentity();
        tile3_movement = 400;
        glTranslatef(0, tile3_movement, 0);
    }

    glPopMatrix();
}

void game() {
    // sound line
   
    draw_street();
    draw_tiles();
    good_car.good_car();
    if (untouchable) {
        glPushMatrix();
        glColor3f(1, 0, 0);
        glTranslatef(good_car.x, good_car.y + 190, 0);
        glBegin(GL_LINE_LOOP);
        glVertex2d(-15, -120);
        glVertex2d(0, -115);
        glVertex2d(15, -120);
        glEnd();
        glPopMatrix();
        glColor3f(1, 1, 1);
        glRasterPos3f(150, -160, 0);

        string s = "invincble";
        for (int i = 0; i < s.length(); i++)
        {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, s.at(i));
        }
    
    }

    enemy_car1.enemy_car();
    enemy_car2.enemy_car();
    enemy_car3.enemy_car();

    if (score % 10 == 0 & score != 0) {
        speed_tiles += 0.002;
        enemy_car1.speed += 0.002;
        enemy_car2.speed += 0.002;
        enemy_car3.speed += 0.002;
        speed_move += 0.003;
    }
    Drawscore(score, 150, -190, 0);
    if (!crashed) {
        scoref += 0.01;
        if (modf(scoref, &intpart) < 0.01)
        {
            score += 1;
        }

    }
    invincible.draw_power_up_invincible(score);
    power_up_check();
    if (power_up_nottaken) {
        crash_check();
    }

}
void menu() {
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    draw_street();
    draw_tiles();
    good_car.good_car();

    glColor3f(1.2, 0, 0.2);
    glBegin(GL_QUADS);
    glVertex2f(-60, 110);
    glVertex2f(60, 110);
    glVertex2f(60, 60); 
    glVertex2f(-60, 60);
    glEnd();
    glColor3f(1.90, 1.90, 1.90);
    glBegin(GL_QUADS);
    glVertex2f(-50, 100);
    glVertex2f(50, 100);
    glVertex2f(50, 50);
    glVertex2f(-50, 50);
    glEnd();
    glColor3f(0.2, 0.2, 0.2);
    glBegin(GL_QUADS);
    glVertex2f(-40, -60);
    glVertex2f(40, -60);
    glVertex2f(40, -100);
    glVertex2f(-40, -100);
    glEnd();
    glColor3f(0, 0, 0);
    glRasterPos3f(-20, 70, 0);
    string s1 = "Crash Car";
    string s2 = "* Press Enter to play";
    string s3 = "* press Esc to exit";

    for (int i = 0; i < s1.length(); i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, s1.at(i));
    }


    glColor3f(1, 1, 1);
    glRasterPos3f(-35, -75, 0);
    for (int i = 0; i < s2.length(); i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, s2.at(i));
    }

  
    glRasterPos3f(-35, -90, 0);
    for (int i = 0; i < s3.length(); i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, s3.at(i));
    }
}

void Display() {

   
    if (!inmenu) {
        glClearColor(0, 0, 0, 1);
        glClear(GL_COLOR_BUFFER_BIT);
        game();
    }
    else {
        menu();
    }




    glutSwapBuffers();
=======
#include <windows.h>
#include <gl/gl.h>
#include <gl/glut.h>
#include <ctime>
#include <cstdio>
#include<synchapi.h>
#include<iostream>
#include<sstream>
#include "cars.h"
#include "power_up.h"
using namespace std;
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")
#pragma comment(lib, "glut32.lib")


void InitGraphics(int argc, char* argv[]);
void SetTransformations();
void Display();
float tile1_movement = -140;
float tile2_movement = -40;
float tile3_movement = 80;
float speed_move = 10.8;
float speed_tiles = 2;
int score = 0;
//float invinc_x ,invinc_y;
float intpart;
float scoref = 0;
float power_up_timerf = 0;
int power_up_timer = 10;
boolean crashed = false;
boolean power_up_nottaken = true;
boolean untouchable = false;
boolean inmenu = true;
int power_up_time = 0;
boolean start = true;
cars good_car(0, -195, 1, 1, 1);
cars enemy_car1(0, 300, 1, 0.5, 0.9);
cars enemy_car2(40, 700, 1, 1, 0);
cars enemy_car3(-40, 600, 0.40, 0.20, 0.90);
power_up invincible(0, 400);
//power_up invincible= new invincible();

int main(int argc, char* argv[]) {
    InitGraphics(argc, argv);
    srand(time(NULL)); 
    return 0;
}

void timer(int value)
{
    const int desiredFPS = 125;
    glutTimerFunc(1000 / desiredFPS, timer, ++value);
    glutPostRedisplay();
}
void restart() {
    good_car.x = 0;
    good_car.y = -195;
    enemy_car1.x = 0;
    enemy_car1.y = 300;
    enemy_car2.x = 40;
    enemy_car2.y = 700;
    enemy_car3.x = -40;
    enemy_car3.y = 600;
    speed_tiles = 2;
    enemy_car1.speed = 2.3;
    enemy_car2.speed = 2.3;
    enemy_car3.speed = 2.3;
    invincible.speed = 1;
    invincible.y = 400;
    speed_move = 20.8;
    score = 0;
    crashed = false;
    invincible.draw = false;

    glutDisplayFunc(Display);

}

void OnKeyPress(unsigned char key, int x, int y) {
    switch (key) {
    case 'a'://		a key
    case 'A':
        if (!inmenu) {
            if (!crashed) {
                if (good_car.x - speed_move > -55) {
                    good_car.x -= speed_move;
                    //sndPlaySound(TEXT("Drifting Car.wav"), SND_ASYNC); // sound line
                    break;
                }

            }
        }
        break;
    case 'd'://		d key
    case 'D':
        if (!inmenu) {
            if (!crashed) {
                if (good_car.x + speed_move < 55) {
                    good_car.x += speed_move;
                    //sndPlaySound(TEXT("Drifting Car.wav"), SND_ASYNC); // sound line
                    break;
                }
            }
        }
        break;

    case 'w'://		d key
    case 'W':
        if (!inmenu) {
            if (!crashed) {
                if (good_car.y + speed_move < 200) {
                    good_car.y += speed_move;


                    break;
                }

            }
        }
        break;
    case 's':
    case 'S':
        if (!inmenu) {
            if (!crashed) {
                if (good_car.y - speed_move > -195) {
                    good_car.y -= speed_move;


                    break;
                }
            }
        }
        break;

    case 'r':
    case 'R':
        if (!inmenu) {
            if (crashed) {
                restart();
            }
        }
        break;


    case 13:
        inmenu = false;
        
        break;

    case 27: // Escape key
        glutDestroyWindow(1);
        exit(0);
        break;

    case 'm':
    case 'M':   
        inmenu = true;
        restart();
        break;

    }




}

void power_up_check() {
    if ((abs(good_car.x - invincible.x) < 40) & (abs(good_car.y - invincible.y) < 70)) {
        invincible.draw = false;
        power_up_nottaken = false;
        invincible.y = 400;
        power_up_time = score + 10;
        untouchable = true;

    }



    //cout << power_up_time << endl;


    else if (score >= power_up_time) {
        //cout << power_up_time << endl;
        untouchable = false;
        power_up_nottaken = true;
    }



}

void InitGraphics(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GL_DOUBLE);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(1020, 720);
    glutCreateWindow("Crash car");
    glutTimerFunc(0, timer, 0);
    glutDisplayFunc(Display);
    sndPlaySound(TEXT("Valorant.wav"), (SND_LOOP,SND_ASYNC)); 
    glutKeyboardFunc(OnKeyPress);
    SetTransformations();
    glutMainLoop();

}

void SetTransformations() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-200, 200, -200, 200);
}

void Drawscore(int score, float x, float y, float z)
{
    glColor3f(1, 1, 1);
    glRasterPos3f(x, y, z);

    string s = "score : " + to_string(score);


    for (int i = 0; i < s.length(); i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, s.at(i));
    }

}

void crash_check() {

    if (((abs(good_car.x - enemy_car1.x) < 23) & (abs(enemy_car1.y + 100) < 25) | //  main car 
        (abs(good_car.x - enemy_car2.x) < 23) & (abs(enemy_car2.y + 100) < 25) |
        (abs(good_car.x - enemy_car3.x) < 23) & (abs(enemy_car3.y + 100) < 25))) {// car 2



        speed_tiles = 0;
        enemy_car1.speed = 0;
        enemy_car2.speed = 0;
        enemy_car3.speed = 0;
        invincible.speed = 0;
        crashed = true;
        if (crashed) {
            glColor3f(0.3, 0.3, 0.3);
            glBegin(GL_QUADS);
            glVertex2f(-40, 30);
            glVertex2f(40, 30);
            glVertex2f(40, -30);
            glVertex2f(-40, -30);
            glEnd();

            glColor3f(1, 1, 1);
            glRasterPos3f(-28, 20, 0);
            string s = "You crashed";
            string s2 = "Esc to exit";
            string s3 = "R to restart";
            string s4 = "M for menu";

            for (int i = 0; i < s.length(); i++)
            {
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, s.at(i));
            }
            glRasterPos3f(-28, 0, 0);
            for (int i = 0; i < s2.length(); i++)
            {
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, s2.at(i));
            }

            glRasterPos3f(-28, -10, 0);
            for (int i = 0; i < s3.length(); i++)
            {
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, s3.at(i));
            }
            glRasterPos3f(-28, -20, 0);
            for (int i = 0; i < s4.length(); i++)
            {
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, s4.at(i));
            }
        }
    }

}

void draw_street() {
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.1, 0.60);
    glVertex2i(-75, 200);
    glVertex2i(75, 200);
    glVertex2i(75, -200);
    glVertex2i(-75, -200);
    glEnd();
}

void draw_tiles() {
    glPushMatrix();
    glTranslatef(0, tile1_movement, 0);
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2i(-25, -200);
    glVertex2i(-30, -200);
    glVertex2i(-30, -120);
    glVertex2i(-25, -120);

    glVertex2i(25, -200);
    glVertex2i(30, -200);
    glVertex2i(30, -120);
    glVertex2i(25, -120);
    glEnd();

    tile1_movement -= speed_tiles;
    if (tile1_movement <= -280) {
        glLoadIdentity();
        tile1_movement = 400;
        glTranslatef(0, tile1_movement, 0);
    }
    glPopMatrix();
    // --------------------------------------------------------------
    //first row tile 2
    //--------------------------------------------------------------
    glPushMatrix();
    glTranslatef(0, tile2_movement, 0);
    glBegin(GL_QUADS);

    glColor3f(1, 1, 1);//cyan
    glVertex2i(-25, -100);
    glVertex2i(-30, -100);
    glVertex2i(-30, -20);
    glVertex2i(-25, -20);

    glVertex2i(25, -100);
    glVertex2i(30, -100);
    glVertex2i(30, -20);
    glVertex2i(25, -20);

    glEnd();
    tile2_movement -= speed_tiles;
    if (tile2_movement <= -280) {
        glLoadIdentity();
        tile2_movement = 400;
        glTranslatef(0, tile2_movement, 0);
    }
    glPopMatrix();
    // --------------------------------------------------------------
    //first row tile 3
    //--------------------------------------------------------------
    glPushMatrix();
    glTranslatef(0, tile3_movement, 0);
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);//cyan
    glVertex2i(-25, 0);
    glVertex2i(-30, 0);
    glVertex2i(-30, 80);
    glVertex2i(-25, 80);

    glVertex2i(25, 0);
    glVertex2i(30, 0);
    glVertex2i(30, 80);
    glVertex2i(25, 80);
    glEnd();
    tile3_movement -= speed_tiles;
    if (tile3_movement <= -280) {
        glLoadIdentity();
        tile3_movement = 400;
        glTranslatef(0, tile3_movement, 0);
    }

    glPopMatrix();
}

void game() {
    // sound line
   
    draw_street();
    draw_tiles();
    good_car.good_car();
    if (untouchable) {
        glPushMatrix();
        glColor3f(1, 0, 0);
        glTranslatef(good_car.x, good_car.y + 190, 0);
        glBegin(GL_LINE_LOOP);
        glVertex2d(-15, -120);
        glVertex2d(0, -115);
        glVertex2d(15, -120);
        glEnd();
        glPopMatrix();
        glColor3f(1, 1, 1);
        glRasterPos3f(150, -160, 0);

        string s = "invincble";
        for (int i = 0; i < s.length(); i++)
        {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, s.at(i));
        }
    
    }

    enemy_car1.enemy_car();
    enemy_car2.enemy_car();
    enemy_car3.enemy_car();

    if (score % 10 == 0 & score != 0) {
        speed_tiles += 0.002;
        enemy_car1.speed += 0.002;
        enemy_car2.speed += 0.002;
        enemy_car3.speed += 0.002;
        speed_move += 0.003;
    }
    Drawscore(score, 150, -190, 0);
    if (!crashed) {
        scoref += 0.01;
        if (modf(scoref, &intpart) < 0.01)
        {
            score += 1;
        }

    }
    invincible.draw_power_up_invincible(score);
    power_up_check();
    if (power_up_nottaken) {
        crash_check();
    }

}
void menu() {
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    draw_street();
    draw_tiles();
    good_car.good_car();

    glColor3f(1.2, 0, 0.2);
    glBegin(GL_QUADS);
    glVertex2f(-60, 110);
    glVertex2f(60, 110);
    glVertex2f(60, 60); 
    glVertex2f(-60, 60);
    glEnd();
    glColor3f(1.90, 1.90, 1.90);
    glBegin(GL_QUADS);
    glVertex2f(-50, 100);
    glVertex2f(50, 100);
    glVertex2f(50, 50);
    glVertex2f(-50, 50);
    glEnd();
    glColor3f(0.2, 0.2, 0.2);
    glBegin(GL_QUADS);
    glVertex2f(-40, -60);
    glVertex2f(40, -60);
    glVertex2f(40, -100);
    glVertex2f(-40, -100);
    glEnd();
    glColor3f(0, 0, 0);
    glRasterPos3f(-20, 70, 0);
    string s1 = "Crash Car";
    string s2 = "* Press Enter to play";
    string s3 = "* press Esc to exit";

    for (int i = 0; i < s1.length(); i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, s1.at(i));
    }


    glColor3f(1, 1, 1);
    glRasterPos3f(-35, -75, 0);
    for (int i = 0; i < s2.length(); i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, s2.at(i));
    }

  
    glRasterPos3f(-35, -90, 0);
    for (int i = 0; i < s3.length(); i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, s3.at(i));
    }
}

void Display() {

   
    if (!inmenu) {
        glClearColor(0, 0, 0, 1);
        glClear(GL_COLOR_BUFFER_BIT);
        game();
    }
    else {
        menu();
    }




    glutSwapBuffers();
>>>>>>> 3691c551fabde1c501f6b1e4a196be0cab4d8eea
}