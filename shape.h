class SHAPE {

  public:

     SHAPE();
     SHAPE go2Next();
     void append(SHAPE*);
     void remove(void);
     SHAPE *shift_left(void);
     SHAPE *prev, *next;

  protected:

     int Number_of_obj;
     float x[3],y[3]; // position, velocity, acceleration, more?
     float w[3]; // rotation, angular rate, angular acceleration, more?
};

class CIRCLE: public SHAPE {

  public:

     CIRCLE();

};
