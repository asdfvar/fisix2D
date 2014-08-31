#include "list_line.h"
#include "line.h"
#include <stdio.h>
#include <iostream>

class NODE_LINE;
class LIST_LINE;

/*||||||||||||
  ||  NODE_LINE  ||
  ||||||||||||*/

/********************
 * Node constructor *
 ********************/

NODE_LINE::NODE_LINE() {
  static int id = 0;

  line_obj = 0;
  have_line = false;
  node_id = id++;
}

/*********************
 * set line object *
 *********************/

void NODE_LINE::set_line_obj(LINE* line) {
  if (!have_line) {
     line_obj = line;
     have_line = true;
  } else
     std::cout << "line already exists"
          << std::endl;
}

/*********************
 * get line object *
 *********************/

LINE *NODE_LINE::get_line(void) {
  if (have_line)
     return line_obj;
  else {
     std::cout << "no line exists"
          << std::endl;
     return 0;
  }
}

/*||||||||||||
  ||  LIST_LINE  ||
  ||||||||||||

 ********************
 * List constructor *
 ********************/

LIST_LINE::LIST_LINE() {
  N_node = 0;
  at = 0;
  N_line = 0;
  is_circular = true;
  this_line = 0;
  this_line_node = 0;
}

/*****************
 * insert Circle *
 *****************/

void LIST_LINE::insert(LINE *line_obj) {

  this_line = line_obj;

  NODE_LINE *node = new NODE_LINE();

  insertNode(node);

  node->set_line_obj(line_obj);

  this_line_node = node;

  N_line++;
}

/**************
 * get line *
 **************/

LINE *LIST_LINE::get_line(void) {

  return this_line;
}

/***************
 * Insert Node *
 ***************

    prev <-> this <-> next
                   ^
                   |
                 insert
*/

void LIST_LINE::insertNode(NODE_LINE *node) {

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

  std::cout << "added a line node at "
            << at << " with previous node at "
            << at->prev << " and next node at "
            << at->next << std::endl;
}

/******************
 * goto next node *
 ******************/

void LIST_LINE::goto_next(void) {

  at = at->next;

}

/**********************
 * goto previous node *
 **********************/

void LIST_LINE::goto_prev(void) {

  at = at->prev;

}

/**************
 * pop line *
 **************/

LINE *LIST_LINE::pop_line(void) {

  if (N_line <= 0) {

     printf("No lines left\n");
     return 0;

  } else {

     N_line--;
     LINE *ptr = this_line;
     at->have_line = false;

     if (!at->have_line)
       pop();

     goto_next_line();

     return ptr;

   }
}

/*****************
 * delete line *
 *****************/

void LIST_LINE::delete_line(void) {

  this_line_node->delete_line();

  if (!this_line_node->have_line)
    pop();

}

/*****************
 * delete line *
 *****************/

void NODE_LINE::delete_line(void) {

  if (have_line) {

    delete line_obj;
    have_line = false;

    std::cout
      << "line object at "
      << line_obj
      << " deleted"
      << std::endl;

  }

}

/********************
 * goto next line *
 ********************/

void LIST_LINE::goto_next_line() {

  if (N_line <= 0) {
     printf("No lines left\n");
     return;
  }

  if (is_circular) {

     at = this_line_node;
     goto_next();

     while (!at->have_line)
        goto_next();

     this_line = at->get_line();
     this_line_node = at;

  } else
     printf("Oops. Didn't make this case yet\n");


}

/************
 * pop node *
 ************/

NODE_LINE *LIST_LINE::pop(void) {

  NODE_LINE *ptr = at;

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

LIST_LINE::~LIST_LINE() {

  while (N_node > 0)
    delete this->pop();

}

/*******************
 * Node destructor *
 *******************/

NODE_LINE::~NODE_LINE() {

  std::cout
   << "line at "
   << line_obj
   << " deleted"
   << std::endl;

  delete line_obj;
}
