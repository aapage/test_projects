

#include <iostream>
using namespace std;
int main()
{
  cout << endl;
  cout << "###############################" << endl;
  cout << "######Hello Midhathaway########" << endl;
  cout << "###############################" << endl;
  cout << endl;

  for (int middy =3; middy < 10; middy++)
    {
      cout << "middy has this many gentlmen suiters: " << middy <<endl;
      //middy++
      if (middy == 8) break;
    }
  
  cout << endl << "middy what number would you like to compute the factorial of?" << endl;


  void compute_factorial(int &number_in);
  void array_tester(int array1[], const int array2[]);
  // factorial calculations
  int factorial_number;
  cin >> factorial_number;
  compute_factorial(factorial_number);
  cout << endl << "Result: " << factorial_number << endl;


  //////////////////////////////
  // Array tester start//
  int array1[4] = {1,2,3,4};
  int array2[4] = {2,3,4,5};
  array_tester(array1, array2);
  cout << array1[0];
    
  return 0;
}


// function to compute the factorial of a number
void compute_factorial(int &number_in)
{
  int factorial_result = number_in;
 
  for(int i = 1; i < number_in; i++)
    {
      factorial_result *= i;
    }
  number_in = factorial_result;
  return;
}

//Function to test arrays

void array_tester(int array1[], const int array2[])
{
  array1[0]= 111;
  //array2[0]= 222;
}
