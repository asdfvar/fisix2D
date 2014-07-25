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

    int node_id;

    void setCircleObj(CIRCLE*);
    CIRCLE *getCircle(void);

  private:

    CIRCLE *circle_obj;
    bool have_circle;
};

 /********
  * LIST *
  ********/

class LIST {

  public:

    LIST();
   ~LIST();

    void insert(CIRCLE*);
    CIRCLE *popCircle(void); // working on making this
    NODE *pop(void);
    void gotonext(void);
    void gotoprev(void);

  private:

    /* Node */
    NODE *at, *beginning, *end; // check beginning and end are used
    void insertNode(NODE*);
    int N_node;

    // Circle
    int N_circle;
    NODE *this_circle_node;

};

#endif
