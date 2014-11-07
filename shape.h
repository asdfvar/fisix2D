#ifndef SHAPE_H
#define SHAPE_H

#include "drawings.h"

class SHAPE {

  public:

     SHAPE();

  protected:

     float mass;
     float force_x, force_y;
     float x[3],y[3]; // position, velocity, acceleration, more?
     float w[3];      // rotation, angular rate, angular acceleration, more?
};

/**********
 * CIRCLE *
 **********/

class CIRCLE: public SHAPE {

  public:

     CIRCLE();
     CIRCLE(float x_in, float y_in);
     CIRCLE(float x_in, float y_in, float diameter_in);
     CIRCLE(float x_in, float y_in, float diameter_in, float elasticity_in);

    /********************************************************
     * Update the circle "ball" parameters based on a delta *
     * time and external forces                             *
     ********************************************************/

     void reset_force(void);
     void apply_force(float Fx, float Fy);
     void update(float dt);

     float getx0(void);
     float gety0(void);
     float getDiameter(void);
     float getMass(void);
     float getElasticity(void);
     float getVelx(void);
     float getVely(void);

     void setPosx(float);
     void setPosy(float);
     void setVelx(float);
     void setVely(float);

     void draw(void);

  private:

     DRAWINGS drawings;
     float diameter;
     float elasticity;

};
#endif
