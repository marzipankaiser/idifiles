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


    static const int MARK_REFERENCED = 1<<0;
    static const int MARK_ALIEN_REFERENCED = 1<<1; // to indicate references from out of space
    static const int MARK_DELETION = 1<<2;

    /* Garbage collection */
    void mark(int flags, bool unmark=false);
  protected:
    virtual void markChildren(int flags, bool unmark=false);
    int markValue; 
    std::list<Object* const>::iterator& heapPosition;

    static std::list<Object* const> heapObjects;
  public:

  // delete if all mark bits aren't set or
  // any notmark bits are set
    static void deleteUnmarked(int mark, int notmark, float part=1.0);
  };

}

#endif
