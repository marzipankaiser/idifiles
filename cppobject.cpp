#include "cppobject.h"

using namespace idifiles;
using namespace std;

template<typename T>
type_index cpp_object<T>::type(){
  return typeid(T);
}
template<typename T>
void* cpp_object<T>::raw_data(){
  return data;
}
