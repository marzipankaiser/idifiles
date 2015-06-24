#ifndef IDIFILES_BASIC_H
#define IDIFILES_BASIC_H
#include "module.h"

namespace idifiles{

  class basic : public module{
  private:
    static basic* singleton =0;

  protected:
    basic();
    
  public:
    static getSingleton();
  }
  
}

#endif