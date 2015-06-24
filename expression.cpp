#include "expression.h"

using namespace idifiles;

void Expression::map_ptrs(std::function<void(object*)> fn){
  fn(op);
  for(auto it=args.begin();it!=args.end();++it){
    fn(it->first);
    fn(it->second);
  }
}

object* Expression::funcall(std::vector<object*> arg){
  //TODO
}
