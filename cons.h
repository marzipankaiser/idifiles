#ifndef IDIFILES_CONS_H
#define IDIFILES_CONS_H

namespace idifiles{

  class cons : public object{

    object *car, *cdr;

  protected:
    virtual void* raw_data();

    // map over child ptrs.
    virtual void map_ptrs(std::function<void(object*)> fn);

  public:
    virtual std::type_index type();
  };

}

#endif
