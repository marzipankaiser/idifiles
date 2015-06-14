#include "object.h"

using namespace idifiles;
using namespace std;

const uint_fast8_t GC_MARK_DO_NOT_TOUCH=3;
std::unordered_map
<std::type_index,
 std::unordered_map
 <std::type_index,
  std::function<object*(object*)> > > object::conversion_fns;
object* object::some_object = 0;

void object::def_conversion(type_index from, type_index to,
			    function<object*(object*)> fn){
  conversion_fns[from][to] = fn;
  for(auto&& to2 : conversion_fns[to]){
    if(!conversion_fns[from].count(to2))
      conversion_fns[from][to2] = [&fn,&to2](object* o){
	return fn(o)->convert_to(to2);
      }
  }
  for(auto& from_map : conversion_fns){
    if(from_map.count(from) && !from_map.count(to)){
      from_map[to] = [&fn,&from](object* o){
	return fn(o->convert_to(from));
      }
    }
  }
}
template<typename T> T object::as(){
  return dynamic_cast<T>(convert_to(typeid(T))->raw_data());
}

object* object::convert_to(std::type_index to){
  return conversion_fns[type()][to](this);
}

object* object::funcall(std::vector<object*> arg){
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
void object::run_gc(){
  static uint_fast8_t new_mark=2;
  new_mark = (last_mark==2)?1:2;

  // mark reachable
  auto mark_fn = [&mark_fn](object* o){
    if(o->mark==new_mark) return;
    if(o->mark!=GC_MARK_DO_NOT_TOUCH)
      o->mark=new_mark;
    o->map_ptrs(mark_fn);
  }
  for(auto root_ptr : root_ptrs)
    mark_fn(root_ptr);

  // walk memory, delete unreachable
  object* root_ptr = *(root_ptrs.begin()); // use first root ptr
  object* current_ptr = root_ptr;
  do{
    if(current_ptr->mark!=new_mark
       && current_ptr->mark!=GC_MARK_DO_NOT_TOUCH){
      object* to_delete = current_ptr;
      current_ptr = to_delete->next_in_memory;
      delete to_delete;
    }else{
      current_ptr = current_ptr->next_in_memory;
    }
  }while(current_ptr!=root_ptr);
  
  some_object = current_ptr;
  
}
void object::mark_lock(){
  root_ptrs.insert(this);
  mark=GC_MARK_DO_NOT_TOUCH;
}
void object::mark_free(){
  mark=0;
  root_ptrs.erase(this);
}

object::~object(){
  //update memory pointers
  prev_in_memory->next_in_memory = next_in_memory;
  next_in_memory->prev_in_memory = prev_in_memory;
}
