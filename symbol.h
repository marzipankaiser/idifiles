#ifndef IDIFILES_SYMBOL_H
#define IDIFILES_SYMBOL_H

#include <functional>
#include <typeindex>
#include "string.h"
#include "object.h"
class module;

namespace idifiles
{

  struct symbol : public object{
    String name;
    module* module;

    object* global_value;

    symbol(String name, module* module);

  protected:
    virtual void map_ptrs(std::function<void(object*)> fn);
  public:
    virtual void* raw_data();
    virtual std::type_index type();

  };
  
}

#endif
