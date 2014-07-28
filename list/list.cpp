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

/*********************
 * set circle object *
 *********************/

void NODE::set_circle_obj(CIRCLE* circle) {
  if (!have_circle)
     circle_obj = circle;
  else
     std::cout << "circle already exists"
          << std::endl;
}

/*********************
 * get circle object *
 *********************/

CIRCLE *NODE::get_circle(void) {
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
  is_circular = true;
  this_circle = 0;
  this_circle_node = 0;
}

/*****************
 * insert Circle *
 *****************/

void LIST::insert(CIRCLE *circle_obj) {

  this_circle = circle_obj;

  NODE *node = new NODE();

  insertNode(node);

  node->set_circle_obj(circle_obj);

  this_circle_node = node;

  N_circle++;
}

/**************
 * get circle *
 **************/

CIRCLE *LIST::get_circle(void) {

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

void LIST::insertNode(NODE *node) {

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

  std::cout << "added a node at "
            << at << " with previous node at "
            << at->prev << " and next node at "
            << at->next << std::endl;
}

/******************
 * goto next node *
 ******************/

void LIST::goto_next(void) {

  at = at->next;

}

/**********************
 * goto previous node *
 **********************/

void LIST::goto_prev(void) {

  at = at->prev;

}

/**************
 * pop circle *
 **************/

CIRCLE *LIST::pop_circle(void) {

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

void LIST::delete_circle(void) {

  this_circle_node->delete_circle();

  if (!this_circle_node->have_circle)
    pop();

}

/*****************
 * delete circle *
 *****************/

void NODE::delete_circle(void) {

  if (have_circle) {

    delete circle_obj;

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

void LIST::goto_next_circle() {

  if (N_circle <= 0) {
     printf("No circles left\n");
     return;
  }

  if (is_circular) {

     at = this_circle_node;

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

NODE *LIST::pop(void) {

  NODE *ptr = at;

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

LIST::~LIST() {

  while (N_node > 0)
    delete this->pop();

}

/*******************
 * Node destructor *
 *******************/

NODE::~NODE() {

  std::cout
   << "circle at "
   << circle_obj
   << " deleted"
   << std::endl;

  delete circle_obj;
}
