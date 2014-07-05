#include <stdio.h>
#include <iostream>
#include "shape.h"

class CIRCLE;

int main() {

  CIRCLE *ball = new CIRCLE;

  std::cout << ball->prev << " "
            << ball << " "
            << ball->next << std::endl;

  ball->append(new CIRCLE);

  std::cout << ball->prev << " "
            << ball << " "
            << ball->next << std::endl;

  delete ball;

  return 0;
}
