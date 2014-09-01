#include "line.h"
#include "drawings.h"

LINE::LINE(
        float x1_in,
        float y1_in,
        float x2_in,
        float y2_in){

   x1 = x1_in;
   y1 = y1_in;
   x2 = x2_in;
   y2 = y2_in;

}

LINE::~LINE() {}

void LINE::draw() {

   drawings.draw_line(x1,y1,x2,y2);

}
