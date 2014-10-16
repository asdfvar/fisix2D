#include "shape.h"
#include "tools.h"
#include <cmath>
#include <iostream>

#define ABS(A) ((A) > 0.0) ? (A) : -(A)
#define EPS 0.00000001

/* function to return the distance from a point and a
   finite length line

     |(y2-y1)*x0 - (x2-x1)*y0 - x1*y2 + x2*y1|
 d = -----------------------------------------
            sqrt((x2-x1)^2 + (y2-y1)^2)

*/

float distance2Line(
                   float x1, /* line start x */
                   float y1, /* line start y */
                   float x2, /* line end x   */
                   float y2, /* line end y   */
                   float x0, /* point x      */
                   float y0) /* point y      */
{

  float Dp1, Dp2, Dp1p2;
  float num, den;

  Dp1p2 = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
  Dp1   = (x0-x1)*(x0-x1) + (y0-y1)*(y0-y1);
  Dp2   = (x0-x2)*(x0-x2) + (y0-y2)*(y0-y2);

  if (Dp1 + Dp1p2 < Dp2)
     return sqrtf(Dp1);
  else if (Dp2 + Dp1p2 < Dp1)
     return sqrtf(Dp2);
  else {
     num = (y2-y1)*x0 - (x2-x1)*y0 - x1*y2 + x2*y1;
     num = ABS(num);
     den = sqrtf((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
     return num / den;
  }
}

/* will change the course of the ball if it
   intersects a line. Otherwise, it wont do
   anything.
*/
void collideWithLine(CIRCLE *circle, LINE *line) {

   float x0 = circle->getx0();
   float y0 = circle->gety0();
   float e  = circle->getElasticity();
   float vx = circle->getVelx();
   float vy = circle->getVely();
   float x1 = line->getx1();
   float y1 = line->gety1();
   float x2 = line->getx2();
   float y2 = line->gety2();

   float dist = distance2Line(x1, y1, x2, y2, x0, y0);

   float diameter = circle->getDiameter();

   if (2.0*dist <= diameter) {

      /* check the dot product of the ball velocity
         and the normal vector of the line. If they
         are in the opposite direction (-), then
         there is a collision. */

      // get the normal vector from the line to the
      // center of the circle

      float px = x2-x1;
      float py = y2-y1;
      float qx = x0-x1;
      float qy = y0-y1;
      float norm = sqrtf(px*px + py*py);
      px /= norm;
      py /= norm;
      float dotp = px*qx + py*qy;

      // compute the normal vector
      // (length is from surface to the center of the ball)
      float nx = qx - dotp*px;
      float ny = qy - dotp*py;

      // compute the dot product of the ball velocity
      // and the normal vector to the surface
      dotp = nx*vx + ny*vy;
      
      // normalize the normal vector
      norm = sqrtf(nx*nx + ny*ny);
      nx /= norm;
      ny /= norm;

      if (dotp < 0.0) {
         // projection matrix
         float T11 = nx*nx;
         float T12 = nx*ny;
         float T21 = T12;
         float T22 = ny*ny;

         // project the ball velocity vector onto the normal vector
         float Pu_nx = T11*vx + T12*vy;
         float Pu_ny = T21*vx + T22*vy;

         // compute the new velocity direction
         vx -= Pu_nx*(1.0 + e);
         vy -= Pu_ny*(1.0 + e);

         // circle->setVely(-e*vy);
         circle->setVelx(vx);
         circle->setVely(vy);

      } else {

         // the ball is intersecting the line but traveling
         // the away from the line. Move it away from the line

         float delta = diameter / 2.0 - dist;

         x0 += delta*nx;
         y0 += delta*ny;

         circle->setPosx(x0);
         circle->setPosy(y0);

      }
   }
}

void collideWithCircle (CIRCLE *circle1, CIRCLE *circle2) {

   float c1x = circle1->getx0();
   float c1y = circle1->gety0();
   float c1e  = circle1->getElasticity();
   float c1vx = circle1->getVelx();
   float c1vy = circle1->getVely();
   float mass1 = circle1->getMass();

   float c2x = circle2->getx0();
   float c2y = circle2->gety0();
   float c2e  = circle2->getElasticity();
   float c2vx = circle2->getVelx();
   float c2vy = circle2->getVely();
   float mass2 = circle2->getMass();

   float dist2 = (c1x-c2x)*(c1x-c2x) + (c1y-c2y)*(c1y-c2y);

   float diameter1 = circle1->getDiameter();
   float diameter2 = circle2->getDiameter();

   // check if the two intersect
   if ( 4*dist2 <= (diameter1 + diameter2)*(diameter1 + diameter2) ) {

      // compute relative velocities and positions
      float vx12 = c2vx - c1vx;
      float vy12 = c2vy - c1vy;
      float x12  = c2x  - c1x;
      float y12  = c2y  - c1y;

      /* There is a collision if one circle is traveling towards the
         other one (relatively) */
      if (vx12*x12 + vy12*y12 < 0.0) {

         // normal vector from circle 1 to circle 2
         float norm = sqrtf(x12*x12 + y12*y12);
         x12 /= norm;
         y12 /= norm;

         // projection matrix
         float T11 = x12*x12;
         float T12 = x12*y12;
         float T21 = T12;
         float T22 = y12*y12;

         // project the ball velocity vector onto the normal vector
         float v1nx = T11*c1vx + T12*c1vy;
         float v1ny = T21*c1vx + T22*c1vy;
         float v2nx = T11*c2vx + T12*c2vy;
         float v2ny = T21*c2vx + T22*c2vy;

         // get the orthogonal to normal velocity vectors
         float v1px = c1vx - v1nx;
         float v1py = c1vy - v1ny;
         float v2px = c2vx - v2nx;
         float v2py = c2vy - v2ny;

         /* change the normal velocity vector by conserving
            momentum and kinetic energy */
         float v1xnew = mass1*v1nx - mass2*(v1nx - 2.0*v2nx);
               v1xnew /= mass1 + mass2;
         float v1ynew = mass1*v1ny - mass2*(v1ny - 2.0*v2ny);
               v1ynew /= mass1 + mass2;
         float v2xnew = mass2*v2nx - mass1*(v2nx - 2.0*v1nx);
               v2xnew /= mass1 + mass2;
         float v2ynew = mass2*v2ny - mass1*(v2ny - 2.0*v1ny);
               v2ynew /= mass1 + mass2;

         if (v1xnew*v1xnew + v1ynew*v1ynew < EPS) {
            v1xnew = 0.0;
            v1ynew = 0.0;
         }
         if (v2xnew*v2xnew + v2ynew*v2ynew < EPS) {
            v2xnew = 0.0;
            v2ynew = 0.0;
         }

         v1xnew += v1px;
         v1ynew += v1py;
         v2xnew += v2px;
         v2ynew += v2py;

         circle1->setVelx(v1xnew);
         circle1->setVely(v1ynew);
         circle2->setVelx(v2xnew);
         circle2->setVely(v2ynew);

      } else {
         /* This case, the balls intersect each other but are moving
            away from each other. We want to move them away from
            each other */

         // normal vector from circle 1 to circle 2
         float norm = sqrtf(x12*x12 + y12*y12);
         x12 /= norm;
         y12 /= norm;

         float err = 0.5*(diameter1 + diameter2) - sqrtf(dist2);
         err *= 0.5;

         /* Each of the two balls are moved half of the distance
            of their intersection away from each other */
         c1x -= err * x12;
         c1y -= err * y12;
         c2x += err * x12;
         c2y += err * y12;

         circle1->setPosx(c1x);
         circle1->setPosy(c1y);
         circle2->setPosx(c2x);
         circle2->setPosy(c2y);
      }

   }
}
