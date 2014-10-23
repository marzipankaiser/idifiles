#include "symbol.h"

idifiles::Symbol::Symbol(std::string name, bool intern){
  this->name=name;
  if(intern)
    symboltable.insert(std::make_pair<std::string, Symbol* const>
		       (name,this));
}

idifiles::Symbol* const idifiles::Symbol::intern(std::string name){
  if(symboltable.find(name)!=symboltable.end())
    return symboltable[name];
  else{
    return new Symbol(name);
  }
}

idifiles::Symbol* const idifiles::Symbol::makeUninternedSymbol
(std::string name){
  return 
}

idifiles::Symbol::~Symbol(){}
