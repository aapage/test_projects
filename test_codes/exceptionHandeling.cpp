#include <iostream>
#include <string>

class A
{
 private:
  int data;
 public:
  A(int dataIn):data(dataIn)
  {
    std::string a = "Error";
    throw a;
  }
};

int main(int argc, const char *argv[])
{
 try
   { 
 if (argc == 2)
  {
    std::cout << argv[1] << std::endl;
   
    throw 22;
 }
  try
    {
      A a(11);
    }
  catch (std::string e)
    {
      std::cout << e << std::endl;
    }
   }
  catch (...)
    {
      std::cout << "Detected unhandled exception" << std::endl;
    }
   
  return 0;
}


