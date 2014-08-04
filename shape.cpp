#include "shape.h"

class SHAPE;

SHAPE::SHAPE() {}

/**/

CIRCLE::CIRCLE() {

   mass = 1.0;
   x[0] = x[1] = x[2] = 0.0;
   y[0] = y[1] = y[2] = 0.0;
   w[0] = w[1] = w[2] = 0.0;

}

/********************************************************
 * Update the circle "ball" parameters based on a delta *
 * time and external forces                             *
 ********************************************************/

void CIRCLE::update(float dt,      /* delta time */
               float forcex,  /* force in x (N) */
               float forcey){ /* force in y (N) */

   // update the position
   x[0] += x[1]*dt + 0.5*x[2]*dt*dt;
   y[0] += y[1]*dt + 0.5*y[2]*dt*dt;

   // update the velocity
   x[1] += x[2]*dt;
   y[1] += y[2]*dt;

   // update the acceleration
   x[2] = forcex / mass;
   y[2] = forcey / mass;

}

float CIRCLE::acceleration_to_force(float a) {

   return mass * a;

}
