#ifndef IDIFILES_SIMPLE_FUNCTION_H
#define IDIFILES_SIMPLE_FUNCTION_H
#include <vector>

#include "operator.h"

namespace idifiles{

  template<class R, class... Ts>
  class simple_function : public operator{
    std::function<R, Ts...> fn;
    std::vector<symbol*> arg_names;
  public:
    object* funcall(std::map<symbol*, object*> arg);
  };
  
}

#endif
