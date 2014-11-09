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
      void mouseMotion(int x, int y);

      LIST_CIRCLE circle_objs;
      LIST_LINE line_objs;

   private:

      int windowsizex,
          windowsizey;

      bool rightButtonDown;

      // selected point on the screen
      int activeP1x,
          activeP1y,
          activeP2x,
          activeP2y;

      // selected point on the screen normalized to [-1,1]x[-1,1]
      float activeX1,
            activeY1,
            activeX2,
            activeY2;

};
