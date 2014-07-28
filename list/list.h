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

    void set_circle_obj(CIRCLE*);
    CIRCLE *get_circle(void);
    void delete_circle(void);
    bool have_circle;

  private:

    CIRCLE *circle_obj;
};

 /********
  * LIST *
  ********/

class LIST {

  public:

    LIST();
   ~LIST();

    // Circle
    void insert(CIRCLE*);
    CIRCLE *get_circle(void);
    void goto_next_circle(void);
    CIRCLE *pop_circle(void);
    void delete_circle(void);

  private:

    bool is_circular;

    /* Node */
    NODE *at, *beginning, *end;
    NODE *pop(void);
    void goto_next(void);
    void goto_prev(void);
    void insertNode(NODE*);
    int N_node;

    // Circle
    int N_circle;
    NODE *this_circle_node;
    CIRCLE *this_circle;

};

#endif
