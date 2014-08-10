#include "list.h"
#include "assembly.h"
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

  assembly_obj = 0;
  have_assembly = false;
  node_id = id++;
}

/*********************
 * set assembly object *
 *********************/

void NODE::set_assembly_obj(ASSEMBLY* assembly) {
  if (!have_assembly) {
     assembly_obj = assembly;
     have_assembly = true;
  } else
     std::cout << "assembly already exists"
          << std::endl;
}

/*********************
 * get assembly object *
 *********************/

ASSEMBLY *NODE::get_assembly(void) {
  if (have_assembly)
     return assembly_obj;
  else {
     std::cout << "no assembly exists"
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
  N_assembly = 0;
  is_circular = true;
  this_assembly = 0;
  this_assembly_node = 0;
}

/*****************
 * insert Circle *
 *****************/

void LIST::insert(ASSEMBLY *assembly_obj) {

  this_assembly = assembly_obj;

  NODE *node = new NODE();

  insertNode(node);

  node->set_assembly_obj(assembly_obj);

  this_assembly_node = node;

  N_assembly++;
}

/**************
 * get assembly *
 **************/

ASSEMBLY *LIST::get_assembly(void) {

  return this_assembly;
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
 * pop assembly *
 **************/

ASSEMBLY *LIST::pop_assembly(void) {

  if (N_assembly <= 0) {

     printf("No assemblys left\n");
     return 0;

  } else {

     N_assembly--;
     ASSEMBLY *ptr = this_assembly;
     at->have_assembly = false;

     if (!at->have_assembly)
       pop();

     goto_next_assembly();

     return ptr;

   }
}

/*****************
 * delete assembly *
 *****************/

void LIST::delete_assembly(void) {

  this_assembly_node->delete_assembly();

  if (!this_assembly_node->have_assembly)
    pop();

}

/*****************
 * delete assembly *
 *****************/

void NODE::delete_assembly(void) {

  if (have_assembly) {

    delete assembly_obj;
    have_assembly = false;

    std::cout
      << "assembly object at "
      << assembly_obj
      << " deleted"
      << std::endl;

  }

}

/********************
 * goto next assembly *
 ********************/

void LIST::goto_next_assembly() {

  if (N_assembly <= 0) {
     printf("No assemblys left\n");
     return;
  }

  if (is_circular) {

     at = this_assembly_node;
     goto_next();

     while (!at->have_assembly)
        goto_next();

     this_assembly = at->get_assembly();
     this_assembly_node = at;

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
   << "assembly at "
   << assembly_obj
   << " deleted"
   << std::endl;

  delete assembly_obj;
}
