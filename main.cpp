#include <stdio.h>
#include <iostream>
#include "shape.h"
#include "list.h"

class CIRCLE;

int main() {

  CIRCLE *ball = new CIRCLE;

  LIST list;

  list.insert(new CIRCLE);
  list.insert(new CIRCLE);
  list.insert(new CIRCLE);

  list.pop();
  list.pop();

  list.insert(new CIRCLE);
  list.insert(new CIRCLE);
  list.insert(new CIRCLE);
  list.insert(new CIRCLE);
  list.insert(new CIRCLE);
  list.insert(new CIRCLE);

  return 0;
}
