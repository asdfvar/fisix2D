#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <stdio.h>
#include <iostream>
#include <cmath>
#include "fisix.h"
#include "drawings.h"
#include "shape.h"
#include "line.h"
#include "tools.h"
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

   activeClick = false;
   activeP1x   = 0;
   activeP1y   = 0;
   activeP2x   = 0;
   activeP2y   = 0;

}

FISIX::~FISIX() {}

/*********************************
 * Idle processing               *
 *********************************
 * for updating and calculations *
 * and such                      *
 *********************************/

float gettime(void);
float waitUntil(float dt);

void FISIX::idle(void) {

   /* insert computations here */

   float dt = waitUntil(0.005);

   CIRCLE *circle, *otherCircle;
   LINE   *line;

   // determine interactions with lines
   for (int iCircle = 0; iCircle < circle_objs.N_circle; iCircle++) {

      circle = circle_objs.get_circle();

      for (int iLine = 0; iLine < line_objs.N_line; iLine++) {
         line = line_objs.get_line();
         collideWithLine(circle, line);

         line_objs.goto_next_line();
      }

      circle_objs.goto_next_circle();
   }

   // determine interactions with other circles
   for (int iCircle = 0; iCircle < circle_objs.N_circle; iCircle++) {

      circle = circle_objs.get_circle();

      float x0 = circle->getx0();
      float y0 = circle->gety0();

      float x1, y1;
      float Force;

      for (int jCircle = 0; jCircle < circle_objs.N_circle - 1; jCircle++) {

         circle_objs.goto_next_circle();
         otherCircle = circle_objs.get_circle();

         x1 = otherCircle->getx0();
         y1 = otherCircle->gety0();

         float nx = x1 - x0;
         float ny = y1 - y0;
         float norm = sqrtf( nx*nx + ny*ny );
         nx /= norm;
         ny /= norm;

         // collision with other circle
         collideWithCircle(circle, otherCircle);

         // gravitational pull of other circle
         Force = gravity( circle, otherCircle, 0.00001 );
         circle->apply_force( Force * nx, Force * ny);

      }

   }

   // update the circles by dt
   for (int i = 0; i < circle_objs.N_circle; i++) {
      // extract the current circle from the list
      circle = circle_objs.get_circle();
      // advance the list to the next circle node
      circle_objs.goto_next_circle();

      // apply gravitational forces
      float Fy = circle->getMass() * -0.5;
      circle->apply_force(0.0, Fy);

      // update the circle positions, velocity, etc...
      circle->update(dt);

      // reset forces
      circle->reset_force();
   }

   glutPostRedisplay();

}

/***********
 * Display *
 ***********/

void FISIX::display(void) {

  glClear(GL_COLOR_BUFFER_BIT);

   // draw line as it is being made by the user
   if (activeClick) {

      DRAWINGS draw;

      draw.draw_line (activeX1,
                      activeY1,
                      activeX2,
                      activeY2,
                      1.0, 1.0, 0.0);

   }

   CIRCLE *circle;

   for (int i = 0; i < circle_objs.N_circle; i++) {

      // extract the current circle from the list
      circle = circle_objs.get_circle();

      // advance the list to the next circle node
      circle_objs.goto_next_circle();

      // draw this circle
      circle->draw();

   }

   LINE *line;

   for (int i = 0; i < line_objs.N_line; i++) {

      // extract the current line from the list
      line = line_objs.get_line();

      // advance the list to the next line node
      line_objs.goto_next_line();

      // draw this line
      line->draw();

   }

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
         circle_objs.insert(new CIRCLE(xpos, ypos, 0.05, 0.9));

   activeP2x = x;
   activeP2y = y;
   activeX2 = -((float)(windowsizex - 2*activeP2x))/windowsizex;
   activeY2 = ((float)(windowsizey - 2*activeP2y))/windowsizey;
   if (button == GLUT_RIGHT_BUTTON &&
       state  == GLUT_DOWN) {

         activeP1x = x;
         activeP1y = y;

         activeX1 = -((float)(windowsizex - 2*activeP1x))/windowsizex;
         activeY1 = ((float)(windowsizey - 2*activeP1y))/windowsizey;

         activeClick = true;

   } else if (button == GLUT_RIGHT_BUTTON &&
       state  == GLUT_UP) {

         activeClick = false;
         line_objs.insert(new LINE(activeX1, activeY1, activeX2, activeY2));

   }
}

/****************
 * Mouse Motion *
 ****************/

void FISIX::mouseMotion(int x, int y) {

   activeP2x = x;
   activeP2y = y;
   activeX2 = -((float)(windowsizex - 2*activeP2x))/windowsizex;
   activeY2 = ((float)(windowsizey - 2*activeP2y))/windowsizey;
}
