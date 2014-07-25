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
  static int id = 0;

  circle_obj = 0;
  have_circle = false;
  node_id = id++;
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
  if (!have_circle)
     circle_obj = circle;
  else
     std::cout << "circle already exists"
          << std::endl;
}

/*********************
 * get circle object *
 *********************/

CIRCLE *NODE::getCircle(void) {
  if (have_circle)
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

/*****************
 * insert Circle *
 *****************/

void LIST::insert(CIRCLE *circle_obj) {

  NODE *node = new NODE();

  insertNode(node);

  node->setCircleObj(circle_obj);

  this_circle_node = node;

  N_circle++;
}

/***************
 * Insert Node *
 ***************

    prev <-> this <-> next
                   ^
                   |
                 insert
*/

void LIST::insertNode(NODE *node) {

  N_node++;

  if (N_node == 1) {

     at = node;
     node->prev = node->next = 0;
     beginning = end = at;

  } else {
     
     if (at == end) end = node;

     node->next = at->next;
     node->prev = at;
     if (at->next != 0) at->next->prev = node;
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

/******************
 * goto next node *
 ******************/

void LIST::gotonext(void) {

  at = at->next;

}

/**********************
 * goto previous node *
 **********************/

void LIST::gotoprev(void) {

  at = at->prev;

}

/**************
 * pop circle *
 **************/

CIRCLE *LIST::popCircle(void) {

  if (N_circle <= 0) {

     printf("No circles left\n");
     return 0;

  } else {

     N_circle--;
     
     CIRCLE *ptr;

     

   }
}

/************
 * pop node *
 ************/

NODE *LIST::pop(void) {

  NODE *ptr = at;

  N_node--;

  if (N_node > 0) {

     at = ptr->prev;
     at->next = ptr->next;
     if (ptr->next != 0) ptr->next->prev = at;

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

  }

  return ptr;
}
