#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <stdio.h>
#include <iostream>
#include "fisix.h"
#include "drawings.h"

FISIX::FISIX() {}
FISIX::~FISIX() {}

void FISIX::display(void) {

  glClear(GL_COLOR_BUFFER_BIT);

   /* insert gl drawings stuffs here */
   draw_circle(
          0.5,
          0.25,
          0.25);

   glFlush();

}

void FISIX::idle(void) {

   /* insert computations here */

   glutPostRedisplay();

}
