#ifndef _RECTANGULARENTITYCLASS_H_
#define _RECTANGULARENTITYCLASS_H_


//Programmer: Alex Page
//Date: April 2016
//Purpose: Inherits from MapEntityClass.
//This class will serve as a base class for
//three different rectangular objects: HouseClass, RoadClass, and SchoolClass
//-----------------------------------------------------------------------------

#include "MapClass.h"
#include "PixelLocationClass.h"
#include "ColorClass.h"
#include "MapEntityClass.h"
#include "MapExceptionClass.h"

class RectangularEntityClass: public MapEntityClass
{

 public:
  //default constructor must call MapEntityClass ctor 
  RectangularEntityClass(PixelLocationClass inPixel, ColorClass inColor);

  void drawOnMap(MapClass *mapObj) const;
  
  //returns string of representation of object
  virtual string toString() const = 0;

  //returns string of type of class
  virtual string getType() const = 0;

  //return int of number of rows
  virtual int getNumRows() const = 0;

  //return int of number of columns
  virtual int getNumCols() const = 0;
  
};


#endif
