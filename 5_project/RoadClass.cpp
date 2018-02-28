#include "RoadClass.h"


#include <string>
#include <iostream>
using namespace std;

#include "RectangularEntityClass.h"
#include "PixelLocationClass.h"
#include "ColorClass.h"

//Programmer: Alex Page
//RoadClass are road objects that contain all information necessary to draw
//them on the map

RoadClass::RoadClass(PixelLocationClass inPixel,
		      int inLength,
		      int inNumLanes,
		      bool inIsVertical,
		     ColorClass inColor):RectangularEntityClass(inPixel,
								inColor)
{
  if (inLength < 0)
    {
      cout << "RoadClass Error:" <<
        "Length of road cannot be less than 0" << endl;
      cout << "taking absolute value" << endl;
      length = -inLength;
    }
  else { length = inLength; }
  
  if(inNumLanes == 0)
    {
      cout << "RoadClass Error:" <<
        "Number of lanes of road cannot be 0" << endl;
      cout << "Setting default numLanes = 1" << endl;
      numLanes = 1;
    }

  else if(inNumLanes < 0)
    {
      cout << "RoadClass Error:" <<
        "Number of lanes of road cannot be negative" << endl;
      cout << "taking absolute value" << endl;
      numLanes = -inNumLanes;

    }
  else { numLanes = inNumLanes; }
  
  isVertical = inIsVertical;
  
  //set number of rows and number of cols based on isVertical
  if (isVertical)
    {
      numRows = length;
      numCols = numLanes*PIXELS_PER_LANE;
    }
  else
    {
      numRows = numLanes*PIXELS_PER_LANE;
      numCols = length;
    }
}

string RoadClass::toString() const
{
  ostringstream oss;
  oss.clear();
  oss.str("");

  string verticalString;
  if (isVertical) {verticalString = "Vertical";}
  else {verticalString = "Horizontal";}

  //print to screen all important info
  oss << ROAD_TYPE << " Len: " << length << " Lanes: " << numLanes <<
    " Runs: " << verticalString << " " << MapEntityClass::toString();

  return (oss.str());
}

string RoadClass::getType() const
{
  return ROAD_TYPE;
}

int RoadClass::getNumRows() const
{
  return numRows;
}

int RoadClass::getNumCols() const
{
  return numCols;
}
