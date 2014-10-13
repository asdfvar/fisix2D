#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <stdio.h>
#include <iostream>
#include "drawings.h"
#include "fisix.h"

int windowsizex = 1200;
int windowsizey = 1000;

FISIX program(windowsizex, windowsizey);

/*********************
 * Display to screen *
 *********************/

void display(void) {

program.display();

}

/*******************
 * Idle processing *
 *******************/

void idle(void) {

program.idle();

}

/***************
 * Mouse click *
 ***************/

void mouse(
        int button,
        int state,
        int x,
        int y)
{

/*
   button
      GLUT_LEFT_BUTTON
      GLUT_MIDDLE_BUTTON
      GLUT_RIGHT_BUTTON
   state
      GLUT_UP
      GLUT_DOWN
*/

program.mouse(button, state, x, y);

}

void mouseMotion(int x, int y) {

   std::cout << "x = " << x << std::endl;
   std::cout << "y = " << y << std::endl;

   program.mouseMotion(x, y);
}
#if 0
void mousePassive(int x, int y) {

   std::cout << "x = " << x << std::endl;
   std::cout << "y = " << y << std::endl;
}
#endif

/********
 * Main *
 ********/

int main(int argc, char** argv) {

   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
   glutInitWindowSize(windowsizex, windowsizey);
   glutInitWindowPosition(50, 50);
   glutCreateWindow("2D Physics Sim");

   glutDisplayFunc(display);
   glutMouseFunc(mouse);
   glutMotionFunc(mouseMotion);
//   glutPassiveMotionFunc(mousePassive);
#if 0
   glutKeyboardUpFunc(keyboardUp);
   glutKeyboardFunc(keyboardDown);
#endif
   glutIdleFunc(idle);

   glutMainLoop();

  return 0;
}
