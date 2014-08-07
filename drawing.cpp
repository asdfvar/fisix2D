#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include "drawings.h"

void drawing(void) {

   glClear(GL_COLOR_BUFFER_BIT);

   /* insert gl drawings stuffs here */
   draw_circle(
          0.5,
          0.25,
          0.25);

   glFlush();

}
