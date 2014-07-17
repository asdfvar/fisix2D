#ifndef LIST_H
#define LIST_H
#include "shape.h"

class NODE {

  public:

    NODE();
   ~NODE();

    CIRCLE *circle_obj;

    NODE *prev, *next;

};

class LIST {

  public:

    LIST();
   ~LIST();
    void append(CIRCLE*);
    NODE *pop(void);
    void gotonext(void);
    void gotoprev(void);

  private:

    int N;
    NODE *at;

};

#endif
