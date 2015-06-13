#include "object.h"

using namespace idifiles;
using namespace std;

std::unordered_map
<std::type_index,
 std::unordered_map
 <std::type_index,
  std::function<object*(object*)> > > object::conversion_fns;
object* object::some_object = 0;

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

object* object::funcall(object* arg){
  //TODO: throw exception
}

object::object(){
  mark=0;
  if(some_object){
    prev_in_memory = some_object;
    next_in_memory = some_object->next_in_memory;
    some_object->next_in_memory = this;
  }else{
    next_in_memory = this;
    prev_in_memory = this;
    some_object = this;
  }
}


// simple stop-the-world, mark-and-sweep gc
void object::run_gc(object* root_ptr){
  static uint_fast8_t new_mark=2;
  new_mark = (last_mark==2)?1:2;

  // mark reachable
  auto mark_fn = [&mark_fn](object* o){
    if(o->mark==new_mark) return;
    o->mark=new_mark;
    o->map_ptrs(mark_fn);
  }
  mark_fn(root_ptr);

  // walk memory, delete unreachable
  object* current_ptr = root_ptr;
  do{
    if(current_ptr->mark!=new_mark){
      current_ptr->prev_in_memory->next_in_memory
	= current_ptr->next_in_memory;
      current_ptr->next_in_memory->prev_in_memory
	= current_ptr->prev_in_memory;
      object* to_delete = current_ptr;
      current_ptr = to_delete->next_in_memory;
      to_delete->next_in_memory = 0;
      to_delete->prev_in_memory = 0;
      delete to_delete;
    }else{
      current_ptr = current_ptr->next_in_memory;
    }
  }while(current_ptr!=root_ptr);
  
  some_object = current_ptr;
  
}
