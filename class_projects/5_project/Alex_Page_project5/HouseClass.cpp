

#include <string>
#include <iostream>
using namespace std;

#include "PixelLocationClass.h"
#include "ColorClass.h"
#include "HouseClass.h"
#include "RectangularEntityClass.h"

//Programmer: Alex Page
//HouseClass are house objects that contain all information necessary to draw
//them on the map

HouseClass::HouseClass(PixelLocationClass inPixel,
		       int inDollarValue,
		       ColorClass inColor):RectangularEntityClass(
								  inPixel,
								  inColor)
{
  //set dollar value and numRows,numCols
  if (inDollarValue < 0)
    {
      cout << "HouseClass Error:" <<
        "Value of house cannot be less than 0" << endl;
      cout << "taking absolute value" << endl;

      dollarValue = -inDollarValue;
    }

  else { dollarValue = inDollarValue; }
  
  //rounded down to int, starts with min of 1 pixel
  numRows = numCols = 1 + dollarValue/DOLLARS_PER_PIXEL;   
}

string HouseClass::toString() const
{
  ostringstream oss;
  oss.clear();
  oss.str("");

  //print to screen all important info
  oss << HOUSE_TYPE << " Value: " << dollarValue << " " <<
    MapEntityClass::toString();

  return (oss.str());
}

string HouseClass::getType() const
{
  return HOUSE_TYPE;
}

int HouseClass::getNumRows() const
{
  return numRows;
}

int HouseClass::getNumCols() const
{
  return numCols;
}
