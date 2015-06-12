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

    uint_fast8_t mark;
  protected:
    virtual void* raw_data()=0;

    // map over child ptrs.
    virtual void map_ptrs(std::function<void(object*)> fn)=0;

    
  public:
    static void def_conversion(std::type_index from,
			       std::type_index to,
			       std::function<object*(object*)> fn);
    static void run_gc();
    object* convert_to(std::type_index type);
    
    virtual std::type_index type()=0;
    
    template<typename T> T as();
  };

  
}

#endif
