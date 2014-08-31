#include "drawings.h"
class LINE {

   public:

      LINE(float x1, float x2, float y1, float y2);
     ~LINE();

      void draw();

   private:

      float x1,y1,x2,y2;
      DRAWINGS drawings;
};
