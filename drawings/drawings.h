#ifndef DRAWINGS_H
#define DRAWINGS_H

class DRAWINGS {

   public:

      DRAWINGS();
      ~DRAWINGS();

      void draw_circle (
           float diameter,
           float x, /* range -1 to 1 */
           float y, /* range -1 to 1 */
           int  N = 40, /* points */
           char red = 255,
           char green = 255,
           char blue = 255);

      void draw_line (
           float x1,
           float y1,
           float x2,
           float y2,
           char red = 255,
           char green = 255,
           char blue = 255);

   private:

      float scale;
};
#endif
