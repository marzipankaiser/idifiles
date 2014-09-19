#ifndef IDIFILES__OBJECT_H
#define IDIFILES__OBJECT_H

namespace idifiles{

  class Object{
  public:
    virtual Object* evaluate(Environment* env);
    template<typename... ARG>
    virtual Object* call(Environment* env, ARG... args);
    virtual Object* call(Environment* env, Object* args);
  };

}

#endif
