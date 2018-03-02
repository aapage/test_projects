#ifndef _ROADCLASS_H_
#define _ROADCLASS_H_

#include <string>
#include <iostream>
using namespace std;

#include "RectangularEntityClass.h"
#include "PixelLocationClass.h"
#include "ColorClass.h"

//Programmer: Alex Page
//RoadClass are road objects that contain all information necessary to draw
//them on the map

//constants for roads
const ColorClass ROAD_COLOR = ColorClass(127,127,127); //grey
const int PIXELS_PER_LANE = 3;
const string ROAD_TYPE = "Road";

class RoadClass: public RectangularEntityClass
{
 private:
  int length;
  int numLanes;
  bool isVertical;

  int numRows;
  int numCols;

 public:
  //RoadClass ctor
  RoadClass(PixelLocationClass inPixel,
             int inLength,
	     int inNumLanes,
	     bool inIsVertical,
             ColorClass inColor = ROAD_COLOR);

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


