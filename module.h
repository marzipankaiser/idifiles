#ifndef IDIFILES_MODULE_H
#define IDIFILES_MODULE_H

#include <functional>

#include "symbol.h"
#include "string.h"

namespace idifiles{

  class module{

    struct symbol_info{
      bool exported;
    };

    std::unordered_map<String, symbol> symboltable;
    std::unordered_map<symbol*, symbol_info> symbol_infos;

  public:
    void import(symbol* s);
    void import(module& m);

    bool symbol_exported(symbol* s);

    void map_symbols(std::function<void(symbol*)> fn);

    symbol* intern(String name);
    
  };
  
}

#endif
