#include "shape.h"

class SHAPE;

SHAPE::SHAPE() {

  prev = this;
  next = this;
  Number_of_obj = 1;

}

#if 0
SHAPE::~SHAPE() {

  while(Number_of_obj > 0) {
  }

}
#endif

void SHAPE::append(SHAPE *shape) {

/*

    prev <-> this <-> next
                   ^
                   |
                 append

*/

  shape->next = this->next;
  shape->prev = this;
  this->next = shape;
  shape->next->prev = shape;
  shape->Number_of_obj = ++Number_of_obj;

}

void SHAPE::remove(void) {

  this->prev->next = this->next;
  this->next->prev = this->prev;

  delete this;

}

SHAPE *SHAPE::shift_left(void) {

  return this->prev;

}

/**/

CIRCLE::CIRCLE() {

  x[0] = x[1] = x[2] = 0.0;
  y[0] = y[1] = y[2] = 0.0;
  w[0] = w[1] = w[2] = 0.0;

}
