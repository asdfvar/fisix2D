#ifndef LIST_H
#define LIST_H
#include "shape.h"

 /********
  * NODE *
  ********/

class NODE {

  public:

    NODE();
   ~NODE();

    NODE *prev, *next;

    int i_node;

    void setCircleObj(CIRCLE*);
    CIRCLE *getCircle(void);

  private:

    CIRCLE *circle_obj;
    bool isCircle;
};

 /********
  * LIST *
  ********/

class LIST {

  public:

    LIST();
   ~LIST();

    void insert(CIRCLE*);
    NODE *pop(void);
    void gotonext(void);
    void gotoprev(void);

  private:

    int N_node;
    NODE *at;

    void insertNode(NODE*);

};

#endif
