#include "list_circle.h"
#include "shape.h"
#include <stdio.h>
#include <iostream>

class NODE_CIRCLE;
class LIST_CIRCLE;

/*||||||||||||
  ||  NODE_CIRCLE  ||
  ||||||||||||*/

/********************
 * Node constructor *
 ********************/

NODE_CIRCLE::NODE_CIRCLE() {
  static int id = 0;

  circle_obj = 0;
  have_circle = false;
  node_id = id++;
}

/*********************
 * set circle object *
 *********************/

void NODE_CIRCLE::set_circle_obj(CIRCLE* circle) {
  if (!have_circle) {
     circle_obj = circle;
     have_circle = true;
  } else
     std::cout << "circle already exists"
          << std::endl;
}

/*********************
 * get circle object *
 *********************/

CIRCLE *NODE_CIRCLE::get_circle(void) {
  if (have_circle)
     return circle_obj;
  else {
     std::cout << "no circle exists"
          << std::endl;
     return 0;
  }
}

/*||||||||||||
  ||  LIST_CIRCLE  ||
  ||||||||||||

 ********************
 * List constructor *
 ********************/

LIST_CIRCLE::LIST_CIRCLE() {
  N_node = 0;
  at = 0;
  N_circle = 0;
  is_circular = true;
  this_circle = 0;
  this_circle_node = 0;
}

/*****************
 * insert Circle *
 *****************/

void LIST_CIRCLE::insert(CIRCLE *circle_obj) {

  this_circle = circle_obj;

  NODE_CIRCLE *node = new NODE_CIRCLE();

  insertNode(node);

  node->set_circle_obj(circle_obj);

  this_circle_node = node;

  N_circle++;
}

/**************
 * get circle *
 **************/

CIRCLE *LIST_CIRCLE::get_circle(void) {

  return this_circle;
}

/***************
 * Insert Node *
 ***************

    prev <-> this <-> next
                   ^
                   |
                 insert
*/

void LIST_CIRCLE::insertNode(NODE_CIRCLE *node) {

  N_node++;

  if (N_node == 1) {

     at = node;
     if (is_circular)
        node->prev = node->next = at;
     else
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

  std::cout << "added a circle node at "
            << at << " with previous node at "
            << at->prev << " and next node at "
            << at->next << std::endl;
}

/******************
 * goto next node *
 ******************/

void LIST_CIRCLE::goto_next(void) {

  at = at->next;

}

/**********************
 * goto previous node *
 **********************/

void LIST_CIRCLE::goto_prev(void) {

  at = at->prev;

}

/**************
 * pop circle *
 **************/

CIRCLE *LIST_CIRCLE::pop_circle(void) {

  if (N_circle <= 0) {

     printf("No circles left\n");
     return 0;

  } else {

     N_circle--;
     CIRCLE *ptr = this_circle;
     at->have_circle = false;

     if (!at->have_circle)
       pop();

     goto_next_circle();

     return ptr;

   }
}

/*****************
 * delete circle *
 *****************/

void LIST_CIRCLE::delete_circle(void) {

  this_circle_node->delete_circle();

  if (!this_circle_node->have_circle)
    pop();

}

/*****************
 * delete circle *
 *****************/

void NODE_CIRCLE::delete_circle(void) {

  if (have_circle) {

    delete circle_obj;
    have_circle = false;

    std::cout
      << "circle object at "
      << circle_obj
      << " deleted"
      << std::endl;

  }

}

/********************
 * goto next circle *
 ********************/

void LIST_CIRCLE::goto_next_circle() {

  if (N_circle <= 0) {
     printf("No circles left\n");
     return;
  }

  if (is_circular) {

     at = this_circle_node;
     goto_next();

     while (!at->have_circle)
        goto_next();

     this_circle = at->get_circle();
     this_circle_node = at;

  } else
     printf("Oops. Didn't make this case yet\n");


}

/************
 * pop node *
 ************/

NODE_CIRCLE *LIST_CIRCLE::pop(void) {

  NODE_CIRCLE *ptr = at;

  N_node--;

  if (N_node > 0) {

     at = ptr->prev;
     at->next = ptr->next;
     if (ptr->next != 0) ptr->next->prev = at;

     std::cout << "node at "
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

/****************
 * Destroy list *
 ****************/

LIST_CIRCLE::~LIST_CIRCLE() {

  while (N_node > 0)
    delete this->pop();

}

/*******************
 * Node destructor *
 *******************/

NODE_CIRCLE::~NODE_CIRCLE() {

  std::cout
   << "circle at "
   << circle_obj
   << " deleted"
   << std::endl;

  delete circle_obj;
}
