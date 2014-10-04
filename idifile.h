#ifndef IDIFILE_H
#define IDIFILE_H
#include <string>

namespace idifiles{

  class IdiFile{
  public:
    static Object* evaluate(Object* obj, Environment* env);
    static Object* read(std::string str);
  };

}

#endif
