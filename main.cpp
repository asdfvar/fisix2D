#include <stdio.h>
#include <iostream>
#include "shape.h"
#include "list.h"

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

  ball = (CIRCLE*) ball->shift_left();

  std::cout << ball->prev << " "
            << ball << " "
            << ball->next << std::endl;

  printf("\n\n");

  LIST list;

  list.append(new CIRCLE);
  list.append(new CIRCLE);
  list.append(new CIRCLE);

  list.pop();
  list.pop();

  list.append(new CIRCLE);
  list.append(new CIRCLE);
  list.append(new CIRCLE);
  list.append(new CIRCLE);
  list.append(new CIRCLE);
  list.append(new CIRCLE);

  return 0;
}
