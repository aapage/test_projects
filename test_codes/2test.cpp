

#include <iostream>
using namespace std;

class middy
{
public:
  string hair;
  string mood;
  int location;
  
  int speak(string topic)
  {
    if (mood == 'happy') {cout << "I love you" << endl;}
    else if (mood == 'sad') {cout << "I hate you" << endl;}
  }
};

int main()
{
  #int matrix1[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
  #matrix1[0][0]=3;
  #cout << matrix1[0][0] << endl;
  
  middy midHat;

  midHat.mood = "happy";
  midHat.speak("topic");

  return (0);
}
