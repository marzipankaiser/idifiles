#ifndef SYMBOL_H
#define SYMBOL_H
#include "object.h"
#include <string>
#include <unordered_map>

namespace idifiles{

  class Symbol : public Object{
    const std::string name;
    static std::unordered_map<std::string, Symbol* const> symboltable;

    Symbol(std::string name);
  public:
    static Symbol* const intern(std::string name);
    virtual ~Symbol();
  };

}

#endif
