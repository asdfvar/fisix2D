#include"list.h"
#include<stdio.h>
#include<iostream>

class NODE;
class LIST;

NODE::NODE() {}

LIST::LIST() {

  N = 0;
  at = 0;

}

void LIST::append(void *obj) {

  NODE *node = new NODE();
  node->obj = obj;

  if (N++ == 0) {

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

void LIST::gotonext(void) {

  at = at->next;

}

void LIST::gotoprev(void) {

  at = at->prev;

}

void *LIST::getobj(void) {

  return at->obj;

}

NODE *LIST::pop(void) {

  NODE *ptr = at;

  if (N <= 0) {

    N = 0;
    std::cout << "Nothing to pop"
        << std::endl;

    return ptr;

  }

  if (--N == 0) {

    at = 0;

    std::cout << "Last node popped at "
        << ptr << std::endl;

  } else {

     at = ptr->prev;
     at->next = ptr->next;
     ptr->next->prev = at;

     std::cout << "node "
        << ptr << " popped"
        << std::endl;

  }

  return ptr;
}

LIST::~LIST() {

  while (N > 0)
    delete this->pop();

}
