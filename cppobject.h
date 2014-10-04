#ifndef CPPOBJECT_H
#define CPPOBJECT_H
#include "object.h"

namespace idifiles{

  template<typename T>
  class CppObject : public Object{
    T value;
  public:
    CppObject(T value);
    virtual ~CppObject();

    T get();
    static T get(CppObject<T>* obj);
  };

}

#endif
