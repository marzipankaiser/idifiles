#include "cppobject.h"

template<typename T>
idifiles::CppObject<T>::CppObject(T value){
  this->value=value;
}

template<typename T>
idifiles::CppObject<T>::~CppObject(){}

template<typename T>
idifiles::CppObject<T>::get(){ return value; }

template<typename T>
idifiles::CppObject<T>::get(CppObject<T>* obj){
  return obj->value;
}
