#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <stdio.h>
#include <iostream>
#include "fisix.h"
#include "drawings.h"
#include "shape.h"
#include "line.h"
#include "list_circle.h"
#include "list_line.h"
#include "drawings.h"

/*****************
 * Initial stuff *
 *****************/

FISIX::FISIX(int windowsizex_in,
             int windowsizey_in)
{
   windowsizex = windowsizex_in;
   windowsizey = windowsizey_in;

   line_objs.insert(new LINE(-0.5, -0.5, 0.5, 0.5));

}

FISIX::~FISIX() {}

/*******************
 * Idle processing *
 *******************/

float gettime(void);

void FISIX::idle(void) {

   /* insert computations here */

   float dt = gettime();

   CIRCLE *circ;

   for (int i = 0; i < circle_objs.N_circle; i++) {

      // extract the current circle from the list
      circ = circle_objs.get_circle();

      // advance the list to the next circle node
      circle_objs.goto_next_circle();

      // update the circle positions, velocity, etc...
      circ->update_acceleration(dt, 0.0, -0.5);

   }

   glutPostRedisplay();

}

/***********
 * Display *
 ***********/

void FISIX::display(void) {

  glClear(GL_COLOR_BUFFER_BIT);

   CIRCLE *circ;

   for (int i = 0; i < circle_objs.N_circle; i++) {

      // extract the current circle from the list
      circ = circle_objs.get_circle();

      // advance the list to the next circle node
      circle_objs.goto_next_circle();

      // draw this circle
      circ->draw();

   }

   LINE *line;

   line = line_objs.get_line();
   line->draw();

   glFlush();
}

/***************
 * Mouse Click *
 ***************/

void FISIX::mouse(
        int button,
        int state,
        int x, /* column number */
        int y) /* row number */
{

/* button
 *    GLUT_LEFT_BUTTON
 *    GLUT_MIDDLE_BUTTON
 *    GLUT_RIGHT_BUTTON
 * state
 *    GLUT_UP
 *    GLUT_DOWN
 *    3 : mouse wheel forward
 *    4 : mouse wheel backward
 */

   int row,col;
   int Nrow = windowsizey;
   int Ncol = windowsizex;

   float xpos,ypos;

   xpos = (float)x/windowsizex * 2.0 - 1.0;
   ypos = 1.0 - 2.0 * (float)y/windowsizey;

   if (button == GLUT_LEFT_BUTTON &&
       state  == GLUT_DOWN)
      circle_objs.insert(new CIRCLE(xpos, ypos));

}
