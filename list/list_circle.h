#ifndef LIST_CIRCLE_H
#define LIST_CIRCLE_H
#include "shape.h"

 /***************
  * NODE_CIRCLE *
  ***************/

class NODE_CIRCLE {

  public:

    NODE_CIRCLE();
   ~NODE_CIRCLE();

    NODE_CIRCLE *prev, *next;

    int node_id;

    void set_circle_obj(CIRCLE*);
/*  puts a new circle object into the node */

    CIRCLE *get_circle(void);
/*  returns a pointer to the circle */

    void delete_circle(void);
/*  deletes the current circle */

    bool have_circle;
/*  tells whether this node has
    an circle or not */

  private:

    CIRCLE *circle_obj;
};

 /***************
  * Circle LIST *
  ***************/

class LIST_CIRCLE {

  public:

    LIST_CIRCLE();
   ~LIST_CIRCLE();

    // circle
    void insert(CIRCLE*);
    CIRCLE *get_circle(void);
/*  returns a pointer to the circle */

    void goto_next_circle(void);
/*  goto the next circle */

    CIRCLE *pop_circle(void);
/*  pops the circle and returns a
    pointer to that circle. Also
    pops the node if there is nothing
    left on the node */

    void delete_circle(void);
/*  deletes the circle on the
    current node */

    // circle
    int N_circle;

  private:

    bool is_circular;

    /* node */
    NODE_CIRCLE *at, *beginning, *end;
    NODE_CIRCLE *pop(void);
    void goto_next(void);
    void goto_prev(void);
    void insertNode(NODE_CIRCLE*);
    int N_node;

    // circle
    NODE_CIRCLE *this_circle_node;
    CIRCLE *this_circle;

};

#endif
