#ifndef SYMBOL_H
#define SYMBOL_H
#include "object.h"
#include <string>
#include <unordered_map>

namespace idifiles{

  class Symbol : public Object{
    const std::string name;
    static std::unordered_map<std::string, Symbol* const> symboltable;

    Symbol(std::string name, bool intern=true);
  public:
    static Symbol* const intern(std::string name);
    static Symbol* const makeUninternedSymbol(std::string name);
    virtual ~Symbol();
  };

}

#endif
