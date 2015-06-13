#ifndef IDIFILES_ENVIRONMENT_H
#define IDIFILES_ENVIRONMENT_H

#include <map>
#include <typeindex>
#include <functional>
#include "symbol.h"
#include "object.h"

namespace idifiles{

  class environment : public object{

    environment* parent;
    std::map<symbol*, object*> local_bindings;

  public:
    bool is_bound(symbol* s);
    object* get(symbol* s);
    void set(symbol* s, object* v);
    void bind(symbol* s, object* v);
    
  protected:
    virtual void map_ptrs(std::function<void(object*)> fn);
  public:
    virtual void* raw_data();
    virtual std::type_index type();

  };
  
}

#endif
