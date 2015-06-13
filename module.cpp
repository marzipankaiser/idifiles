#include "module.h"

using namespace idifiles;
using namespace std;

void module::import(symbol* s){
  symboltable[s->name()] = s;
}
void module::import(module& m){
  m.map_symbols([this, &m](symbol* s){
      if(m.symbol_exported(s))
	import(s);
    });
}
bool module::symbol_exported(symbol* s){
  return symbol_infos[s].exported;
}
void module::map_symbols(std::function<void(symbol*)> fn){
  for(auto it = symboltable.begin(); it!=symboltable.end(); ++it)
    fn(it->second);
}
symbol* module::intern(String name){
  auto it = symboltable.find(name);
  if(it!=symboltable.end())
    return it->second;
  else{
    symboltable[name] = new symbol(name, this);
    return symboltable[name];
  }
}

void module::map_ptrs(std::function<void(object*)> fn){
  map_symbols(fn);
}
void* module::raw_data(){ return this; }
std::type_index type(){ return typeid(module); }
