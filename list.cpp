#include "list.h"
#include "shape.h"
#include <stdio.h>
#include <iostream>

class NODE;
class LIST;

/*||||||||||||
  ||  NODE  ||
  ||||||||||||*/

/********************
 * Node constructor *
 ********************/

NODE::NODE() {
  circle_obj = 0;
  isCircle = false;
}

/*******************
 * Node destructor *
 *******************/

NODE::~NODE() {
  delete circle_obj;
}

/*********************
 * set circle object *
 *********************/

void NODE::setCircleObj(CIRCLE* circle) {
  if (!isCircle)
     circle_obj = circle;
  else
     std::cout << "circle already exists"
          << std::endl;
}

/*********************
 * get circle object *
 *********************/

CIRCLE *NODE::getCircle(void) {
  if (isCircle)
     return circle_obj;
  else {
     std::cout << "no circle exists"
          << std::endl;
     return 0;
  }
}

/*||||||||||||
  ||  LIST  ||
  ||||||||||||

 ********************
 * List constructor *
 ********************/

LIST::LIST() {
  N_node = 0;
  at = 0;
  N_circle = 0;
}

/********************
 * append to insert *
 ********************

    prev <-> this <-> next
                   ^
                   |
                 insert

*/

void LIST::insert(CIRCLE *circle_obj) {

  NODE *node = new NODE();

  insertNode(node);

  node->setCircleObj(circle_obj);

  N_circle++;
}

/***************
 * Insert Node *
 ***************/

void LIST::insertNode(NODE *node) {

  N_node++;

  if (N_node == 1) {

     at = node;
     node->prev = node->next = at;

  } else {
     
     node->next = at->next;
     node->prev = at;
     at->next->prev = node;
     at->next = node;
     at = node;

  }

  std::cout << "added a node at "
            << at << " with previous node at "
            << at->prev << " and next node at "
            << at->next << std::endl;
}

/****************
 * Destroy list *
 ****************/

LIST::~LIST() {

  while (N_node > 0)
    delete this->pop();

}

void LIST::gotonext(void) {

  at = at->next;

}

void LIST::gotoprev(void) {

  at = at->prev;

}

NODE *LIST::pop(void) {

  NODE *ptr = at;

  N_node--;

  if (N_node > 0) {

     at = ptr->prev;
     at->next = ptr->next;
     ptr->next->prev = at;

     std::cout << "node "
        << ptr << " popped"
        << std::endl;

  } else if (N_node == 0) {

    at = 0;

    std::cout << "Last node popped at "
        << ptr << std::endl;

  } else {

    N_node = 0;
    std::cout << "Nothing to pop"
        << std::endl;

    return ptr;

  }

  return ptr;
}
