//Project 1, make a 2-player game where player 1 picks a number 
//from 1-100 and player two tries to guess it.

#include <iostream>
using namespace std;

//define constants for range of allowed values
const int minValue = 1;
const int maxValue = 100;

//functions
int getIntInRange(int minValue, int maxValue)
{
  int pValue;
  while(true)
    {
      cout << "Enter a number from 1 to 100 (inclusive): " << endl;
      cin >> pValue;
  
      if(pValue <= maxValue && pValue >= minValue)
	{  
	  break;
	}
      else
	{
	  cout << "ERROR: Value is not within the valid range. Try again" << endl;
	}
    }
  return pValue;
}

int getSecretNumber(int minValue, int maxValue)
{
  int secretNum;
  secretNum = getIntInRange(minValue, maxValue);
  for (int i = 0; i < 30; i++)
    {
      cout << "Clearing screen!" << endl;
    }
  return secretNum;
}

bool getGuessAndCheck(int minValue, int maxValue, int secretNum)
{
  int guessNum;
  guessNum = getIntInRange(minValue, maxValue);
  bool guessCheck = false;

  if (guessNum == secretNum)
    {
      cout << "Congratulations! You guessed it!" << endl;
      guessCheck = true;
    }
  else if (guessNum < secretNum)
    {
      cout << "The secret number is HIGHER than your guess" << endl;
      guessCheck = false;
    }
  else if (guessNum > secretNum)
    {
      cout << "The secret number is LOWER than your guess" << endl;
      guessCheck =  false;
    }
  return guessCheck;
}

int main()
{
  cout << "Player 1: You will enter a secret number for the other player to try to guess" << endl;
  int secretNum;
  secretNum = getSecretNumber(minValue, maxValue);
  
  cout << "Player 2: You will try to guess the secret number" << endl;

  bool player2Success = false;
  int i = 0;
  while (!player2Success)
    {
      player2Success = getGuessAndCheck(minValue, maxValue, secretNum);
      i++;
    }
  cout << "It took you " << i << " guesses to guess it!" << endl;
  return (0);
}
