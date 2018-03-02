#include "PixelLocationClass.h"

#include <iostream>
#include <sstream>
using namespace std;

void PixelLocationClass::getInfoFromUser(
     const string &label
     )
{
  bool validInput;

  validInput = false;
  do
  {
    cout << "Enter " << label << " row and column: ";
    cin >> row >> col;

    if (!cin)
    {
      cout << "Invalid data entered" << endl;
      cin.clear();
    }
    else
    {
      validInput = true;
    }

    cin.ignore(200, '\n');
  } while (!validInput);
}

void PixelLocationClass::assign(
     int inR,
     int inC
     )
{
  row = inR;
  col = inC;
}

int PixelLocationClass::getRow(
     ) const
{
  return (row);
}

int PixelLocationClass::getCol(
     ) const
{
  return (col);
}

string PixelLocationClass::toString(
     ) const
{
  ostringstream oss;

  oss.clear();
  oss.str("");
  oss << "[" << row << "," << col << "]";
  return (oss.str());
}
