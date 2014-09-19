#include "object.h"

idifiles::Object* const idifiles::Object::evaluate
(idifiles::Environment* env){
  return this;
}

template<typename... ARG>
idifiles::Object* const idifiles::Object::call
(idifiles::Environment* env, ARG... args){
  //TODO
}

idifiles::Object* const idifiles::Object::call
(idifiles::Environment* env, Object* args){
  throw NotFuncallableException(this);
}
