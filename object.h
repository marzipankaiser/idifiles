#ifndef IDIFILES__OBJECT_H
#define IDIFILES__OBJECT_H
#include <list>

namespace idifiles{

  class Object{
  public:
    virtual Object* const evaluate(Environment* env);
    template<typename... ARG>
    virtual Object* call(Environment* env, ARG... args);
    virtual Object* call(Environment* env, Object* args);

    Object();
    virtual ~Object();

    /* Garbage collection */
    void mark(int flags, bool unmark=false);
  protected:
    virtual void markChildren(int flags, bool unmark=false);
    int markValue; 
    std::list<Object* const>::iterator& heapPosition;

    static std::list<Object* const> heapObjects;
  public:

  // delete if all mark bits aren't set and
  // all notmark bits are set
    static void deleteUnmarked(int mark, int notmark, float part=1.0);
  };

}

#endif
