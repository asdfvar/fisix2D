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

//  ball->remove();
  ball = (CIRCLE*) ball->shift_left();

  std::cout << ball->prev << " "
            << ball << " "
            << ball->next << std::endl;

  return 0;
}
