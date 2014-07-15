class NODE {

  public:

    NODE();

    void *obj;
    NODE *prev, *next;

};

class LIST {

  public:

    LIST();
   ~LIST();
    void append(void*);
    NODE *pop(void);
    void gotonext(void);
    void gotoprev(void);
    void *getobj(void);

  private:

    int N;
    NODE *at;

};
