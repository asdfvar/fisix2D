#ifndef SHAPE_H
#define SHAPE_H

class SHAPE {

  public:

     SHAPE();

  protected:

     float x[3],y[3]; // position, velocity, acceleration, more?
     float w[3]; // rotation, angular rate, angular acceleration, more?
};

class CIRCLE: public SHAPE {

  public:

     CIRCLE();

};
#endif
