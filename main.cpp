#include <stdio.h>
#include <iostream>
#include "shape.h"
#include "list.h"

class CIRCLE;

float gettime(void);

int main() {

  float dt;
  float Time = 0.0;

  while (Time < 10.0) {

  Time += gettime();

  }

  return 0;
}
