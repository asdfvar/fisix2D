#ifndef LINE_H
#define LINE_H

#include "drawings.h"

class LINE {

   public:

      LINE();
      LINE(float x1, float y1, float x2, float y2);
     ~LINE();

      float getx1(void);
      float gety1(void);
      float getx2(void);
      float gety2(void);

      void draw();

   private:

      float x1,y1,x2,y2;
      DRAWINGS drawings;
};
#endif
