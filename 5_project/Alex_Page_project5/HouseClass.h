#ifndef _HOUSECLASS_H_
#define _HOUSECLASS_H_

#include <string>
#include <iostream>
using namespace std;

#include "RectangularEntityClass.h"
#include "PixelLocationClass.h"
#include "ColorClass.h"

//Programmer: Alex Page
//HouseClass are house objects that contain all information necessary to draw
//them on the map

//constants for houses
const ColorClass HOUSE_COLOR = ColorClass(255,0,0); //red
const int DOLLARS_PER_PIXEL = 15000;
const string HOUSE_TYPE = "House";

class HouseClass: public RectangularEntityClass
{
 private:
  int dollarValue;
  int numRows;
  int numCols;

 public:
  //makes a house with pixel location and dollar value set
 
  HouseClass(PixelLocationClass inPixel,
	     int inDollarValue,
	     ColorClass inColor = HOUSE_COLOR);

  //toString prints out relavent info
  string toString() const;
  
  //getType returns a string of the object type "House"
  string getType() const;
  
  //get Number of rows
  int getNumRows() const;

  //get Num of cols
  int getNumCols() const;

};


#endif
