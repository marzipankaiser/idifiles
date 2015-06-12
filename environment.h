#ifndef IDIFILES_ENVIRONMENT_H
#define IDIFILES_ENVIRONMENT_H

#include <map>
#include "symbol.h"
#include "object.h"

namespace idifiles{

  class environment{

    environment* parent;
    std::map<symbol*, object*> local_bindings;

  public:
    bool is_bound(symbol* s);
    object* get(symbol* s);
    void set(symbol* s, object* v);
    void bind(symbol* s, object* v);
    
  };
  
}

#endif
