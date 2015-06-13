#ifndef IDIFILES_MODULE_H
#define IDIFILES_MODULE_H

#include <functional>

#include "symbol.h"
#include "string.h"

namespace idifiles{

  class module : public object{

    struct symbol_info{
      bool exported;
    };

    std::unordered_map<String, symbol*> symboltable;
    std::unordered_map<symbol*, symbol_info> symbol_infos;
  public:
    void import(symbol* s);
    void import(module& m);

    bool symbol_exported(symbol* s);

    void map_symbols(std::function<void(symbol*)> fn);

    symbol* intern(String name);

    
  protected:
    virtual void map_ptrs(std::function<void(object*)> fn);
  public:
    virtual void* raw_data();
    virtual std::type_index type();

  };
  
}

#endif
