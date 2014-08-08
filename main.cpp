#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <stdio.h>
#include <iostream>
#include "drawings.h"
#include "fisix.h"

FISIX program;

void display(void) {

program.display();

}

void idle(void) {

program.idle();

}


int main(int argc, char** argv) {

   int windowsizex = 800;
   int windowsizey = 800;

   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
   glutInitWindowSize(windowsizex, windowsizey);
   glutInitWindowPosition(50, 50);
   glutCreateWindow("2D Physics Sim");

   glutDisplayFunc(display);
#if 0
   glutKeyboardUpFunc(keyboardUp);
   glutKeyboardFunc(keyboardDown);
   glutMouseFunc(mouseclick);
   glutPassiveMotionFunc(mousePassive);
   glutMotionFunc(mouseMotion);
#endif
   glutIdleFunc(idle);

   glutMainLoop();

  return 0;
}
