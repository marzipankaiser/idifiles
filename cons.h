#ifndef CONS_H
#define CONS_H
#include "object.h"

namespace idifiles{

  class Cons : public object{
  public:
    Object *car, *cdr;

    Cons(Object* car, Object* cdr);

    template<typename T, typename ...ARGS> 
    static Cons* list(T arg1, ARGS... args);
    template<typename ...ARGS> 
    static Cons* list<Object*,ARGS...>(Object* arg1, ARGS... args);
    static Cons* list();
  protected:
    virtual void markChildren(int flags, boll unmark=false);
  };
  
}

#endif
