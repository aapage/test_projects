#include <string>
#include <iostream>
using namespace std;

//declare clases
class middy
{
private:
  int numberOfMiddy;
public:
  string mood;
  int middysNumber(int numberIn);
  void expressMood();
};


//main
int main()
{
  middy midHat;
  midHat.middysNumber(5);

  string mood;
  cout << "\n What is Midhat's mood\n";
  cin >> mood;
  midHat.mood = mood;
  midHat.expressMood();
  return 0;
}

//define classes
//class middy
//{
//private:
// int numberOfMiddy;  
//public:
//  string mood;
//  int middysNumber(int numberIn);
//  void expressMood();
//};

//define member funcitons
int middy::middysNumber(int numberIn)
  {
    numberOfMiddy = numberIn;
    cout << numberOfMiddy << endl;
    return 0;
  }
void middy::expressMood()
  {
    if (mood == "happy") {cout << "\nI LOVE YOU\n";}
    else if (mood == "sad"){cout << "\nYou suck, and your whole family sucks.\n";} 
    else if (mood == "sad"){cout << "\nYou suck, and your whole family sucks.\n";}
    else if (mood == "tired"){cout << "\nStop talking, bring me wine.\n";}
  }


