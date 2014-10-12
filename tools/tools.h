#ifndef TOOLS_H
#define TOOLS_H

#include "line.h"
#include "shape.h"

 float distance2Line(
           float x1, /* line start x */
           float y1, /* line start y */
           float x2, /* line end x   */
           float y2, /* line end y   */
           float x0, /* point x      */
           float y0);/* point y      */

 void collideWithLine(
           CIRCLE*,
           LINE*);

void collideWithCircle(
           CIRCLE *circle1,
           CIRCLE *circle2);

#endif
