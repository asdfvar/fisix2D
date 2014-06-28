#include "shape.h"

CIRCLE::CIRCLE() {

  x[0] = x[1] = x[2] = 0.0;
  y[0] = y[1] = y[2] = 0.0;
  w[0] = w[1] = w[2] = 0.0;

}

CIRCLE::CIRCLE(float pos[]) {

  x[0] = pos[0];
  y[0] = pos[1];

  x[1] = x[2] = 0.0;
  y[1] = y[2] = 0.0;
  w[0] = w[1] = w[2] = 0.0;

}

CIRCLE::CIRCLE(float pos[], float vel[]) {

  x[0] = pos[0];
  y[0] = pos[1];

  x[1] = vel[0];
  y[1] = vel[1];

  x[2] = 0.0;
  y[2] = 0.0;
  w[0] = w[1] = w[2] = 0.0;

}

CIRCLE::CIRCLE(float pos[], float vel[]) {

  x[0] = pos[0];
  y[0] = pos[1];

  x[1] = vel[0];
  y[1] = vel[1];

  x[2] = 0.0;
  y[2] = 0.0;
  w[0] = w[1] = w[2] = 0.0;

}
