#ifndef SHAPE_H
#define SHAPE_H

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

    /********************************************************
     * Update the circle "ball" parameters based on a delta *
     * time and external forces                             *
     ********************************************************/

     void update(float dt, float forcex, float forcey);

    /******************************************************
     * Conversion from an acceleration magnitude to an    *
     * equivalent force for this object.                  *
     *              F                                     *
     *         a = ---                                    *
     *              m                                     *
     ******************************************************/

     float acceleration_to_force(float a);

     void draw(void);

};
#endif
