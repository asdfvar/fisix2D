#include <stdio.h>
#include <iostream>
#include "shape.h"
#include "list.h"

class ASSEMBLY;

int main() {

  ASSEMBLY *ball = new ASSEMBLY;

  LIST list;

  list.insert(new ASSEMBLY);
  list.insert(new ASSEMBLY);
  list.insert(new ASSEMBLY);

  ASSEMBLY *qwer = list.pop_assembly();
  qwer = list.pop_assembly();

  list.insert(new ASSEMBLY);
  list.insert(new ASSEMBLY);
  list.insert(new ASSEMBLY);
  list.insert(new ASSEMBLY);
  list.insert(new ASSEMBLY);
  list.insert(new ASSEMBLY);

  delete qwer;

  return 0;
}
