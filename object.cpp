#include "object.h"
#include "cons.h"

idifiles::Object* const idifiles::Object::evaluate
(idifiles::Environment* env){
  return this;
}

template<typename... ARG>
idifiles::Object* const idifiles::Object::call
(idifiles::Environment* env, ARG... args){
  call(env, Cons::list(args...));
}

idifiles::Object* const idifiles::Object::call
(idifiles::Environment* env, Object* args){
  throw NotFuncallableException(this);
}

void idifiles::Object::mark(int flags){
  int oldMark=markValue;
  markValue|=flags;
  if(oldMark!=markValue) markChildren(flags);
}

void idifiles::Object::markChildren(int flags){}

idifiles::Object::Object(){
  heapObjects.push_front(this);
  heapPosition = heapObjects.front();
}

idifiles::Object::~Object(){
  heapObjects.erase(heapPosition);
}

void idifiles::Object::deleteUnmarked(int mark, float part){
  int part_n = int(heapObjects.size()*part);
  auto it = heapObjects.begin();
  for(int i=0; (i<part_n)&&(it!=heapObjects.end());i++){
    if(!(mark & (*it)->markValue)) delete *it;
  }
}
