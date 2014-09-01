#include "tools.h"
#include <cmath>

#define ABS(A) ((A) > 0.0) ? (A) : -(A)

static float distance2Line(
                   float x1, /* line start x */
                   float y1, /* line start y */
                   float x2, /* line end x   */
                   float y2, /* line end y   */
                   float x0, /* point x      */
                   float y0) /* point y      */
{

  float Dp1, Dp2, Dp1p2;
  float num, den;

  Dp1p2 = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
  Dp1   = (x0-x1)*(x0-x1) + (y0-y1)*(y0-y1);
  Dp2   = (x0-x2)*(x0-x2) + (y0-y2)*(y0-y2);

  if (Dp1 + Dp1p2 < Dp2)
     return sqrtf(Dp1);
  else if (Dp2 + Dp1p2 < Dp1)
     return sqrtf(Dp2);
  else {
     num = (y2-y1)*x0 - (x2-x1)*y0 - x1*y2 + x2*y1;
     num = ABS(num);
     den = sqrtf((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
     return num / den;
  }
}
