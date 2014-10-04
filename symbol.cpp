#include "symbol.h"

idifiles::Symbol::Symbol(std::string name){
  this->name=name;
  symboltable.insert(std::make_pair<std::string, Symbol* const>
		     (name,this));
}

Symbol* const idifiles::Symbol::intern(std::string name){
  if(symboltable.find(name)!=symboltable.end())
    return symboltable[name];
  else{
    return new Symbol(name);
  }
}

idifiles::Symbol::~Symbol(){}
