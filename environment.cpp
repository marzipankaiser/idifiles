#include "environment.h"

using namespace idifiles;
using namespace std;

bool environment::is_bound(symbol* s){
  if(local_bindings.count(s)>0) return true;
  else if(parent) return parent->is_bound();
  else return false;
}
object* environment::get(symbol* s){
  auto it = local_bindings.find(s);
  if(it!=local_bindings.end())
    return it->second;
  else if(parent) return parent->get(s);
  else return s->global_value;
}
void environment::set(symbol* s, object* v){
  auto it = local_bindings.find(s);
  if(it!=local_bindings.end())
    it->second = v;
  else if(parent) parent->set(s, v);
  else s->global_value = v;
}
void environment::bind(symbol* s, object* v){
  local_bindings[s] = v;
}


void environment::map_ptrs(std::function<void(object*)> fn){
  fn(parent);
  for(auto it=local_bindings.begin();it!=local_bindings.end();++it)
    fn(it->second);
}
void* environment::raw_data(){ return this; }
std::type_index environment::type(){ return typeid(environment); }
