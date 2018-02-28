
#include <iostream>
#include <string>

int main()
{
  char input[80];
  std::cin >> input; 
  int length = 0;
  for (int i = 0; input[i] != '\0'; i++)
  {
    length ++;
  }

  for (int i = 0; i < length +1 ; i++)
  {
    //std::cout << input[i] << std::endl;
    char temp = input[i];
    input[i] = input[length];
    input[length] = temp;
    std::cout << input[i] << std::endl;
  }
  
  
  std::cout << input << std::endl;

  return 0;
}
