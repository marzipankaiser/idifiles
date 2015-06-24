#ifndef IDIFILES_OPERATOR_H
#define IDIFILES_OPERATOR_H
#include "object.h"

namespace idifiles{

  class Operator : public object{
  protected:
    void map_ptrs(std::function<void(object*)> fn);
  public:
    virtual object* funcall(std::map<symbol*, object*> arg)=0;
  };
  
}

#endif
