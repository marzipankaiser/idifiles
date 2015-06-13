#include "symbol.h"

symbol::symbol(String name, module* module)
  : name(name), module(module), global_value(0)
{}

void symbol::map_ptrs(std::function<void(object*)> fn){
  //fn(name); ?
  fn(module);
  fn(global_value);
}

void* symbol::raw_data(){ return this; }
voif std::type_index type(){ return typeid(symbol); }
