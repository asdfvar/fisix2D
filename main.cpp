#include <stdio.h>
#include <iostream>
#include "shape.h"
#include "list.h"

class CIRCLE;

int main() {

  CIRCLE *ball = new CIRCLE;

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
