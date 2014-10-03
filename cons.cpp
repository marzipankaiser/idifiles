#include "cons.h"

idifiles::Cons* idifiles::Cons::list(){ return 0; }
template<typename T, typename... ARGS>
idifiles::Cons* idifiles::Cons::list(T arg1, ARGS... args){
  return new Cons(new Object(arg1), list(args...));
}
template<typename ...ARGS> 
idifiles::Cons* idifiles::Cons::list<Object*,ARGS...>
(Object* arg1, ARGS... args){
  return new Cons(arg1, list(args...));
}

