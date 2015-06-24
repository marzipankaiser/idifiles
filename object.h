#ifndef IDIFILES_OBJECT_H
#define IDIFILES_OBJECT_H

#include <unordered_map>
#include <unordered_set>
#include <typeindex>
#include <functional>
#include <initializer_list>
#include <vector>

class context;

namespace idifiles{

  const uint_fast8_t GC_MARK_DO_NOT_TOUCH;

  class object{

    static
    std::unordered_map
    <std::type_index,
     std::unordered_map
     <std::type_index,
      std::function<object*(object*)> > > conversion_fns;
    static object* some_object;
    static std::unordered_set<object*> root_ptrs;
    
    uint_fast8_t mark;
    object *next_in_memory, *prev_in_memory;
  protected:
    virtual void* raw_data();

    // map over child ptrs.
    virtual void map_ptrs(std::function<void(object*)> fn)=0;
    
  public:
    object();
    static void def_conversion(std::type_index from,
			       std::type_index to,
			       std::function<object*(object*)> fn);
    static void run_gc();
    void mark_lock();
    void mark_free();

    
    object* convert_to(std::type_index type);
    
    virtual std::type_index type();
    
    template<typename T> T as();

    virtual object* funcall(std::map<symbol*, object*> arg);
    virtual object* eval(context* c);

    virtual ~object();
  };

  
}

#endif
