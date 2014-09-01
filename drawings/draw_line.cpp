#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include "drawings.h"

void DRAWINGS::draw_line (
      float x1,
      float y1,
      float x2,
      float y2,
      float red, float green, float blue)
{

   glLineWidth(2.5);
   glColor3f(red, green, blue);
   glBegin(GL_LINES);
   glVertex3f(x1,y1,0.0);
   glVertex3f(x2,y2,0.0);
   glEnd();
}
