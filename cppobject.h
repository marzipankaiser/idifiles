#ifndef IDIFILES_CPPOBJECT_H
#define IDIFILES_CPPOBJECT_H

#include "object.h"
#include <typeindex>
#include <functional>

namespace idifiles{

  template<typename T>
  class cpp_object : public object{

    T* data;
    
    virtual void* raw_data();
    virtual void map_ptrs(std::function<void(object*)> fn)=0;

  public:
    virtual std::type_index type();
  };
  
}

#endif
