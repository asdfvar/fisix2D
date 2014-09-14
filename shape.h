#ifndef SHAPE_H
#define SHAPE_H

#include "drawings.h"

class SHAPE {

  public:

     SHAPE();

  protected:

     float mass;
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

     void update_force(float dt, float forcex, float forcey);
     void update_acceleration(float ax, float ay);
     void update(float dt);

     float getx0(void);
     float gety0(void);
     float getDiameter(void);
     float getElasticity(void);
     float getVelx(void);
     float getVely(void);
     bool getColliding(void);

     void setVelx(float);
     void setVely(float);
     void setColliding(bool);

     void draw(void);

  private:

     DRAWINGS drawings;
     float diameter;
     float elasticity;
     bool colliding;

};
#endif
