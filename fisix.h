#include "list_circle.h"
#include "list_line.h"

class FISIX {

   public:

      FISIX(int windowsizex_in,
            int windowsizey_in);
      ~FISIX();

/*************************
 * Main Program Routines *
 *************************/

      void display(void);
      void idle(void);
      void mouse(int, int, int, int);

      LIST_CIRCLE circle_objs;
      LIST_LINE line_objs;

   private:

      int windowsizex,
          windowsizey;

};
