#ifndef IDIFILES_SYMBOL_H
#define IDIFILES_SYMBOL_H

namespace idifiles
{

  struct symbol
  {
    String name;
    module* module;

    symbol(String name, module* module);
  };
  
}

#endif
