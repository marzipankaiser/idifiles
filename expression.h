#ifndef IDIFILES_EXPRESSION_H
#define IDIFILES_EXPRESSION_H
#include "object.h"

class Operator;
class symbol;

namespace idifiles{

  class Expression : public object{
  protected:
    void map_ptrs(std::function<void(object*)> fn);
  public:
    Operator* op;
    std::map<symbol*, object*> args;

    object* funcall(std::vector<object*> arg);
  };
  
}

#endif
