#include "object.h"

using namespace idifiles;
using namespace std;

std::unordered_map
<std::type_index,
 std::unordered_map
 <std::type_index,
  std::function<object*(object*)> > > object::conversion_fns;

void object::def_conversion(type_index from, type_index to,
			    function<object*(object*)> fn){
  conversion_fns[from][to] = fn;
}
template<typename T> T object::as(){
  return dynamic_cast<T>(convert_to(typeid(T))->raw_data());
}

object* object::convert_to(std::type_index to){
  return conversion_fns[type()][to](this);
}


void object::run_gc(){

  ///TODO
  
}
