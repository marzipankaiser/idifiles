#ifndef IDIFILES_OBJECT_H
#define IDIFILES_OBJECT_H

#include <unordered_map>
#include <typeindex>
#include <functional>

namespace idifiles{

  class object{

    static
    std::unordered_map
    <std::type_index,
     std::unordered_map
     <std::type_index,
      std::function<object*(object*)> > > conversion_fns;
    static object* some_object;

    uint_fast8_t mark;
    object *next_in_memory, *prev_in_memory;
  protected:
    virtual void* raw_data()=0;

    // map over child ptrs.
    virtual void map_ptrs(std::function<void(object*)> fn)=0;

    
  public:
    object();
    static void def_conversion(std::type_index from,
			       std::type_index to,
			       std::function<object*(object*)> fn);
    static void run_gc(object* root_ptr);
    object* convert_to(std::type_index type);
    
    virtual std::type_index type()=0;
    
    template<typename T> T as();

    virtual object* funcall(object* arg);
  };

  
}

#endif
