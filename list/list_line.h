#ifndef LIST_LINE_H
#define LIST_LINE_H
#include "line.h"

 /***************
  * NODE_LINE *
  ***************/

class NODE_LINE {

  public:

    NODE_LINE();
   ~NODE_LINE();

    NODE_LINE *prev, *next;

    int node_id;

    void set_line_obj(LINE*);
/*  puts a new line object into the node */

    LINE *get_line(void);
/*  returns a pointer to the line */

    void delete_line(void);
/*  deletes the current line */

    bool have_line;
/*  tells whether this node has
    an line or not */

  private:

    LINE *line_obj;
};

 /***************
  * Circle LIST *
  ***************/

class LIST_LINE {

  public:

    LIST_LINE();
   ~LIST_LINE();

    // line
    void insert(LINE*);
    LINE *get_line(void);
/*  returns a pointer to the line */

    void goto_next_line(void);
/*  goto the next line */

    LINE *pop_line(void);
/*  pops the line and returns a
    pointer to that line. Also
    pops the node if there is nothing
    left on the node */

    void delete_line(void);
/*  deletes the line on the
    current node */

    // line
    int N_line;

  private:

    bool is_circular;

    /* node */
    NODE_LINE *at, *beginning, *end;
    NODE_LINE *pop(void);
    void goto_next(void);
    void goto_prev(void);
    void insertNode(NODE_LINE*);
    int N_node;

    // line
    NODE_LINE *this_line_node;
    LINE *this_line;

};

#endif
