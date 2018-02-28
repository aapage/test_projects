#include <iostream>
#include <type_traits>

template <typename T1, typename T2>
bool isDerived()
{
  bool result;
  result = std::is_base_of<T1, T2>::value;
  return result;
}

class A {};
class B : A {};


int main()
{
  
  std::cout << isDerived< A , B >() << std::endl;
  std::cout << isDerived< int , A >() << std::endl;
  std::cout << isDerived< B , A >() << std::endl;


  return 0;
}
