#ifndef LIST_H
#define LIST_H
#include "assembly.h"

 /********
  * NODE *
  ********/

class NODE {

  public:

    NODE();
   ~NODE();

    NODE *prev, *next;

    int node_id;

    void set_assembly_obj(ASSEMBLY*);
/*  puts a new assembly object into the node */

    ASSEMBLY *get_assembly(void);
/*  returns a pointer to the assembly */

    void delete_assembly(void);
/*  deletes the current assembly */

    bool have_assembly;
/*  tells whether this node has
    an assembly or not */

  private:

    ASSEMBLY *assembly_obj;
};

 /********
  * LIST *
  ********/

class LIST {

  public:

    LIST();
   ~LIST();

    // assembly
    void insert(ASSEMBLY*);
    ASSEMBLY *get_assembly(void);
/*  returns a pointer to the assembly */

    void goto_next_assembly(void);
/*  goto the next assembly */

    ASSEMBLY *pop_assembly(void);
/*  pops the assembly and returns a
    pointer to that assembly. Also
    pops the node if there is nothing
    left on the node */

    void delete_assembly(void);
/*  deletes the assembly on the
    current node */

  private:

    bool is_circular;

    /* node */
    NODE *at, *beginning, *end;
    NODE *pop(void);
    void goto_next(void);
    void goto_prev(void);
    void insertNode(NODE*);
    int N_node;

    // assembly
    int N_assembly;
    NODE *this_assembly_node;
    ASSEMBLY *this_assembly;

};

#endif
