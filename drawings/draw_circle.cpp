#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <cmath>
#include "drawings.h"

#define PI 3.14159265358979

void DRAWINGS::draw_circle (
           float diameter,
           float x0,
           float y0,
           int  N,
           char red,
           char green,
           char blue)
{

   float tmp;
   float x,y;

   glColor3ub(red, green, blue);

   glBegin(GL_POLYGON);
   for (int i = 0; i < N; i++) {
      x = x0 + diameter/2.0*cosf(2*PI*(float)i/40.0);
      y = y0 + diameter/2.0*sinf(2*PI*(float)i/40.0);

      glVertex3f(x*scale, y*scale, 0.0);
   }
   glEnd();
}
