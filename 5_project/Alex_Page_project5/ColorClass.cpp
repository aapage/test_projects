#include "ColorClass.h"

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

bool ColorClass::writeToFile(
     ofstream &outFile
     ) const
{
  bool success;

  success = true;
  
  outFile << red << " " << green << " " << blue;

  if (!outFile)
  {
    success = false;
  }

  return (success);
}

bool ColorClass::readFromFile(
     ifstream &inFile
     )
{
  bool success;
  int r;
  int g;
  int b;

  success = true;

  inFile >> r >> g >> b;

  if (!(inFile && setColor(r, g, b)))
  {
    cout << "Error: Reading color from file" << endl;
    success = false;
  }
  
  return (success);
}

bool ColorClass::setColor(
     int inR,
     int inG,
     int inB
     )
{
  bool success;

  success = true; 

  if (inR < 0 || inR > MAX_COLOR ||
      inG < 0 || inG > MAX_COLOR ||
      inB < 0 || inB > MAX_COLOR)
  {
    cout << "Error: Unable to set color with invalid values" << endl;
    success = false;
  }
  else
  {
    red = inR;
    green = inG;
    blue = inB;
  }

  return (success);
}

void ColorClass::setRed(
     )
{
  red = MAX_COLOR;
  green = 0;
  blue = 0;
}

void ColorClass::setGreen(
     )
{
  red = 0;
  green = MAX_COLOR;
  blue = 0;
}

void ColorClass::setBlue(
     )
{
  red = 0;
  green = 0;
  blue = MAX_COLOR;
}

void ColorClass::setBlack(
     )
{
  red = 0;
  green = 0;
  blue = 0;
}

void ColorClass::setWhite(
     )
{
  red = MAX_COLOR;
  green = MAX_COLOR;
  blue = MAX_COLOR;
}

bool ColorClass::isSameColor(
     const ColorClass &inColor
     ) const
{
  bool isSame;

  isSame = (red == inColor.red &&
            green == inColor.green && 
            blue == inColor.blue);

  return (isSame);
}

string ColorClass::toString(
     ) const
{
  ostringstream oss;
  oss.clear();
  oss.str("");

  oss << "(" << red << "," << green << "," << blue << ")";

  return (oss.str());
}
