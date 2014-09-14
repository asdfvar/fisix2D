#include "line.h"
#include "drawings.h"

LINE::LINE(void){
   x1 = 0.0;
   y1 = 0.0;
   x2 = 0.0;
   y2 = 0.0;
}

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

float LINE::getx1(void) {
   return x1;
}

float LINE::gety1(void) {
   return y1;
}

float LINE::getx2(void) {
   return x2;
}

float LINE::gety2(void) {
   return y2;
}

void LINE::draw() {

   drawings.draw_line(x1,y1,x2,y2);

}
