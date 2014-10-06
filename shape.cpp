#include "shape.h"
#include "drawings.h"
#include <stdio.h>

class SHAPE;

SHAPE::SHAPE() {}

/**/

CIRCLE::CIRCLE() {

   mass = 1.0;
   x[0] = x[1] = x[2] = 0.0;
   y[0] = y[1] = y[2] = 0.0;
   w[0] = w[1] = w[2] = 0.0;
   diameter = 0.25;
   elasticity = 1.0;

}

CIRCLE::CIRCLE(float x_in, float y_in) {

   mass = 1.0;
   x[0] = x_in;
   y[0] = y_in;
   x[1] = x[2] = 0.0;
   y[1] = y[2] = 0.0;
   w[0] = w[1] = w[2] = 0.0;
   diameter = 0.25;
   elasticity = 1.0;

}

CIRCLE::CIRCLE(float x_in, float y_in, float diameter_in) {

   mass = 1.0;
   x[0] = x_in;
   y[0] = y_in;
   x[1] = x[2] = 0.0;
   y[1] = y[2] = 0.0;
   w[0] = w[1] = w[2] = 0.0;
   diameter = diameter_in;
   elasticity = 1.0;

}

CIRCLE::CIRCLE(float x_in, float y_in, float diameter_in,
               float elasticity_in) {

   mass = 1.0;
   x[0] = x_in;
   y[0] = y_in;
   x[1] = x[2] = 0.0;
   y[1] = y[2] = 0.0;
   w[0] = w[1] = w[2] = 0.0;
   diameter = diameter_in;
   elasticity = elasticity_in;

}

/********************************************************
 * Update the circle "ball" parameters based on a delta *
 * time and external forces                             *
 ********************************************************/

void CIRCLE::update_force(float dt, /* delta time (seconds) */
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

/********************************************************
 * Update the circle "ball" parameters based on a delta *
 * time and the provided acceleration                   *
 ********************************************************/

void CIRCLE::update_acceleration(
               float ax,  /* acceleration in x (N) */
               float ay){ /* acceleration in y (N) */

   // update the acceleration
   x[2] = ax;
   y[2] = ay;

}

void CIRCLE::update(float dt) {

   // update the position
   x[0] += x[1]*dt + 0.5*x[2]*dt*dt;
   y[0] += y[1]*dt + 0.5*y[2]*dt*dt;

   // update the velocity
   x[1] += x[2]*dt;
   y[1] += y[2]*dt;

}

/*********
 * get x *
 *********/

float CIRCLE::getx0(void) {
   return x[0];
}

/*********
 * get y *
 *********/

float CIRCLE::gety0(void) {
   return y[0];
}

/*********************
 * get velocity in x *
 *********************/

float CIRCLE::getVelx(void) {
   return x[1];
}

/*********************
 * get velocity in y *
 *********************/

float CIRCLE::getVely(void) {
   return y[1];
}

/****************
 * get diameter *
 ****************/

float CIRCLE::getDiameter(void) {
   return diameter;
}

/******************
 * get elasticity *
 ******************/

float CIRCLE::getElasticity(void) {
   return elasticity;
}

/*********************
 * set position in x *
 *********************/

void CIRCLE::setPosx(float x0) {
   x[0] = x0;
}

/*********************
 * set position in y *
 *********************/

void CIRCLE::setPosy(float y0) {
   y[0] = y0;
}

/*********************
 * set velocity in x *
 *********************/

void CIRCLE::setVelx(float vx) {
   x[1] = vx;
}

/*********************
 * set velocity in y *
 *********************/

void CIRCLE::setVely(float vy) {
   y[1] = vy;
}

/*******************
 * Draw the circle *
 *******************/

void CIRCLE::draw(void) {

   drawings.draw_circle(diameter, x[0], y[0]);

}
