class SHAPE {

   public:

      SHAPE *prev, *next;

      SHAPE();
      SHAPE(float x[]);
      SHAPE(float x[], float v[]);
      SHAPE(float x[], float v[], float a[]);
     ~SHAPE();

   protected:
       float x[3],y[3]; // position, velocity, acceleration, more?
       float w[3]; // rotation, angular rate, angular acceleration, more?
};

class CIRCLE: public SHAPE {

};
