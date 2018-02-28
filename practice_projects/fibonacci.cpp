#include <iostream>

using namespace std;
int main()
{
  int currentNumber = 1;
  int previousNumber = 1;

  int n;
  cout << "enter n: " << endl;
  cin >> n;

  for (int i = 0; i < n; i++)
    {
      cout << currentNumber << endl;
      int tempCurrent = currentNumber; 
      currentNumber += previousNumber;
      previousNumber = tempCurrent;
    }
  return 0;
}
